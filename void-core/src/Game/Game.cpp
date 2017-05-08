//
// Created by Dmitry Mozgin on 25/04/2017.
//

#include <iostream>
#include <Common/GameContext.h>
#include <Common/Time.h>
#include "Game.h"
#include "Levels/Levels.h"
#include "Tags.h"

using namespace vd;

//region IGame

IGame::~IGame() {
}

//endregion

//region Game

Game::Game(
        const IObjectPoolRef& objectPool,
        const IPlayerRef& player,
        const IMusicSystemRef& musicSystem,
        const IInputSystemRef& inputSystem,
        const ISceneRef& scene,
        const IVoidScreenRef& tryAgainScreen,
        const IVoidScreenRef& introScreen,
        const IHelpScreenRef& movementHelpScreen
)
        : _skipIntro(false),
          _startLevel(0),
          _objectPool(objectPool),
          _player(player),
          _musicSystem(musicSystem),
          _inputSystem(inputSystem),
          _scene(scene),
          _tryAgainScreen(tryAgainScreen),
          _introScreen(introScreen),
          _movementHelpScreen(movementHelpScreen),
          _currentLevelIndex(0),
          _currentTrack(nullptr),
          _levels(CreateLevels(this))
{
    _inputSystem->OnAnyKey.connect(std::bind(&Game::OnAnyKey, this));
    _inputSystem->OnPlayerMove.connect(std::bind(&Game::OnPlayerMove, this, std::placeholders::_1));
    _inputSystem->OnQuit.connect(std::bind(&Game::OnQuit, this));
    _inputSystem->OnReset.connect(std::bind(&Game::OnReset, this));
}

IPlayerRef Game::GetPlayer() const {
    return _player;
}

IObjectPoolRef Game::GetObjectPool() const {
    return _objectPool;
}

IInputSystemRef Game::GetInputSystem() const {
    return _inputSystem;
}

IMusicSystemRef Game::GetMusicSystem() const {
    return _musicSystem;
}

IVoidScreenRef Game::GetTryAgainScreen() const {
    return _tryAgainScreen;
}

IVoidScreenRef Game::GetIntroScreen() const {
    return _introScreen;
}

IHelpScreenRef Game::GetMovementHelpScreen() const {
    return _movementHelpScreen;
}

ISceneRef Game::GetScene() const {
    return _scene;
}

float Game::TimeForNextLevel() const {
    return static_cast<float>(_musicSystem->TimeForNextLevel(_currentLevelIndex));
}

void Game::OnStart() {
    GameComponent::OnStart();

    _tryAgainScreen->SetText(TextPlaceId::Title, TextId::TryAgainTitle);
    _tryAgainScreen->SetText(TextPlaceId::Footer, TextId::TryAgainFooter);

    if (_startLevel!= 0) {
        _skipIntro = true;
    }

    _inputSystem->Enable(InputSystemEvent::Quit);

    if (_skipIntro) {
        _introScreen->Hide();
        StartGame(_startLevel);
    } else {
        _introScreen->Show();
        _inputSystem->Enable(InputSystemEvent::AnyKey);
    }
}

void Game::OnUpdate() {
    GameComponent::OnUpdate();

    for (auto& object : *GetCurrentLevel()->Objects()) {
        if (!object->IsEnabled()) continue;

        if (_player->IsAlive()) {
            if (object->GetTag() == Tags::Gate) {

                // Change background color.
                if (!_backgroundColorChanged &&
                        _player->IsCoverWholeScreen(object) &&
                        _player->CanCollide(object)) {
                    if (CanMoveToNextLevel()) {
                        _scene->SetBackgroundColor(GetNextLevel()->GetBackgroundColor());
                    } else {
                        // Last level gate's color or IntroScreen's background.
                        _scene->SetBackgroundColor(Colors::Black);
                    }

                    _backgroundColorChanged = true;
                }

                // Check if a player has entered a gate.
                if (_player->IsBehind(object)) {
                    if (_player->CanCollide(object)) {
                        if (CanMoveToNextLevel()) {
                            MoveToNextLevel();
                        } else {
                            EndGame(EndGameCause::FinishedGame);
                        }
                    } else {
                        EndGame(EndGameCause::MissedGate);
                    }
                    break;
                }
            }

            // Check if the player encounter a portal.
            if (object->GetTag() == Tags::Portal &&
                _player->CanCollide(object)) {
                EndGame(EndGameCause::CollidedWithPortal);
                break;
            }
        }

        // Disable objects left behind (optimization).
        if (_player->IsBehind(object)) {
            object->SetEnabled(false);
        }
    }

    GetCurrentLevel()->Update(this, Time::GetDeltaTime());
}

void Game::OnAnyKey() {
    if (_introScreen->IsVisible() || _tryAgainScreen->IsVisible()) {
        _inputSystem->Disable(InputSystemEvent::AnyKey);

        // Because of the hide animation.
        _scene->SetBackgroundColor(GetColorOfFirstLevel());

        if (_introScreen->IsVisible()) {
            _introScreen->HideWithAnimation(std::bind(&Game::OnReset, this));
        } else {
            _inputSystem->Enable(InputSystemEvent::PlayerMove);
            _inputSystem->Enable(InputSystemEvent::Reset);

            _tryAgainScreen->HideWithAnimation(std::bind(&Game::OnReset, this));
        }
    } else {
        throw new std::runtime_error("Invalid condition");
    }
}

void Game::OnPlayerMove(MoveDirection moveDirection) {
    VoidTrackRef nextTrack = nullptr;

    switch (moveDirection) {
        case MoveDirection::Left:
            nextTrack = _currentTrack->GetLeftTrack();
            break;
        case MoveDirection::Up:
            nextTrack = _currentTrack->GetTopTrack();
            break;
        case MoveDirection::Right:
            nextTrack = _currentTrack->GetRightTrack();
            break;
        case MoveDirection::Down:
            nextTrack = _currentTrack->GetBottomTrack();
            break;
        case MoveDirection::None:
            break;
    }

    if (nextTrack != nullptr) {
        _currentTrack = nextTrack;
        _player->MoveToTrack(_currentTrack);
    }
}

void Game::OnQuit() {
    GameContext::Quit();
}

void Game::OnReset() {
    StartGame(0);
}

void Game::StartGame(int levelIndex) {
    GetCurrentLevel()->DisableObjects();
    _currentLevelIndex = levelIndex;

    _musicSystem->Play(_currentLevelIndex, true);

    InitLevel();

    _player->SetAlive(true);
    _player->StartRunning();

    _inputSystem->Disable(InputSystemEvent::AnyKey);
    _inputSystem->Enable(InputSystemEvent::PlayerMove);
    _inputSystem->Enable(InputSystemEvent::Reset);
}

VoidLevelRef Game::GetCurrentLevel() {
    return _levels.at(_currentLevelIndex);
}

VoidLevelRef Game::GetNextLevel() {
    return _levels.at(_currentLevelIndex + 1);
}

Color Game::GetColorOfFirstLevel() {
    return _levels[0]->GetBackgroundColor();
}

void Game::InitLevel() {
    auto currentLevel = GetCurrentLevel();

    currentLevel->Prepare(this);

    _scene->SetBackgroundColor(currentLevel->GetBackgroundColor()) ;
    _currentTrack = currentLevel->StartTrack();
    _player->MoveToPosition(Vector3::Zero);
    _backgroundColorChanged = false;

    InitHelpScreen();
}

void Game::InitHelpScreen() {
    if (_currentLevelIndex == 3) {
        TextId message;

        if (GameContext::IsMobilePlatform()) {
            message = TextId::SwipeDownHelp;
        } else {
            message = TextId::MoveUpHelp;
        }

        _movementHelpScreen->SetText(TextPlaceId::Message, message);
        _movementHelpScreen->SetTextColor(TextPlaceId::Message, Colors::Black);
        _movementHelpScreen->ShowAndHide();
    } else if (_currentLevelIndex == 4) {
        TextId message;

        if (GameContext::IsMobilePlatform()) {
            message = TextId::SwipeLeftHelp;
        } else {
            message = TextId::MoveRightHelp;
        }

        _movementHelpScreen->SetText(TextPlaceId::Message, message);
        _movementHelpScreen->SetTextColor(TextPlaceId::Message, Colors::White);
        _movementHelpScreen->ShowAndHide();
    }
}

void Game::MoveToNextLevel() {
    MoveToLevel(_currentLevelIndex + 1);
}

void Game::MoveToLevel(int levelIndex) {
    if (_currentLevelIndex != levelIndex) {
        GetCurrentLevel()->Destroy(this);

        _currentLevelIndex = levelIndex;
    }

    InitLevel();
}

void Game::EndGame(Game::EndGameCause cause) {
    _player->SetAlive(false);
    _inputSystem->Disable(InputSystemEvent::PlayerMove);
    _inputSystem->Disable(InputSystemEvent::Reset);
    _musicSystem->Stop(true);

    switch (cause) {
        case EndGameCause::CollidedWithPortal:
        case EndGameCause::MissedGate:
            if (cause == EndGameCause::CollidedWithPortal) {
                _tryAgainScreen->SetText(TextPlaceId::Body, TextId::TryAgainCollidedWithPortal);
            } else if (cause == EndGameCause::MissedGate) {
                _tryAgainScreen->SetText(TextPlaceId::Body, TextId::TryAgainMissedGate);
            }
            _tryAgainScreen->ShowWithAnimation([this]() {
                    GetCurrentLevel()->DisableObjects();
                    _player->StopRunning();
                    _inputSystem->Enable(InputSystemEvent::AnyKey);
            });
            break;
        case EndGameCause::FinishedGame:
            MoveToLevel(0);
            GetCurrentLevel()->DisableObjects();
            _player->StopRunning();

            _introScreen->ShowWithAnimation([this]() {
                    _inputSystem->Enable(InputSystemEvent::AnyKey);
            });
            break;
        default:
            throw std::exception();
    }
}

bool Game::CanMoveToNextLevel() {
    return _currentLevelIndex + 1 < _levels.size();
}

std::vector<VoidLevelRef> Game::CreateLevels(const IGameRef& game) {
    std::vector<VoidLevelRef> levels = {
            std::make_shared<Level1>(),
            std::make_shared<Level2>(),
            std::make_shared<Level3>(),
            std::make_shared<Level4>(),
            std::make_shared<Level5>(),
            std::make_shared<Level6>(),
            std::make_shared<Level7>(),
            std::make_shared<Level8>(),
            std::make_shared<Level9>(),
            std::make_shared<Level10>(),
            std::make_shared<Level11>(),
            std::make_shared<Level12>(),
            std::make_shared<Level13>(),
            std::make_shared<Level14>(),
            std::make_shared<Level15>(),
            std::make_shared<Level16>(),
            std::make_shared<Level17>(),
            std::make_shared<Level18>(),
            std::make_shared<Level19>(),
            std::make_shared<Level20>(),
            std::make_shared<Level21>(),
            std::make_shared<Level22>(),
            std::make_shared<Level23>(),
            std::make_shared<Level24>(),
            std::make_shared<Level25>(),
            std::make_shared<Level26>(),
            std::make_shared<Level27>(),
            std::make_shared<Level28>(),
            std::make_shared<Level29>(),
            std::make_shared<Level30>(),
            std::make_shared<Level31>(),
            std::make_shared<Level32>(),
            std::make_shared<Level33>(),
            std::make_shared<Level34>(),
            std::make_shared<Level35>(),
            std::make_shared<Level36>(),
            std::make_shared<Level37>(),
            std::make_shared<Level38>(),
            std::make_shared<Level39>(),
            std::make_shared<Level40>(),
            std::make_shared<Level41>(),
            std::make_shared<Level42>(),
            std::make_shared<Level43>(),
            std::make_shared<Level44>()
    };

    for (auto& l: levels) {
        l->Create(game);
    }

    return levels;
}

//endregion
