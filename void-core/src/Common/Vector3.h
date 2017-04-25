//
// Created by Dmitry Mozgin on 25/04/2017.
//


#include "Math.h"

namespace vd {

template <typename T>
class Vector3T {

public:

    //region Constants

    //! (0, 0, 1)
    static const Vector3T<T> Forward;

    //! (0, 0, 0)
    static const Vector3T<T> Zero;

    //endregion

    T x;

    T y;

    T z;

    Vector3T() : Vector3T(0, 0) {
    }

    Vector3T(T x, T y) : Vector3T(x, y, 0) {
    }

    Vector3T(T x, T y, T z) {
        this->x = x;
        this->y = y;
        this->z = z;
    }

    Vector3T<T> operator-() const {
        return Vector3T<T>(-this->x, -this->y, -this->z);
    }

    static T Distance(Vector3T<T> v1, Vector3T<T> v2) {
        auto dx = v2.x - v1.x;
        auto dy = v2.y - v1.y;
        auto dz = v2.z - v1.z;

        return Math<T>::Sqrt(dx * dx + dy * dy + dz * dz);
    }

    static Vector3T<T> Lerp(Vector3T<T> a, Vector3T<T> b, double blend) {
        a.x = blend * (b.x - a.x) + a.x;
        a.y = blend * (b.y - a.y) + a.y;
        a.z = blend * (b.z - a.z) + a.z;
        return a;
    }

    // No implicit conversion to Vector2.

};

template <typename T>
const Vector3T<T> Vector3T<T>::Forward = Vector3T<T>(0, 0, 1);

template <typename T>
const Vector3T<T> Vector3T<T>::Zero = Vector3T<T>(0, 0, 0);

typedef Vector3T<float> Vector3;

}




