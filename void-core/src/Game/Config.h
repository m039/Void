//
// Created by Dmitry Mozgin on 21/04/2017.
//

#pragma once

namespace vd {

class Config {

public:

    static const float Gap = 0.8f;

    static const float MoveTime = 0.6f; // sec

    static const float Threshold = 0.1f;

    static const float RotationSpeed = 30f;

    static const float DefaultScale = 0.33f;

    static const int NumberOfSidesInCircle = 50;

    static const float FadeTime = 1.5f;

private:
    Config() {
    }
};

}
