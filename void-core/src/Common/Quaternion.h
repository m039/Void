//
// Created by Dmitry Mozgin on 06/05/2017.
//

#pragma once

namespace vd {

//! Partially copied from MonoGame.
template<typename T>
class QuaternionT {
public:

    //! The x coordinate of this quaternion.
    T x;

    //! The y coordinate of this quaternion.
    T y;

    //! The z coordinate of this quaternion.
    T z;

    //! The rotation component of this quaternion.
    T w;

    /*!
     * Constructs a quaternion with X, Y, Z and W from four values.
     *
     * @param x The x coordinate in 3d-space.
     * @param y The y coordinate in 3d-space.
     * @param z The z coordinate in 3d-space.
     * @param w The rotation component.
     */
    QuaternionT(T x, T y, T z, T w)
    {
        this->x = x;
        this->y = y;
        this->z = z;
        this->w = w;
    }

    //! A quaternion representing no rotation.
    static const QuaternionT Identity;

    /*!
     * Creates a new quaternion from the specified yaw, pitch and roll angles.
     *
     * @param yaw Yaw around the y axis in radians.
     * @param pitch Pitch around the x axis in radians.
     * @param roll Roll around the z axis in radians.
     */
    static QuaternionT<T> CreateFromYawPitchRoll(T yaw, T pitch, T roll)
    {
        T halfRoll = roll * 0.5f;
        T halfPitch = pitch * 0.5f;
        T halfYaw = yaw * 0.5f;

        T sinRoll = Math<T>::Sin(halfRoll);
        T cosRoll = Math<T>::Cos(halfRoll);
        T sinPitch = Math<T>::Sin(halfPitch);
        T cosPitch = Math<T>::Cos(halfPitch);
        T sinYaw = Math<T>::Sin(halfYaw);
        T cosYaw = Math<T>::Cos(halfYaw);

        return QuaternionT<T>(
                (cosYaw * sinPitch * cosRoll) + (sinYaw * cosPitch * sinRoll),
                (sinYaw * cosPitch * cosRoll) - (cosYaw * sinPitch * sinRoll),
                (cosYaw * cosPitch * sinRoll) - (sinYaw * sinPitch * cosRoll),
                (cosYaw * cosPitch * cosRoll) + (sinYaw * sinPitch * sinRoll)
        );
    }

};

typedef QuaternionT<float> Quaternion;

template <typename T>
const QuaternionT<T> QuaternionT<T>::Identity = QuaternionT<T>(
        0, 0, 0, 1
);

}