//
// Created by Dmitry Mozgin on 03/05/2017.
//

#pragma once

#include "Animation.h"

namespace vd {

// Only rotation animation is supported.
class Rotation : public Animation {
public:

    float startTime;

    float speed;

    float startAngle;

    Rotation(float startAngle, float delay, float speed);

};

typedef std::shared_ptr<Rotation> RotationRef;

}

