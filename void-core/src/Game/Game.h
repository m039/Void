//
// Created by Dmitry Mozgin on 25/04/2017.
//

#pragma once

#include <Game/Screens/VoidScreen.h>
#include <Game/Levels/Levels.h>

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

    virtual ~IGame();

};

typedef IGame* IGameRef;

//!
//! Entry point of the game's logic.
//!
class Game
        : public GameComponent,
          public IGame
{
public:

    Game(
            const IObjectPoolRef& objectCache,
            const IPlayerRef& player,
            const IMusicSystemRef& musicSystem,
            const IInputSystemRef& inputSystem,
            const ISceneRef& scene,
            const IVoidScreenRef& tryAgainScreen,
            const IVoidScreenRef& introScreen,
            const IHelpScreenRef& movementHelpScreen
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

    virtual void OnStart() override;

    virtual void OnUpdate() override;

    //endregion

private:

    enum class EndGameCause {
        CollidedWithPortal,
        MissedGate,
        FinishedGame
    };

    //region InputSystem's event handlers.

    void OnAnyKey();

    void OnPlayerMove(MoveDirection moveDirection);

    void OnQuit();

    void OnReset();

    //endregion

    //region Parameters.

    bool _skipIntro;

    int _startLevel;

    //endregion

    VoidLevelRef GetCurrentLevel();

    VoidLevelRef GetNextLevel();

    Color GetColorOfFirstLevel();

    void StartGame(int levelIndex);

    void InitLevel();

    //! Shows a help message at 3 and 4 levels.
    void InitHelpScreen();

    //! Moves to the next level.
    void MoveToNextLevel();

    void MoveToLevel(int levelIndex);

    void EndGame(EndGameCause cause);

    //! Returns true if there is next level.
    bool CanMoveToNextLevel();

    static std::vector<VoidLevelRef> CreateLevels(const IGameRef& game);

    const IObjectPoolRef _objectPool;

    const IPlayerRef _player;

    const IMusicSystemRef _musicSystem;

    const IInputSystemRef _inputSystem;

    const ISceneRef _scene;

    const IVoidScreenRef _tryAgainScreen;

    const IVoidScreenRef _introScreen;

    const IHelpScreenRef _movementHelpScreen;

    int _currentLevelIndex;

    VoidTrackRef _currentTrack;

    bool _backgroundColorChanged;

    std::vector<VoidLevelRef> _levels;

};

}

