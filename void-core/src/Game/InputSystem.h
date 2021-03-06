//
// Created by Dmitry Mozgin on 28/04/2017.
//

#pragma once

#include <memory>
#include <vector>
#include <string>
#include <unordered_map>
#include <boost/signals2.hpp>

#include <Common/Common.h>
#include <Common/Input.h>
#include <Common/Components/GameComponent.h>

#include "MoveDirection.h"

namespace vd {

enum class InputSystemEvent
{
    PlayerMove = 0,
    Reset = 1,
    AnyKey = 2,
    Quit = 3
};

//! By default all events are disabled.
class IInputSystem {
public:

    boost::signals2::signal<void(MoveDirection)> OnPlayerMove;

    boost::signals2::signal<void()> OnAnyKey;

    boost::signals2::signal<void()> OnReset;

    boost::signals2::signal<void()> OnQuit;

    virtual void Enable(InputSystemEvent event) = 0;

    virtual void Disable(InputSystemEvent event) = 0;

    virtual bool IsEnabled(InputSystemEvent event) = 0;

    virtual ~IInputSystem();

};

typedef std::shared_ptr<IInputSystem> IInputSystemRef;

class InputSystem
        : public GameComponent,
          public IInputSystem
{

    typedef std::function<void()> Handler;

    class TouchController {
    protected:

        TouchController(const IInputRef& input, const float thresholdInUnits);

        virtual void OnSwipe(MoveDirection direction) = 0;

    public:

        //! Call this function inside of GameComponent::Update.
        void Update();

    private:

        const IInputRef _input;

        const float _swipeThreshold;

        Vector2 _firstPosition;

        Vector2 _lastPosition;

        TouchPhase _currentTouchPhase = TouchPhase::Ended;

    };

    class InputSystemTouchController : public TouchController {
    public:

        InputSystemTouchController(const IInputRef& input, InputSystem& inputSystem);

    protected:

        virtual void OnSwipe(MoveDirection direction) override;

    private:

        InputSystem& _inputSystem;

    };

public:

    InputSystem(const IInputRef& input);

    //region GameComponent's overrides.

    void OnStart() override;

    void OnUpdate() override;

    //endregion

    void EnableAll();

    void DisableAll();

    //region Implementation of IInputSystem.

    virtual void Enable(InputSystemEvent event) override;

    virtual void Disable(InputSystemEvent event) override;

    virtual bool IsEnabled(InputSystemEvent event) override;

    //endregion

private:

    void ProcessEnabledHandlers();

    void ProcessTouches();

    void PlayerMoveHandler();

    void AnyKeyHandler();

    void ResetHandler();

    void QuitHandler();

    void UpdateEnabledHandlers();

    void RefreshEnabledHandlers();

    std::unordered_map<InputSystemEvent, Handler, EnumClassHash> _handlers;

    std::unordered_map<InputSystemEvent, bool, EnumClassHash> _handlerMask;

    std::vector<Handler> _enabledHandlers;

    const IInputRef _input;

    bool _refreshEnabledHandlers;

    std::unique_ptr<TouchController> _touchController;

};

}

