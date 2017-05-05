//
// Created by Dmitry Mozgin on 25/04/2017.
//

#pragma once

#include <Game/Screens/VoidScreen.h>
#include <Game/Screens/IHelpScreen.h>
#include <Game/Levels/Level35.h>
#include <Game/Levels/Level1.h>

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

typedef IGame* IGameRef;

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

    //region GameComponent's overrides.

    void OnStart() override;

    void OnUpdate() override;

    //endregion

    virtual ~Game();

private:

    //region Event handlers.

    void OnAnyKey();

    void OnPlayerMove(MoveDirection moveDirection);

    void OnQuit();

    void OnReset();

    //endregion

    void StartGame(int levelIndex);

    const IObjectPoolRef _objectPool;

    const IPlayerRef _player;

    const IMusicSystemRef _musicSystem;

    const IInputSystemRef _inputSystem;

    const ISceneRef _scene;

    VoidTrackRef _currentTrack;

    // Todo: remove.
    std::unique_ptr<Level1> _level;

};

}

