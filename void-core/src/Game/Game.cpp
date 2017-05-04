//
// Created by Dmitry Mozgin on 25/04/2017.
//

#include <iostream>
#include <Common/GameContext.h>
#include "Game.h"
#include "Levels/Level35.h"

using namespace vd;

Game::Game(
        const IObjectPoolRef& objectPool,
        const IPlayerRef& player,
        const IMusicSystemRef& musicSystem,
        const IInputSystemRef& inputSystem,
        const ISceneRef& scene
)
        : _currentTrack(nullptr)
{
    _objectPool = objectPool;
    _player = player;
    _musicSystem = musicSystem;
    _inputSystem = inputSystem;

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
    return vd::IInputSystemRef();
}

IMusicSystemRef Game::GetMusicSystem() const {
    return _musicSystem;
}

IVoidScreenRef Game::GetTryAgainScreen() const {
    // Todo: implement.
    return vd::IVoidScreenRef();
}

IVoidScreenRef Game::GetIntroScreen() const {
    // Todo: implement.
    return vd::IVoidScreenRef();
}

IHelpScreenRef Game::GetMovementHelpScreen() const {
    // Todo: implement.
    return vd::IHelpScreenRef();
}

ISceneRef Game::GetScene() const {
    // Todo: implement.
    return vd::ISceneRef();
}

float Game::TimeForNextLevel() const {
    // Todo: implement.
    return 4.6f;
}

void Game::Start() {
    GameComponent::Start();

    _inputSystem->Enable(InputSystemEvent::Quit);

    _level = std::make_unique<Level35>();
    _level->Initialize(this);

    _currentTrack = _level->StartTrack();
    _player->MoveToPosition(Vector3::Zero);

    // Todo: remove.
    StartGame(0);
}

void Game::Update() {
    GameComponent::Update();

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
