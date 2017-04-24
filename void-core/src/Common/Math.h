//
// Created by Dmitry Mozgin on 24/04/2017.
//

#pragma once

#include <boost/algorithm/clamp.hpp>
#include <algorithm>

namespace vd {

class Math {

public:

    template <typename T>
    static T SmoothStep(T edge0, T edge1, T x) {
        T t = boost::algorithm::clamp((x - edge0) / (edge1 - edge0), 0, 1);
        return t * t * (3 - 2 * t);
    }

};

}