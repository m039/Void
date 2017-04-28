//
// Created by Dmitry Mozgin on 25/04/2017.
//

#pragma once

#include <Game/Screens/VoidScreen.h>
#include <Game/Screens/IHelpScreen.h>

#include "Player.h"
#include "MusicSystem.h"
#include "ObjectPool.h"
#include "InputSystem.h"
#include "Scene.h"

namespace vd {

class IGame {
public:

    virtual IPlayerRef GetPlayer() const = 0;

    virtual IObjectPoolRef GetObjectPool() const = 0;

    virtual IInputSystemRef GetInputSystem() const = 0;

    virtual IMusicSystemRef GetMusicSystem() const = 0;

    virtual IVoidScreenRef GetTryAgainScreen() const = 0;

    virtual IVoidScreenRef GetIntroScreen() const = 0;

    virtual IHelpScreenRef GetMovementHelpScreen() const = 0;

    virtual ISceneRef GetScene() const = 0;

    virtual float TimeForNextLevel() const = 0;

    virtual ~IGame() {}
};

typedef std::shared_ptr<IGame> IGameRef;

//! Entry point of the game's logic.
class Game
        : public GameComponent,
          public IGame {
public:

    Game(
            const IObjectPoolRef& objectCache,
            const IPlayerRef& player,
            const IMusicSystemRef& musicSystem,
            const IInputSystemRef& inputSystem,
            const ISceneRef& scene
    );


    //region Implementation of IGame.
    
    virtual IPlayerRef GetPlayer() const override;

    virtual IObjectPoolRef GetObjectPool() const override;

    virtual IInputSystemRef GetInputSystem() const override;

    virtual IMusicSystemRef GetMusicSystem() const override;

    virtual IVoidScreenRef GetTryAgainScreen() const override;

    virtual IVoidScreenRef GetIntroScreen() const override;

    virtual IHelpScreenRef GetMovementHelpScreen() const override;

    virtual ISceneRef GetScene() const override;

    virtual float TimeForNextLevel() const override;
    
    //endregion

    virtual ~Game();

private:

    IObjectPoolRef _objectCache;

    IPlayerRef _player;

    IMusicSystemRef _musicSystem;

    IInputSystemRef _inputSystem;

    ISceneRef _scene;

};

}

