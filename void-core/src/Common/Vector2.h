//
// Created by Dmitry Mozgin on 25/04/2017.
//


#include "Math.h"

namespace vd {

template <typename T>
class Vector2T {

public:

    //region Constants

    //! (0, 0)
    static const Vector2T<T> Zero;

    //endregion

    T x;

    T y;

    Vector2T() : Vector2T(0, 0) {
    }

    Vector2T(T x, T y) {
        this->x = x;
        this->y = y;
    }

    static T Distance(const Vector2T<T>& v1, const Vector2T<T>& v2) {
        auto dx = v2.x - v1.x;
        auto dy = v2.y - v1.y;

        return Math::Sqrt<T>(dx * dx + dy * dy);
    }

    // No implicit conversion to Vector3.
};

template <typename T>
const Vector2T<T> Vector2T<T>::Zero = Vector2T<T>(0, 0);

typedef Vector2T<float> Vector2;

}





