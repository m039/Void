//
// Created by Dmitry Mozgin on 28/04/2017.
//

#include <iostream>
#include <Common/GameContext.h>
#include "InputSystem.h"

using namespace vd;

//region IInputSystem

IInputSystem::~IInputSystem() {
}

//endregion

//region InputSystem

InputSystem::InputSystem(const IInputRef &input)
        : _input(input),
          _refreshEnabledHandlers(true),
          _touchController(std::make_unique<InputSystemTouchController>(input, *this))
{
}

void InputSystem::OnStart() {
    GameComponent::OnStart();

    _handlers[InputSystemEvent::PlayerMove] = std::bind(&InputSystem::PlayerMoveHandler, this);
    _handlers[InputSystemEvent::Reset] = std::bind(&InputSystem::ResetHandler, this);
    _handlers[InputSystemEvent::AnyKey] = std::bind(&InputSystem::AnyKeyHandler, this);
    _handlers[InputSystemEvent::Quit] = std::bind(&InputSystem::QuitHandler, this);
}

void InputSystem::OnUpdate() {
    GameComponent::OnUpdate();

    ProcessEnabledHandlers();
    ProcessTouches();
    RefreshEnabledHandlers();
}

void InputSystem::EnableAll() {
    for (auto const& h : _handlers) {
        _handlerMask[h.first] = true;
    }

    UpdateEnabledHandlers();
}

void InputSystem::DisableAll() {
    _handlerMask.clear();
    UpdateEnabledHandlers();
}

void InputSystem::Enable(InputSystemEvent event) {
    _handlerMask[event] = true;
    UpdateEnabledHandlers();
}

void InputSystem::Disable(InputSystemEvent event) {
    _handlerMask[event] = false;
    UpdateEnabledHandlers();
}

bool InputSystem::IsEnabled(InputSystemEvent event) {
    return (_handlerMask.find(event) != _handlerMask.end()) && _handlerMask[event];
}

void InputSystem::ProcessEnabledHandlers() {
    for (auto const& h : _enabledHandlers) {
        h();
    }
}

void InputSystem::ProcessTouches() {
    if (_touchController != nullptr) {
        _touchController->Update();
    }
}

void InputSystem::PlayerMoveHandler() {
    MoveDirection direction = MoveDirection::None;

    if (_input->GetKeyDown(KeyCode::UpArrow) || _input->GetKeyDown(KeyCode::W)) {
        direction = MoveDirection::Up;
    } else if (_input->GetKeyDown(KeyCode::LeftArrow) || _input->GetKeyDown(KeyCode::A)) {
        direction = MoveDirection::Left;
    } else if (_input->GetKeyDown(KeyCode::DownArrow) || _input->GetKeyDown(KeyCode::S)) {
        direction = MoveDirection::Down;
    } else if (_input->GetKeyDown(KeyCode::RightArrow) || _input->GetKeyDown(KeyCode::D)) {
        direction = MoveDirection::Right;
    }

    if (direction != MoveDirection::None) {
        OnPlayerMove(direction);
    }
}

void InputSystem::AnyKeyHandler() {
    if (_input->IsAnyKeyDown()) {
        OnAnyKey();
    }
}

void InputSystem::ResetHandler() {
    if (_input->GetKeyDown(KeyCode::R)) {
        OnReset();
    }
}

void InputSystem::QuitHandler() {
    if (_input->GetKeyDown(KeyCode::Q)) {
        OnQuit();
    }
}

void InputSystem::UpdateEnabledHandlers() {
    _refreshEnabledHandlers = true;
}

void InputSystem::RefreshEnabledHandlers() {
    if (_refreshEnabledHandlers) {
        _enabledHandlers.clear();

        for (auto const& h : _handlers) {
            if (IsEnabled(h.first)) {
                _enabledHandlers.push_back(_handlers[h.first]);
            }
        }

        _refreshEnabledHandlers = false;
    }
}

//endregion

//region TouchController

InputSystem::TouchController::TouchController(
        const IInputRef& input,
        const float thresholdInUnits
) : _input(input),
    _swipeThreshold(thresholdInUnits * GameContext::GetScreenDpi()) {
    _firstPosition = _lastPosition = Vector2::Zero;
}

void InputSystem::TouchController::Update() {
    if (_input->GetTouchCount() > 0) {
        auto touch = _input->GetTouch(0);

        if (_currentTouchPhase == TouchPhase::Ended) {
            _firstPosition = _lastPosition = touch->GetPosition();
            _currentTouchPhase = TouchPhase::Moved;
        } else if (_currentTouchPhase == TouchPhase::Moved) {
            _lastPosition = touch->GetPosition();
        }
    } else {
        if (_currentTouchPhase == TouchPhase::Moved) {
            _currentTouchPhase = TouchPhase::Ended;

            if (Vector2::Distance(_firstPosition, _lastPosition) > _swipeThreshold) {
                if (MathF::Abs(_firstPosition.x - _lastPosition.x) >
                    MathF::Abs(_firstPosition.y - _lastPosition.y)) {
                    if ((_lastPosition.x > _firstPosition.x)) {
                        OnSwipe(MoveDirection::Left);
                    } else {
                        OnSwipe(MoveDirection::Right);
                    }
                } else {
                    if (_lastPosition.y > _firstPosition.y) {
                        OnSwipe(MoveDirection::Down);
                    } else {
                        OnSwipe(MoveDirection::Up);
                    }
                }
            }
        }
    }
}

//endregion

//region InputSystemTouchController

InputSystem::InputSystemTouchController::InputSystemTouchController(
        const IInputRef& input,
        InputSystem& inputSystem
)
        : TouchController(input, 0.1f),
          _inputSystem(inputSystem) {
}

void InputSystem::InputSystemTouchController::OnSwipe(MoveDirection direction) {
    if (_inputSystem.IsEnabled(InputSystemEvent::PlayerMove)) {
        _inputSystem.OnPlayerMove(direction);
    }
}

//endregion
