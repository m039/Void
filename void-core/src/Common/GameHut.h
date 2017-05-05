//
// Created by Dmitry Mozgin on 24/04/2017.
//

#pragma once

#include <memory>

#include <Common/Components/AudioPlayer.h>
#include <Common/Components/GameComponent.h>

#include "Mesh.h"
#include "GameContext.h"

namespace vd {

class IMeshGenerator;

//!
//! The main entry point of the game, design goals:
//!
//! - Place that stores all game components and handles a game lifecycle.
//! - It doesn't depend on a particular game.
//! - No graphics code, cause almost always graphics are implementation dependent.
//!
//! Note: a small shelter for a game, hence the name GameHut.
//!
class GameHut {

public:

    // Before the call to GameHut::Start a game is in undefined state.
    virtual void Start();

    virtual void Update();

    // <strikethrough>virtual void Draw();</strikethrough>

    virtual ~GameHut();

protected:

    // Force inheritance by making constructor protected.
    GameHut(
            const IGameContextRef& gameContext,
            const IMeshFactoryRef& meshFactory
    );

    std::vector<std::shared_ptr<IGameComponent>> Components;

};

}

