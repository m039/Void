//
// Created by Dmitry Mozgin on 28/04/2017.
//

#pragma once

#include <memory>

namespace vd {

class IVoidScreen {
public:

    virtual ~IVoidScreen() {}
};

typedef std::shared_ptr<IVoidScreen> IVoidScreenRef;

class VoidScreen : public IVoidScreen {

};

}

