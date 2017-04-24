//
// Created by Dmitry Mozgin on 21/04/2017.
//

#pragma once

namespace vd {

class Config {

public:

    constexpr static const float Gap = 0.8f;

    constexpr static const float MoveTime = 0.6f; // sec

    constexpr static const float Threshold = 0.1f;

    constexpr static const float RotationSpeed = 30.0f;

    constexpr static const float DefaultScale = 0.33f;

    constexpr static const int NumberOfSidesInCircle = 50;

    constexpr static const float FadeTime = 1.5f;

private:
    Config() {
    }
};

}
