//
// Created by Dmitry Mozgin on 05/05/2017.
//

#pragma once

#include "VoidScreen.h"

namespace vd {

class IntroScreen : public VoidScreen {
public:

    //region Implementation of IScreenDrawable.

    virtual void Draw(IScreenDrawer& drawer) override;

    //endregion

};

}

