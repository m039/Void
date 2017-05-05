//
// Created by Dmitry Mozgin on 04/05/2017.
//

#pragma once

#include "../../VoidAppObject.h"

#include <Common/Input.h>
#include <vector>
#include <set>

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

private:

    KeyCode ToKeyCode(ci::app::KeyEvent event);

    std::set<KeyCode> _pressedDownKeys;

    std::set<KeyCode> _heldDownKeys;

    int _timesToSkipUpdate;

};

}

