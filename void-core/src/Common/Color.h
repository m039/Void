//
// Created by Dmitry Mozgin on 26/04/2017.
//

#pragma once

namespace vd {

template <typename T>
class ColorT {
public:

    //region Constants

    static const ColorT<T> Cyan;

    static const ColorT<T> Red;

    static const ColorT<T> Green;

    static const ColorT<T> Blue;

    static const ColorT<T> Black;

    static const ColorT<T> White;

    //endregion

    T r;

    T g;

    T b;

    T a;

    ColorT(T r, T g, T b, T a) {
        this->r = r;
        this->g = g;
        this->b = b;
        this->a = a;
    }

    bool operator==(const ColorT& rhs)
    {
        if (this == &rhs)
            return true;

        return this->r == rhs.r && this->g == rhs.g && this->b == rhs.b; // Discard alpha.
    }

};

template <typename T>
const ColorT<T> ColorT<T>::Cyan = ColorT<T>(0, 1, 1, 1);

template <typename T>
const ColorT<T> ColorT<T>::Green = ColorT<T>(0, 1, 0, 1);

template <typename T>
const ColorT<T> ColorT<T>::Red = ColorT<T>(1, 0, 0, 1);

template <typename T>
const ColorT<T> ColorT<T>::Blue = ColorT<T>(0, 0, 1, 1);

template <typename T>
const ColorT<T> ColorT<T>::Black = ColorT<T>(0, 0, 0, 1);

template <typename T>
const ColorT<T> ColorT<T>::White = ColorT<T>(1, 1, 1, 1);

typedef ColorT<float> Color;

}