//
// Created by Dmitry Mozgin on 21/04/2017.
//

#include <chrono>

#include "Common/Time.h"

#include "WaitForSeconds.h"

using namespace vd;

WaitForSeconds::WaitForSeconds(double seconds)
        : _seconds(seconds),
          _done(false),
          _endTime(-1.0f) {
}

void WaitForSeconds::Update() {
    if (_endTime < 0) {
        _endTime = Time::GetTime() + _seconds;
    }

    _done |= Time::GetTime() >= _endTime;
}

bool WaitForSeconds::IsDone() const {
    return _done;
}
