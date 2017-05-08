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

    MovementHelpScreen();

    //region Implementation of IScreenDrawable.

    virtual void Draw(IScreenDrawer& drawer) override;

    //endregion

    //region Implementation of IHelpScreen.

    virtual void ShowAndHide() override;

    virtual void SetText(TextPlaceId placeId, TextId textId) override;

    virtual void SetTextColor(TextPlaceId placeId, Color color) override;

    //endregion

private:

    void PerformDelayed(float delay, Callback callback);

    static Coroutine::EnumerationFunction DelayedCoroutine(float delay, Callback callback);

    std::string _text;

    Color _color;

};

}

