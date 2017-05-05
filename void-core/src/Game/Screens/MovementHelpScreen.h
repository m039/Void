//
// Created by Dmitry Mozgin on 05/05/2017.
//

#pragma once

#include "VoidScreen.h"

namespace vd {

class MovementHelpScreen
        : public VoidScreen,
          public IHelpScreen {
public:

    //region Implementation of IScreenDrawable.

    virtual void Draw(IScreenDrawer& drawer) override;

    //endregion

    //region Implementation of IHelpScreen.

    virtual void ShowAndHide() override;

    //endregion

    virtual ~MovementHelpScreen();

};

}

