//
// Created by Dmitry Mozgin on 28/04/2017.
//

#pragma once

#include <memory>

namespace vd {

class IHelpScreen {
public:

    virtual void ShowAndHide() = 0;

    ~IHelpScreen() {}
};

typedef std::shared_ptr<IHelpScreen> IHelpScreenRef;

}