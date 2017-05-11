//
// Created by Dmitry Mozgin on 04/05/2017.
//

#pragma once

#include <memory>

#include "Vector2.h"

namespace vd {

enum class KeyCode {
    None = -1,
    UpArrow,
    LeftArrow,
    DownArrow,
    RightArrow,
    W,
    A,
    S,
    D,
    Q,
    R
};

enum class TouchPhase
{
    Began,
    Moved,
    Ended,
    Canceled,
    Stationary
};

class ITouch {
public:

    virtual Vector2 GetPosition() = 0;

    virtual ~ITouch();

};

typedef std::shared_ptr<ITouch> ITouchRef;

class IInput {
public:

    //! Returns true during the frame the user starts pressing down the key identified by name.
    virtual bool GetKeyDown(KeyCode keyCode) = 0;

    //! Is any key or mouse button currently held down?
    virtual bool IsAnyKeyDown() = 0;

    //! Number of touches. Guaranteed not to change throughout the frame.
    virtual int GetTouchCount() = 0;

    //! Returns object representing status of a specific touch.
    virtual ITouchRef GetTouch(int index) = 0;

    virtual ~IInput();

};

typedef std::shared_ptr<IInput> IInputRef;

}
