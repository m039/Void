//
// Created by Dmitry Mozgin on 25/04/2017.
//

#include "Game.h"
#include "Levels/Level35.h"

using namespace vd;

Game::Game(
        const IObjectPoolRef& objectPool,
        const IPlayerRef& player,
        const IMusicSystemRef& musicSystem,
        const IInputSystemRef& inputSystem,
        const ISceneRef& scene
) {
    _objectPool = objectPool;
    _player = player;
    _musicSystem = musicSystem;
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
    return vd::IVoidScreenRef();
}

IVoidScreenRef Game::GetIntroScreen() const {
    return vd::IVoidScreenRef();
}

IHelpScreenRef Game::GetMovementHelpScreen() const {
    return vd::IHelpScreenRef();
}

ISceneRef Game::GetScene() const {
    return vd::ISceneRef();
}

float Game::TimeForNextLevel() const {
    return 4.6f;
}

void Game::Start() {
    GameComponent::Start();

    _level = std::make_unique<Level35>();
    _level->Initialize(this);
}

void Game::Update() {
    GameComponent::Update();
}
