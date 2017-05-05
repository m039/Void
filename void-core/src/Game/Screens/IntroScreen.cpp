//
// Created by Dmitry Mozgin on 05/05/2017.
//

#include <Game/Colors.h>
#include "IntroScreen.h"

using namespace vd;

IntroScreen::~IntroScreen() {

}

void IntroScreen::Draw(IScreenDrawer& drawer) {
    auto alpha = GetAlpha();

    if (alpha > 0) {
        auto backgroundColor = Colors::Black;
        backgroundColor.a = alpha;

        drawer.DrawFullscreenPlane(backgroundColor);

        // Todo: implement the rest.
    }

}
