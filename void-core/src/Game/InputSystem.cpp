//
// Created by Dmitry Mozgin on 28/04/2017.
//

#include <iostream>
#include "InputSystem.h"

using namespace vd;

IInputSystem::~IInputSystem() {
}

//region InputSystem

InputSystem::InputSystem(const IInputRef &input)
        : _input(input),
          _refreshEnabledHandlers(true),
          _touchController(std::make_unique<InputSystemTouchController>(*this))
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

InputSystem::TouchController::TouchController(const float thresholdInUnits)
        : _swipeThreshold(thresholdInUnits) {
    // Todo: implement.
}

void InputSystem::TouchController::Update() {
    // Todo: implement.
}

//endregion

//region InputSystemTouchController

InputSystem::InputSystemTouchController::InputSystemTouchController(InputSystem &inputSystem)
        : TouchController(0.1f),
          _inputSystem(inputSystem) {
}

void InputSystem::InputSystemTouchController::OnSwipe(MoveDirection direction) {
    // Todo: implement.
}

//endregion
