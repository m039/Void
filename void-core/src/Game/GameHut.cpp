//
// Created by Dmitry Mozgin on 24/04/2017.
//

#include <Common/Time.h>
#include "GameHut.h"

using namespace vd;

GameHut::GameHut(std::shared_ptr<IAudioPlayer> &audioPlayer) {
    auto musicSystem = std::make_shared<MusicSystem>(audioPlayer);

    _components.push_back(musicSystem);
}

// Before Start the game is in undefined state.
void GameHut::Start() {
    Time::Update();

    for (auto& c: _components) {
        c->Start();
    }
}

void GameHut::Update() {
    Time::Update();

    for (auto& c: _components) {
        c->Update();
    }
}
