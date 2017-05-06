//
// Created by Dmitry Mozgin on 25/04/2017.
//

#include "ObjectPool.h"

using namespace vd;

//region IObjectPool

IObjectPool::~IObjectPool() {
}

//endregion

//region IObjectPool::IDrawQueue

IObjectPool::IDrawQueue::~IDrawQueue() {
}

//endregion

//region ObjectPool

const std::string ObjectPool::DefaultObjectsName = "ObjectCache's vTrackObject";

ObjectPool::ObjectPool()
        : _freeObjects(std::vector<IVoidTrackObjectRef>(NumberOfPrecreatedObject)) {
    // VoidGameHut is not fully initialized at this point, Init is used instead.
}

void ObjectPool::Init() {
    for (auto i = 0; i < NumberOfPrecreatedObject; i++) {
        _freeObjects[i] = CreateObject();
    }
}

IVoidTrackObjectRef ObjectPool::GetObject() {
    if (_freeObjects.size() != 0) {
        auto v = _freeObjects[0];
        _freeObjects.erase(_freeObjects.begin()); // Remove first element.
        return v;
    }

    return CreateObject(); // Out of objects, it shouldn't happen.
}

void ObjectPool::PutObject(const IVoidTrackObjectRef& object) {
    SetDefaults(object);
    _freeObjects.push_back(object);
}

void ObjectPool::PutObjects(const std::vector<IVoidTrackObjectRef>& objects) {
    for (auto object : objects) {
        SetDefaults(object);
    }

    _freeObjects.insert(_freeObjects.end(), objects.begin(), objects.end());
}

const IVoidTrackObjectRef ObjectPool::CreateObject() {
    auto object = std::make_shared<VoidTrackObject>(*this, DefaultObjectsName);
    SetDefaults(object);
    return object;
}

void ObjectPool::SetDefaults(const IVoidTrackObjectRef &object) {
    object->SetEnabled(false);
    object->SetName(DefaultObjectsName);
    object->SetAnimation(nullptr);
    object->Hide();
    object->SetTag("");
}

//endregion
