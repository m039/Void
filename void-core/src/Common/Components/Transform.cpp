//
// Created by Dmitry Mozgin on 28/04/2017.
//

#include "Transform.h"

using namespace vd;

//region ITransform

ITransform::~ITransform() {
}

//endregion

//region Transform

Transform::Transform()
        : _localScale(Vector3(1, 1, 1)),
          _position(Vector3::Zero),
          _rotation(Quaternion::Identity),
          _translationIsDirty(true),
          _scaleIsDirty(true),
          _rotationIsDirty(true),
          _modelMatrix(Matrix4::Identity)
{
}

const Vector3 Transform::GetLocalScale() const {
    return _localScale;
}

void Transform::SetLocaleScale(const Vector3 &scale) {
    _localScale = scale;
    _scaleIsDirty = true;
}

const Vector3 Transform::GetPosition() const {
    return _position;
}

void Transform::SetPosition(const Vector3 &position) {
    _position = position;
    _translationIsDirty = true;
}

Quaternion Transform::GetRotation() const {
    return _rotation;
}

void Transform::SetRotation(const Quaternion& quaternion) {
    _rotation = quaternion;
    _rotationIsDirty = true;
}

Matrix4 Transform::GetModelMatrix() {
    if (_rotationIsDirty || _translationIsDirty || _scaleIsDirty) {
        auto translation = Matrix4::CreateTranslation(_position);
        auto rotation = Matrix4::CreateFromQuaternion(_rotation);
        auto scale = Matrix4::CreateScale(_localScale.x, _localScale.y, _localScale.z);

        _modelMatrix = scale * rotation * translation;

        _rotationIsDirty = _translationIsDirty = _scaleIsDirty = false;
    }

    return _modelMatrix;
}

//endregion
