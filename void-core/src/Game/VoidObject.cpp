//
// Created by Dmitry Mozgin on 25/04/2017.
//

#include "VoidObject.h"

#include "Game/ObjectPool.h"

#include "Colors.h"
#include "Config.h"

using namespace vd;

VoidObject::VoidObject(IObjectPool &pool, const std::string &name)
        : _objectPool(pool),
          _isEnabled(false),
          _isHidden(true),
          _name(name),
          _mesh(nullptr),
          _color(Colors::Black),
          _transform(std::make_shared<Transform>()) {
    InitDefault();
}

void VoidObject::InitDefault() {
    _transform->SetLocaleScale(Vector3(Config::DefaultScale, Config::DefaultScale, 1));
}

const Color VoidObject::GetColor() const {
    return _color;
}

void VoidObject::SetColor(const Color &color) {
    _color = color;
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
    return _isHidden;
}

const ITransformRef VoidObject::GetTransform() const {
    return _transform;
}

const IMeshRef VoidObject::GetMesh() const {
    return _mesh;
}

void VoidObject::SetMesh(const IMeshRef &mesh) {
    _mesh = mesh;
}

void VoidObject::Hide() {
    RemoveFromDrawQueue();

    _isHidden = true;
}

void VoidObject::Show() {
    _isHidden = false;

    auto drawQueue = _objectPool.GetDrawQueue();
    if (drawQueue != nullptr) {
        drawQueue->Insert(*this);
    }
}

void VoidObject::Destroy() {
    // Todo: implement.
}

VoidObject::~VoidObject() {
   RemoveFromDrawQueue();
}

void VoidObject::RemoveFromDrawQueue() {
    auto drawQueue = _objectPool.GetDrawQueue();
    if (drawQueue != nullptr) {
        drawQueue->Remove(*this);
    }
}