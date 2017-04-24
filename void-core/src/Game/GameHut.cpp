//
// Created by Dmitry Mozgin on 24/04/2017.
//

#include <Common/Time.h>
#include "GameHut.h"

using namespace vd;

GameHut::GameHut(std::shared_ptr<IAudioPlayer> &audioPlayer) {
    _musicSystem = std::make_shared<MusicSystem>(audioPlayer);
}

void GameHut::Start() {
}

void GameHut::Update() {
    Time::Update();

    _musicSystem->Update();
}
