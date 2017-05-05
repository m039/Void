//
// Created by Dmitry Mozgin on 24/04/2017.
//

#include "Time.h"

using namespace vd;

//region Time

sec_t Time::_DeltaTime = 0.0f;

//endregion

//region internal::Time

sec_t internal::Time::_PreviousTime = 0.0f;

bool internal::Time::_Started = false;

void internal::Time::Update() {
    auto time = vd::Time::GetTime();

    if (!_Started) {
        _PreviousTime = time;
        _Started = true;
    }

    vd::Time::_DeltaTime = time - _PreviousTime;
    _PreviousTime = time;
}

//endregion
