//
// Created by Dmitry Mozgin on 04/05/2017.
//

#pragma once

#include <vector>
#include <set>
#include <unordered_map>

#include <Common/Input.h>

#include "../../VoidAppObject.h"

#if defined(SUPPORT_GAMEPADS)

#include <gainput/gainput.h>

#endif

namespace vd {

class InputImpl :
        public VoidAppObject,
        public IInput
{
public:

    InputImpl(VoidApp &app);

    //region Implementation of IInput.

    virtual bool GetKeyDown(KeyCode keyCode) override;

    virtual bool IsAnyKeyDown() override;

    virtual int GetTouchCount() override;

    virtual ITouchRef GetTouch(int index) override;

    //endregion

    void Update();

    void KeyDown(ci::app::KeyEvent event);

    void KeyUp(ci::app::KeyEvent event);
    
    void TouchesBegan(ci::app::TouchEvent event);
    
    void TouchesMoved(ci::app::TouchEvent event);
    
    void TouchesEnded(ci::app::TouchEvent event);

private:

    class TouchImpl : public ITouch {
    public:

        virtual Vector2 GetPosition() override;

        void SetTouch(const ci::ivec2& size, const ci::app::TouchEvent::Touch& touch);

    private:

        Vector2 _position;

    };

    KeyCode ToKeyCode(ci::app::KeyEvent event);

    std::set<KeyCode> _pressedDownKeys;

    std::set<KeyCode> _heldDownKeys;

    int _timesToSkipUpdate;

    std::unordered_map<uint32_t, std::shared_ptr<TouchImpl>> _touchesById;

    std::vector<uint32_t> _touchIds;

#if defined(SUPPORT_GAMEPADS)

    std::unique_ptr<gainput::InputManager> _inputManager;

    std::unique_ptr<gainput::InputMap> _inputMap;

#endif

};

}

