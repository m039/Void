//
// Created by Dmitry Mozgin on 04/05/2017.
//

#include "InputImpl.h"

using namespace vd;

InputImpl::InputImpl(VoidApp &app)
        : VoidAppObject(app),
          _timesToSkipUpdate(-1) {
}

bool InputImpl::GetKeyDown(KeyCode keyCode) {
    // True if the key has just been pressed.
    return (_pressedDownKeys.find(keyCode) != _pressedDownKeys.end()) &&
            (_heldDownKeys.find(keyCode) == _heldDownKeys.end());
}

bool InputImpl::IsAnyKeyDown() {
    return _heldDownKeys.size() > 0;
}

int InputImpl::GetTouchCount() {
    // Todo: implement.
    return 0;
}

ITouchRef InputImpl::GetTouch(int index) {
    // Todo: implement.
    return nullptr;
}

void InputImpl::Update() {
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
    if (keyCode != KeyCode::None) {
        _pressedDownKeys.insert(keyCode);
        _timesToSkipUpdate = 1; // Skip 1 update.
    }
}

void InputImpl::KeyUp(ci::app::KeyEvent event) {
    auto keyCode = ToKeyCode(event);
    if (keyCode != KeyCode::None) {
        _pressedDownKeys.erase(keyCode);
        _heldDownKeys.erase(keyCode);
    }
}

KeyCode InputImpl::ToKeyCode(ci::app::KeyEvent event) {
    auto code = event.getCode();

    switch (code) {
        case ci::app::KeyEvent::KEY_UP:
            return KeyCode::UpArrow;
        case ci::app::KeyEvent::KEY_LEFT:
            return KeyCode::LeftArrow;
        case ci::app::KeyEvent::KEY_DOWN:
            return KeyCode::DownArrow;
        case ci::app::KeyEvent::KEY_RIGHT:
            return KeyCode::RightArrow;
        case ci::app::KeyEvent::KEY_w:
            return KeyCode::W;
        case ci::app::KeyEvent::KEY_a:
            return KeyCode::A;
        case ci::app::KeyEvent::KEY_s:
            return KeyCode::S;
        case ci::app::KeyEvent::KEY_d:
            return KeyCode::D;
        case ci::app::KeyEvent::KEY_q:
            return KeyCode::Q;
        case ci::app::KeyEvent::KEY_r:
            return KeyCode::R;
        default:
            return KeyCode::None;
    }
}
