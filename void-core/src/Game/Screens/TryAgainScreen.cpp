//
// Created by Dmitry Mozgin on 05/05/2017.
//

#include <Game/Colors.h>
#include <Game/Localization/LocalizationManager.h>
#include "TryAgainScreen.h"

using namespace vd;

void TryAgainScreen::Draw(IScreenDrawer& drawer) {
    auto alpha = GetAlpha();

    if (alpha > 0) {
        // plane

        auto planeColor = Colors::WarningRed;
        planeColor.a = alpha;

        drawer.DrawFullscreenPlane(planeColor);

        // body

        drawer.SelectTextFont();

        auto textColor = Colors::White;
        textColor.a = alpha;
        auto measure = drawer.MeasureString(_body);

        auto width = drawer.GetScreenWidth();
        auto height = drawer.GetScreenHeight();

        auto topMargin = (int)(height * 122.0f / 450.0f);
        auto bottomMargin = (int)(height * (1.0f - 39.0f / 450.0f));

        drawer.DrawText(_body, Vector2(width / 2.0f - measure.x / 2.0f, topMargin + measure.y), textColor);

        // footer

        measure = drawer.MeasureString(_footer);

        drawer.DrawText(_footer, Vector2(width / 2.0f - measure.x / 2.0f, bottomMargin + measure.y), textColor);
    }
}

void TryAgainScreen::SetText(TextPlaceId placeId, TextId textId) {
    VoidScreen::SetText(placeId, textId);

    if (placeId == TextPlaceId::Body) {
        _body = LocalizationManager::ToText(textId);
    } else if (placeId == TextPlaceId::Footer) {
        _footer = LocalizationManager::ToText(textId);
    }
}