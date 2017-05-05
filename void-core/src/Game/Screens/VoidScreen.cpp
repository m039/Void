//
// Created by Dmitry Mozgin on 28/04/2017.
//

#include <Common/Time.h>
#include "VoidScreen.h"

using namespace vd;

//region IVoidScreen

IVoidScreen::~IVoidScreen() {

}

//endregion

//region VoidScreen

VoidScreen::VoidScreen()
        : _alpha(0),
          _visible(false),
          _coroutine(nullptr) {
}

bool VoidScreen::IsVisible() {
    return _visible;
}

void VoidScreen::Show() {
    PerformShow(true);
}

void VoidScreen::Hide() {
    PerformShow(false);
}

void VoidScreen::ShowWithAnimation(Callback endAnimationCallback) {
    StartAnimation(true, endAnimationCallback);
}

void VoidScreen::HideWithAnimation(Callback endAnimationCallback) {
    StartAnimation(false, endAnimationCallback);
}

void VoidScreen::SetText(TextPlaceId textId, TextId id) {
    // Do nothing: leave the implementation to descendants.
}

void VoidScreen::SetTextColor(TextPlaceId textId, Color color) {
    // Do nothing: leave the implementation to descendants.
}

void VoidScreen::SetAlpha(float alpha) {
    _alpha = alpha;
}

float VoidScreen::GetAlpha() {
    return _alpha;
}

void VoidScreen::PerformShow(bool showOrHide) {
    if (_coroutine != nullptr) {
        GetCoroutineManager().Stop(_coroutine);
        _coroutine = nullptr;
    }

    if (showOrHide) {
        SetAlpha(1.0f);
    } else {
        SetAlpha(0.0f);
    }

    _visible = showOrHide;
}

void VoidScreen::StartAnimation(bool showOrHide, Callback endAnimationCallback) {
    if (_coroutine != nullptr) {
        CoroutineManager().Stop(_coroutine);
        _coroutine = nullptr;
    }

    _coroutine = GetCoroutineManager().Start(AnimationCoroutine(showOrHide, endAnimationCallback));
}

Coroutine::EnumerationFunction VoidScreen::AnimationCoroutine(bool showOrHide, Callback endAnimationCallback) {
    return [this, showOrHide, endAnimationCallback](Coroutine::YieldHandler& yield) {
        auto t = 0.0f;

        if (showOrHide) {
            while (t < 1) {
                yield(nullptr);
                t += Time::GetDeltaTime() / ShowTime;
                SetAlpha(MathF::SmoothStep(0, 1, t));
            }
        } else {
            while (t < 1) {
                yield(nullptr);
                t += Time::GetDeltaTime() / ShowTime;
                SetAlpha(1 - MathF::SmoothStep(0, 1, t));
            }
        }

        if (endAnimationCallback != nullptr) {
            endAnimationCallback();
        }

        _visible = showOrHide;
    };
}

//endregion
