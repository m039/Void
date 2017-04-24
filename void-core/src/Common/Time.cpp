//
// Created by Dmitry Mozgin on 24/04/2017.
//

#include "Time.h"

using namespace vd;

sec_t Time::_DeltaTime = 0.0f;

sec_t Time::_PreviousTime = 0.0f;

bool Time::_Started = false;

void Time::Update() {
    auto time = GetTime();

    if (!_Started) {
        _PreviousTime = time;
        _Started = true;
    }

    _DeltaTime = time - _PreviousTime;
    _PreviousTime = time;
}
