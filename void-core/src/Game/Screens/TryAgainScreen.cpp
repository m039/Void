//
// Created by Dmitry Mozgin on 05/05/2017.
//

#include <Game/Colors.h>
#include "TryAgainScreen.h"

using namespace vd;

TryAgainScreen::~TryAgainScreen() {

}

void TryAgainScreen::Draw(IScreenDrawer& drawer) {
    auto alpha = GetAlpha();

    if (alpha > 0) {
        // plane

        auto planeColor = Colors::WarningRed;
        planeColor.a = alpha;

        drawer.DrawFullscreenPlane(planeColor);

        // Todo: implement the rest.
    }
}
