//
// Created by Dmitry Mozgin on 05/05/2017.
//

#pragma once

#include "VoidScreen.h"

namespace vd {

class TryAgainScreen : public VoidScreen {
public:

    //region Implementation of IScreenDrawable.

    virtual void Draw(IScreenDrawer& drawer) override;

    virtual void SetText(TextPlaceId placeId, TextId textId) override;

    //endregion

private:

    std::string _body;

    std::string _footer;

};

}


