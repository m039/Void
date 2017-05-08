//
// Created by Dmitry Mozgin on 06/05/2017.
//

#pragma once

#include "Vector3.h"
#include "Quaternion.h"

namespace vd {

//! Partially copied from MonoGame.
template<typename T>
class Matrix4T {
public:

    //region Fields

    //! A first row and first column value.
    T m11;

    //! A first row and second column value.
    T m12;

    //! A first row and third column value.
    T m13;

    //! A first row and fourth column value.
    T m14;

    //! A second row and first column value.
    T m21;

    //! A second row and second column value.
    T m22;

    //! A second row and third column value.
    T m23;

    //! A second row and fourth column value.
    T m24;

    //! A third row and first column value.
    T m31;

    //! A third row and second column value.
    T m32;

    //! A third row and third column value.
    T m33;

    //! A third row and fourth column value.
    T m34;

    //! A fourth row and first column value.
    T m41;

    //! A fourth row and second column value.
    T m42;

    //! A fourth row and third column value.
    T m43;

    //! A fourth row and fourth column value.
    T m44;

    //endregion

    //! Constructs a matrix.
    Matrix4T(
            T m11, T m12, T m13, T m14, 
            T m21, T m22, T m23, T m24, 
            T m31, T m32, T m33, T m34, 
            T m41, T m42, T m43, T m44
    ) {
        this->m11 = m11;
        this->m12 = m12;
        this->m13 = m13;
        this->m14 = m14;
        this->m21 = m21;
        this->m22 = m22;
        this->m23 = m23;
        this->m24 = m24;
        this->m31 = m31;
        this->m32 = m32;
        this->m33 = m33;
        this->m34 = m34;
        this->m41 = m41;
        this->m42 = m42;
        this->m43 = m43;
        this->m44 = m44;
    }

    //! The identity matrix.
    static const Matrix4T Identity;

    /*!
     * Creates a new scaling matrix.
     *
     * @param xScale Scale value for X axis.
     * @param yScale Scale value for Y axis.
     * @param zScale Scale value for Z axis.
     */
    static Matrix4T<T> CreateScale(T xScale, T yScale, T zScale) {
        auto m11 = xScale;
        auto m12 = 0.0f;
        auto m13 = 0.0f;
        auto m14 = 0.0f;
        auto m21 = 0.0f;
        auto m22 = yScale;
        auto m23 = 0.0f;
        auto m24 = 0.0f;
        auto m31 = 0.0f;
        auto m32 = 0.0f;
        auto m33 = zScale;
        auto m34 = 0.0f;
        auto m41 = 0.0f;
        auto m42 = 0.0f;
        auto m43 = 0.0f;
        auto m44 = 1.0f;

        return Matrix4T<T>(
                m11, m12, m13, m14,
                m21, m22, m23, m24,
                m31, m32, m33, m34,
                m41, m42, m43, m44
        );
    }

    /*!
     * Creates a new translation matrix.
     *
     * @param position X,Y and Z coordinates of translation.
     */
    static Matrix4T<T> CreateTranslation(const Vector3T<T>& position) {
        auto m11 = 1.0f;
        auto m12 = 0.0f;
        auto m13 = 0.0f;
        auto m14 = 0.0f;
        auto m21 = 0.0f;
        auto m22 = 1.0f;
        auto m23 = 0.0f;
        auto m24 = 0.0f;
        auto m31 = 0.0f;
        auto m32 = 0.0f;
        auto m33 = 1.0f;
        auto m34 = 0.0f;
        auto m41 = position.x;
        auto m42 = position.y;
        auto m43 = position.z;
        auto m44 = 1.0f;

        return Matrix4T<T>(
                m11, m12, m13, m14,
                m21, m22, m23, m24,
                m31, m32, m33, m34,
                m41, m42, m43, m44
        );
    }

    /*!
     * Creates a new rotation matrix from a quaternion.
     *
     * @param quaternion Quaternion of rotation moment.
     * @param result The rotation matrix as an output parameter.
     */
    static Matrix4T<T> CreateFromQuaternion(const QuaternionT<T>& quaternion) {
        T num9 = quaternion.x * quaternion.x;
        T num8 = quaternion.y * quaternion.y;
        T num7 = quaternion.z * quaternion.z;
        T num6 = quaternion.x * quaternion.y;
        T num5 = quaternion.z * quaternion.w;
        T num4 = quaternion.z * quaternion.x;
        T num3 = quaternion.y * quaternion.w;
        T num2 = quaternion.y * quaternion.z;
        T num = quaternion.x * quaternion.w;
        auto m11 = 1.0f - (2.0f * (num8 + num7));
        auto m12 = 2.0f * (num6 + num5);
        auto m13 = 2.0f * (num4 - num3);
        auto m14 = 0.0f;
        auto m21 = 2.0f * (num6 - num5);
        auto m22 = 1.0f - (2.0f * (num7 + num9));
        auto m23 = 2.0f * (num2 + num);
        auto m24 = 0.0f;
        auto m31 = 2.0f * (num4 + num3);
        auto m32 = 2.0f * (num2 - num);
        auto m33 = 1.0f - (2.0f * (num8 + num9));
        auto m34 = 0.0f;
        auto m41 = 0.0f;
        auto m42 = 0.0f;
        auto m43 = 0.0f;
        auto m44 = 1.0f;

        return Matrix4T<T>(
                m11, m12, m13, m14,
                m21, m22, m23, m24,
                m31, m32, m33, m34,
                m41, m42, m43, m44
        );
    }

    Matrix4T<T> operator*(const Matrix4T<T>& rhs) {
        auto m11 = (((this->m11 * rhs.m11) + (this->m12 * rhs.m21)) + (this->m13 * rhs.m31)) + (this->m14 * rhs.m41);
        auto m12 = (((this->m11 * rhs.m12) + (this->m12 * rhs.m22)) + (this->m13 * rhs.m32)) + (this->m14 * rhs.m42);
        auto m13 = (((this->m11 * rhs.m13) + (this->m12 * rhs.m23)) + (this->m13 * rhs.m33)) + (this->m14 * rhs.m43);
        auto m14 = (((this->m11 * rhs.m14) + (this->m12 * rhs.m24)) + (this->m13 * rhs.m34)) + (this->m14 * rhs.m44);
        auto m21 = (((this->m21 * rhs.m11) + (this->m22 * rhs.m21)) + (this->m23 * rhs.m31)) + (this->m24 * rhs.m41);
        auto m22 = (((this->m21 * rhs.m12) + (this->m22 * rhs.m22)) + (this->m23 * rhs.m32)) + (this->m24 * rhs.m42);
        auto m23 = (((this->m21 * rhs.m13) + (this->m22 * rhs.m23)) + (this->m23 * rhs.m33)) + (this->m24 * rhs.m43);
        auto m24 = (((this->m21 * rhs.m14) + (this->m22 * rhs.m24)) + (this->m23 * rhs.m34)) + (this->m24 * rhs.m44);
        auto m31 = (((this->m31 * rhs.m11) + (this->m32 * rhs.m21)) + (this->m33 * rhs.m31)) + (this->m34 * rhs.m41);
        auto m32 = (((this->m31 * rhs.m12) + (this->m32 * rhs.m22)) + (this->m33 * rhs.m32)) + (this->m34 * rhs.m42);
        auto m33 = (((this->m31 * rhs.m13) + (this->m32 * rhs.m23)) + (this->m33 * rhs.m33)) + (this->m34 * rhs.m43);
        auto m34 = (((this->m31 * rhs.m14) + (this->m32 * rhs.m24)) + (this->m33 * rhs.m34)) + (this->m34 * rhs.m44);
        auto m41 = (((this->m41 * rhs.m11) + (this->m42 * rhs.m21)) + (this->m43 * rhs.m31)) + (this->m44 * rhs.m41);
        auto m42 = (((this->m41 * rhs.m12) + (this->m42 * rhs.m22)) + (this->m43 * rhs.m32)) + (this->m44 * rhs.m42);
        auto m43 = (((this->m41 * rhs.m13) + (this->m42 * rhs.m23)) + (this->m43 * rhs.m33)) + (this->m44 * rhs.m43);
        auto m44 = (((this->m41 * rhs.m14) + (this->m42 * rhs.m24)) + (this->m43 * rhs.m34)) + (this->m44 * rhs.m44);

        return Matrix4T(
                m11, m12, m13, m14,
                m21, m22, m23, m24,
                m31, m32, m33, m34,
                m41, m42, m43, m44
        );
    }

};

typedef Matrix4T<float> Matrix4;

template <typename T>
const Matrix4T<T> Matrix4T<T>::Identity = Matrix4T<T>(
        1.0f, 0.0f, 0.0f, 0.0f,
        0.0f, 1.0f, 0.0f, 0.0f,
        0.0f, 0.0f, 1.0f, 0.0f,
        0.0f, 0.0f, 0.0f, 1.0f
);

}


