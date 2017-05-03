//
// Created by Dmitry Mozgin on 03/05/2017.
//

#include <Common/Time.h>
#include "Rotation.h"

using namespace vd;

Rotation::Rotation(float startAngle, float delay, float speed) {
    this->startTime = (float) Time::GetTime() + delay;
    this->speed = speed;
    this->startAngle = startAngle;
}
