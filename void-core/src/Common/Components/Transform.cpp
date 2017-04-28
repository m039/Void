//
// Created by Dmitry Mozgin on 28/04/2017.
//

#include "Transform.h"

using namespace vd;

Transform::Transform()
        : _localScale(Vector3(1, 1, 1)),
          _position(Vector3::Zero)
{
    // Todo: implement.
}

const Vector3 Transform::GetLocalScale() const {
    return _localScale;
}

void Transform::SetLocaleScale(const Vector3 &scale) {
    _localScale = scale;
}

const Vector3 Transform::GetPosition() const {
    return _position;
}

void Transform::SetPosition(const Vector3 &position) {
    _position = position;
}

void Transform::Rotate(float xAngle, float yAngle, float zAngle) {
    // Todo: implement.
}


