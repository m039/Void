//
// Created by Dmitry Mozgin on 25/04/2017.
//

#include <iostream>
#include <Common/GameContext.h>
#include "Game.h"
#include "Levels/Level35.h"

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
        : _objectPool(objectPool),
          _player(player),
          _musicSystem(musicSystem),
          _inputSystem(inputSystem),
          _scene(scene),
          _tryAgainScreen(tryAgainScreen),
          _introScreen(introScreen),
          _movementHelpScreen(movementHelpScreen),
          _currentTrack(nullptr)
{
    _inputSystem->OnAnyKey.connect(std::bind(&Game::OnAnyKey, this));
    _inputSystem->OnPlayerMove.connect(std::bind(&Game::OnPlayerMove, this, std::placeholders::_1));
    _inputSystem->OnQuit.connect(std::bind(&Game::OnQuit, this));
    _inputSystem->OnReset.connect(std::bind(&Game::OnReset, this));
}

Game::~Game() {
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
    // Todo: implement.
    return 4.6f;
}

void Game::OnStart() {
    GameComponent::OnStart();

    _scene->SetBackgroundColor(Color::Black);

    _inputSystem->Enable(InputSystemEvent::Quit);

    _level = std::make_unique<Level1>();
    _level->Initialize(this);

    _currentTrack = _level->StartTrack();
    _player->MoveToPosition(Vector3::Zero);

    // Todo: remove.
    StartGame(0);
}

void Game::OnUpdate() {
    GameComponent::OnUpdate();

    // Todo: implement.
}

void Game::OnAnyKey() {
    // Todo: implement.
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
    // Todo: implement.
}

void Game::StartGame(int levelIndex) {
    // Todo: implement.

    _inputSystem->Disable(InputSystemEvent::AnyKey);
    _inputSystem->Enable(InputSystemEvent::PlayerMove);
    _inputSystem->Enable(InputSystemEvent::Reset);
}

//endregion
