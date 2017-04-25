//
// Created by Dmitry Mozgin on 24/04/2017.
//

#pragma once

#include <memory>
#include <Common/Components/IAudioPlayer.h>
#include "MusicSystem.h"

namespace vd {

//! The main entry point of the game.
//! Place that stores all game components and handles a game lifecycle.
class GameHut {

public:

    GameHut(std::shared_ptr<IAudioPlayer>& audioPlayer);

    void Start();

    void Update();

private:

    std::vector<std::shared_ptr<IGameComponent>> _components;

};

}

