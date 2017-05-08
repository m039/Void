//
// Created by Dmitry Mozgin on 05/05/2017.
//

#include <Game/Colors.h>
#include <Common/GameContext.h>
#include <Game/Localization/LocalizationManager.h>
#include "IntroScreen.h"

using namespace vd;

void IntroScreen::Draw(IScreenDrawer& drawer) {
    auto alpha = GetAlpha();

    if (alpha > 0) {
        auto backgroundColor = Colors::Black;
        backgroundColor.a = alpha;

        drawer.DrawFullscreenPlane(backgroundColor);

        auto textColor = Colors::White;
        textColor.a = alpha;

        auto x = drawer.GetScreenWidth() / 2.0f;
        auto y = drawer.GetScreenHeight() / 2.0f;

        // Void

        auto topMargin = (int)(drawer.GetScreenHeight() * 48.0f / 450.0f);
        auto text = LocalizationManager::ToText(TextId::Void);

        drawer.SelectHeadlineFont();

        auto measure = drawer.MeasureString(text);

        drawer.DrawText(text, Vector2(x - measure.x / 2, topMargin + measure.y / 2.0f), textColor);

        // Title

        if (GameContext::IsMobilePlatform()) {
            text = LocalizationManager::ToText(TextId::TouchScreenToStart);
        } else {
            text = LocalizationManager::ToText(TextId::PressAnyButtonToStart);
        }

        drawer.SelectTextFont();

        measure = drawer.MeasureString(text);

        drawer.DrawText(text, Vector2(x - measure.x / 2.0f, y + measure.y / 2.0f), textColor);
    }
}
