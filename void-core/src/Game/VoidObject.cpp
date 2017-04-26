//
// Created by Dmitry Mozgin on 25/04/2017.
//

#include "VoidObject.h"

using namespace vd;

VoidObject::VoidObject(const IObjectPool &pool, const std::string &name) {
    InitDefault();
}

void VoidObject::InitDefault() {
    // Todo: implement.
}

const Color &VoidObject::GetColor() const {
    return _color;
}

void VoidObject::SetColor(Color &color) {
    // Todo: implement.
}

const std::string &VoidObject::GetName() const {
    return _name;
}

void VoidObject::SetName(const std::string &name) {
    _name = name;
}

bool VoidObject::IsEnabled() const {
    return _isEnabled;
}

void VoidObject::SetEnabled(bool value) {
    _isEnabled = value;
}

bool VoidObject::IsHidden() const {
    // Todo: implement.
    return false;
}

void VoidObject::SetHidden(bool value) {
    // Todo: implement.
}

ITransform &VoidObject::GetTransform() {
    return _transform;
}

const IMeshRef &VoidObject::GetMesh() const {
    return _mesh;
}

void VoidObject::SetMesh(const IMeshRef &mesh) {
    _mesh = mesh;
}

void VoidObject::Hide() {
    // Todo: implement.
}

void VoidObject::Show() {
    // Todo: implement.
}

void VoidObject::Destroy() {
    // Todo: implement.
}

VoidObject::Transform::Transform()
        : _localScale(Vector3(1, 1, 1)),
          _position(Vector3::Zero)
{
    // Todo: implement.
}

const Vector3 &VoidObject::Transform::GetLocalScale() const {
    return _localScale;
}

void VoidObject::Transform::SetLocaleScale(const Vector3 &scale) {
    _localScale = scale;
}

const Vector3 &VoidObject::Transform::GetPosition() const {
    return _position;
}

void VoidObject::Transform::SetPosition(const Vector3 &position) {
    _position = position;
}

void VoidObject::Transform::Rotate(float xAngle, float yAngle, float zAngle) {
    // Todo: implement.
}
