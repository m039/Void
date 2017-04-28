//
// Created by Dmitry Mozgin on 25/04/2017.
//

#include "Game.h"

using namespace vd;

Game::Game(
        const vd::IObjectPoolRef &objectCache,
        const vd::IPlayerRef &player,
        const vd::IMusicSystemRef &musicSystem,
        const vd::IInputSystemRef &inputSystem,
        const vd::ISceneRef &scene) {

}

Game::~Game() {

}

IPlayerRef Game::GetPlayer() const {
    return vd::IPlayerRef();
}

IObjectPoolRef Game::GetObjectPool() const {
    return vd::IObjectPoolRef();
}

IInputSystemRef Game::GetInputSystem() const {
    return vd::IInputSystemRef();
}

IMusicSystemRef Game::GetMusicSystem() const {
    return vd::IMusicSystemRef();
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
    return 0;
}
