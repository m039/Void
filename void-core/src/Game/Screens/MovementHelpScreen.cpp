//
// Created by Dmitry Mozgin on 05/05/2017.
//

#include <Common/Coroutines/WaitForSeconds.h>
#include "MovementHelpScreen.h"

using namespace vd;

MovementHelpScreen::~MovementHelpScreen() {

}

void MovementHelpScreen::Draw(IScreenDrawer& drawer) {
    // Todo: implement.
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
