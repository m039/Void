//
// Created by Dmitry Mozgin on 24/04/2017.
//

#pragma once

#include <boost/algorithm/clamp.hpp>
#include <algorithm>
#include <math.h>
#include <tgmath.h>

namespace vd {

template <typename T>
class Math {

public:

    static T SmoothStep(T edge0, T edge1, T x) {
        T t = boost::algorithm::clamp((x - edge0) / (edge1 - edge0), 0, 1);
        return t * t * (3 - 2 * t);
    }

    static constexpr T Pi = M_PI;

    static inline T Sqrt(T v) {
        return sqrt(v);
    }
    static inline T Sin(T v) {
        return sin(v);
    }

    static inline T Cos(T v) {
        return cos(v);
    }

    static inline T Min(T v1, T v2) {
        return std::min(v1, v2);
    }

    static inline T Pow(T base, double exponent) {
        return pow(base, exponent);
    }

};

typedef Math<float> MathF;

typedef Math<double> MathD;

}