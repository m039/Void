//
// Created by Dmitry Mozgin on 24/04/2017.
//

#pragma once

#include <memory>
#include <Common/Components/IAudioPlayer.h>
#include <Common/Components/GameComponent.h>
#include "Mesh.h"

namespace vd {

class IMeshGenerator;

//!
//! The main entry point of the game:
//!
//! - Place that stores all game components and handles a game lifecycle.
//! - It doesn't depend on a particular game.
//!
class GameHut {

public:

    // Before the call to GameHut::Start the game is in undefined state.
    virtual void Start();

    virtual void Update();

protected:

    // Force inheritance by making constructor protected.
    GameHut(const IMeshFactoryRef&  meshFactory);

    std::vector<std::shared_ptr<IGameComponent>> Components;

};

}

