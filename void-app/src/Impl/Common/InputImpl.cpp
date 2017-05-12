//
// Created by Dmitry Mozgin on 04/05/2017.
//

#include "InputImpl.h"

#include "../../VoidApp.h"

using namespace vd;

enum Button
{
    Button,
    ButtonSelect,
    JoystickX,
    JoystickY
};

//region InputImpl

InputImpl::InputImpl(VoidApp &app)
        : VoidAppObject(app),
          _timesToSkipUpdate(-1) {

#if defined(SUPPORT_GAMEPADS)
    // Add a classic controller support.

    _inputManager = std::make_unique<gainput::InputManager>();
              
    auto padId = _inputManager->CreateDevice<gainput::InputDevicePad>();

    _inputMap = std::make_unique<gainput::InputMap>(*_inputManager);

    _inputMap->MapFloat(JoystickX, padId, gainput::PadButtonLeftStickX);
    _inputMap->MapFloat(JoystickY, padId, gainput::PadButtonLeftStickY);
    _inputMap->MapBool(ButtonSelect, padId, gainput::PadButtonSelect);
    _inputMap->MapBool(Button, padId, gainput::PadButtonA);
    _inputMap->MapBool(Button, padId, gainput::PadButtonB);
    _inputMap->MapBool(Button, padId, gainput::PadButtonStart);

    _inputMap->SetDeadZone(JoystickX, 0.5f);
    _inputMap->SetDeadZone(JoystickY, 0.5f);

#endif
}

bool InputImpl::GetKeyDown(vd::KeyCode keyCode) {
    // True if the key has just been pressed.

#if defined(SUPPORT_GAMEPADS)

    if (keyCode == vd::KeyCode::Q && _inputMap->GetBoolIsNew(ButtonSelect)) {
        return true;
    }

    if (MathF::Abs(_inputMap->GetFloatDelta(JoystickX)) > 0.0f) {
        if (keyCode == vd::KeyCode::LeftArrow &&
                _inputMap->GetFloat(JoystickX) < -0.5f &&
                _inputMap->GetFloatPrevious(JoystickX) >= -0.5f) {
            return true;
        }

        if (keyCode == vd::KeyCode::RightArrow &&
                _inputMap->GetFloat(JoystickX) > 0.5f &&
                _inputMap->GetFloatPrevious(JoystickX) <= 0.5f) {
            return true;
        }
    }

    if (MathF::Abs(_inputMap->GetFloatDelta(JoystickY)) > 0.0f) {
        if (keyCode == vd::KeyCode::UpArrow &&
                _inputMap->GetFloat(JoystickY) < -0.5f &&
                _inputMap->GetFloatPrevious(JoystickY) >= -0.5f) {
            return true;
        }

        if (keyCode == vd::KeyCode::DownArrow &&
                _inputMap->GetFloat(JoystickY) > 0.5f &&
                _inputMap->GetFloatPrevious(JoystickY) <= 0.5f) {
            return true;
        }
    }

#endif

    return (_pressedDownKeys.find(keyCode) != _pressedDownKeys.end()) &&
            (_heldDownKeys.find(keyCode) == _heldDownKeys.end());
}

bool InputImpl::IsAnyKeyDown() {
#if defined(SUPPORT_GAMEPADS)
    
    if (_inputMap->GetBoolIsNew(Button) ||
            MathF::Abs(_inputMap->GetFloatDelta(JoystickX)) > 0.5f ||
            MathF::Abs(_inputMap->GetFloatDelta(JoystickY)) > 0.5f) {
        return true;
    }
    
#endif

    return _heldDownKeys.size() > 0 || GetTouchCount() > 0;
}

int InputImpl::GetTouchCount() {
    return static_cast<int>(_touchIds.size());
}

ITouchRef InputImpl::GetTouch(int index) {
    return _touchesById[_touchIds[index]];
}

void InputImpl::Update() {
#if defined(SUPPORT_GAMEPADS)

    _inputManager->Update();

#endif

    if (_timesToSkipUpdate == -1) {
        return;
    }

    if (_timesToSkipUpdate == 0) {
        // Flush all keys from  pressedDownKeys to heldDownKeys.
        for (auto& k: _pressedDownKeys) {
            _heldDownKeys.insert(k);
        }
    }

    _timesToSkipUpdate--;
}

void InputImpl::KeyDown(ci::app::KeyEvent event) {
    auto keyCode = ToKeyCode(event);
    if (keyCode != vd::KeyCode::None) {
        _pressedDownKeys.insert(keyCode);
        _timesToSkipUpdate = 1; // Skip 1 update.
    }
}

void InputImpl::KeyUp(ci::app::KeyEvent event) {
    auto keyCode = ToKeyCode(event);
    if (keyCode != vd::KeyCode::None) {
        _pressedDownKeys.erase(keyCode);
        _heldDownKeys.erase(keyCode);
    }
}

vd::KeyCode InputImpl::ToKeyCode(ci::app::KeyEvent event) {
    auto code = event.getCode();

    switch (code) {
        case ci::app::KeyEvent::KEY_UP:
            return vd::KeyCode::UpArrow;
        case ci::app::KeyEvent::KEY_LEFT:
            return vd::KeyCode::LeftArrow;
        case ci::app::KeyEvent::KEY_DOWN:
            return vd::KeyCode::DownArrow;
        case ci::app::KeyEvent::KEY_RIGHT:
            return vd::KeyCode::RightArrow;
        case ci::app::KeyEvent::KEY_w:
            return vd::KeyCode::W;
        case ci::app::KeyEvent::KEY_a:
            return vd::KeyCode::A;
        case ci::app::KeyEvent::KEY_s:
            return vd::KeyCode::S;
        case ci::app::KeyEvent::KEY_d:
            return vd::KeyCode::D;
        case ci::app::KeyEvent::KEY_q:
            return vd::KeyCode::Q;
        case ci::app::KeyEvent::KEY_r:
            return vd::KeyCode::R;
        default:
            return vd::KeyCode::None;
    }
}

void InputImpl::TouchesBegan(ci::app::TouchEvent event) {
    auto size = app.getWindow()->getSize();

    for (auto& t: event.getTouches()) {
        auto touchImpl = std::make_shared<InputImpl::TouchImpl>();
        touchImpl->SetTouch(size, t);

        auto id = t.getId();

        _touchesById[id] = touchImpl;
        _touchIds.push_back(id);
    }
}

void InputImpl::TouchesMoved(ci::app::TouchEvent event) {
    auto size = app.getWindow()->getSize();

    for (auto& t: event.getTouches()) {
        _touchesById[t.getId()]->SetTouch(size, t);
    }
}

void InputImpl::TouchesEnded(ci::app::TouchEvent event) {
    for (auto& t: event.getTouches()) {
        auto id = t.getId();

        _touchIds.erase(std::find(_touchIds.begin(), _touchIds.end(), id));
        _touchesById[id] = nullptr;
    }
}

//endregion

//region InputImpl

Vector2 InputImpl::TouchImpl::GetPosition() {
    return _position;
}

void InputImpl::TouchImpl::SetTouch(const ci::ivec2& size, const ci::app::TouchEvent::Touch& touch) {
    _position = vd::Vector2(touch.getX(), size.y - touch.getY());
}

//endregion
