//
// Created by Dmitry Mozgin on 28/04/2017.
//

#pragma once

#include <memory>

namespace vd {

class IInputSystem {
public:

    ~IInputSystem() {}
};

typedef std::shared_ptr<IInputSystem> IInputSystemRef;

class InputSystem {
public:



};

}

