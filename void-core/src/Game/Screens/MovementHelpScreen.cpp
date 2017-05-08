//
// Created by Dmitry Mozgin on 05/05/2017.
//

#include <Common/Coroutines/WaitForSeconds.h>
#include <Game/Colors.h>
#include <Game/Localization/LocalizationManager.h>
#include "MovementHelpScreen.h"

using namespace vd;

MovementHelpScreen::MovementHelpScreen()
        : _color(Colors::Black) {
}

void MovementHelpScreen::Draw(IScreenDrawer& drawer) {
    if (_text == "")
        return;

    auto width = drawer.GetScreenWidth();
    auto height = drawer.GetScreenHeight();
    auto bottomMargin = (height * (1 - 45.0f / 450.0f));

    drawer.SelectTextFont();

    auto measure = drawer.MeasureString(_text);

    _color.a = GetAlpha();

    drawer.DrawText(
            _text,
            Vector2(width / 2.0f - measure.x / 2.0f, bottomMargin + measure.y / 2.0f),
            _color
    );
}

void MovementHelpScreen::ShowAndHide() {
    ShowWithAnimation([this]() {
        PerformDelayed(3, [this]() {
            HideWithAnimation(nullptr);
        });
    });
}

void MovementHelpScreen::PerformDelayed(float delay, Callback callback) {
    GetCoroutineManager().Start(DelayedCoroutine(delay, callback));
}

Coroutine::EnumerationFunction MovementHelpScreen::DelayedCoroutine(float delay, Callback callback) {
    return [delay, callback](Coroutine::YieldHandler& yield) {
        yield(std::make_shared<WaitForSeconds>(delay));

        if (callback != nullptr) {
            callback();
        }
    };
}

void MovementHelpScreen::SetText(TextPlaceId placeId, TextId textId) {
    _text = LocalizationManager::ToText(textId);
}

void MovementHelpScreen::SetTextColor(TextPlaceId placeId, Color color) {
    _color = color;
}
