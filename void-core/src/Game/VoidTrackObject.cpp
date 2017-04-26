//
// Created by Dmitry Mozgin on 25/04/2017.
//

#include <Game/MeshGenerators/MeshGenerator.h>
#include "VoidTrackObject.h"

using namespace vd;

VoidTrackObject::VoidTrackObject(IObjectPool &pool, const std::string& name)
        : VoidTrackObject(pool, name, Triangle, false) {}

VoidTrackObject::VoidTrackObject(IObjectPool &pool, const std::string& name, ShapeType shapeType, bool isHollow)
        : VoidObject(pool, name) {
    RegenerateMesh(shapeType, isHollow);
}

void VoidTrackObject::SetRotation(float angle) {
    // Todo: implement.
}

void VoidTrackObject::Rotate(float angle) {
    // Todo: implement.
}

const std::string &VoidTrackObject::GetTag() const {
    return _tag;
}

void VoidTrackObject::SetTag(const std::string& tag) {
    _tag = tag;
}

bool VoidTrackObject::IsHollow() const {
    return _isHollow;
}

void VoidTrackObject::SetHollow(bool hollow) {
    RegenerateMesh(_shapeType, hollow);
}

ShapeType VoidTrackObject::GetShapeType() const {
    return _shapeType;
}

void VoidTrackObject::SetShapeType(ShapeType type) {
    RegenerateMesh(_shapeType, type);
}

void VoidTrackObject::RegenerateMesh(ShapeType shapeType, bool isHollow) {
    if (shapeType == _shapeType && isHollow == _isHollow)
        return;

    _shapeType = shapeType;
    _isHollow = isHollow;

    SetMesh(MeshGenerator::Generate(_shapeType, _isHollow));
}