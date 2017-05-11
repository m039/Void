//
// Created by Dmitry Mozgin on 25/04/2017.
//

#include "MeshGenerator.h"
#include "SquareMeshGenerator.h"
#include "CircleMeshGenerator.h"
#include "TriangleMeshGenerator.h"

using namespace vd;

const std::unique_ptr<MeshGenerator> MeshGenerator::_SquareMeshGenerator =
        std::make_unique<SquareMeshGenerator>();

const std::unique_ptr<MeshGenerator> MeshGenerator::_CircleMeshGenerator =
        std::make_unique<CircleMeshGenerator>();

const std::unique_ptr<MeshGenerator> MeshGenerator::_TriangleMeshGenerator =
        std::make_unique<TriangleMeshGenerator>();

IMeshRef MeshGenerator::Generate(ShapeType shapeType, bool isHollow) {
    switch (shapeType) {
        case ShapeType::Square:
            return _SquareMeshGenerator->GenMesh(isHollow);
        case ShapeType::Circle:
            return _CircleMeshGenerator->GenMesh(isHollow);
        case ShapeType::Triangle:
            return _TriangleMeshGenerator->GenMesh(isHollow);
        default:
            throw std::invalid_argument("Invalid shape type.");
    }
}

IMeshRef MeshGenerator::GenMesh(bool isHollow) {
    if (_hollowCachedMesh == nullptr) {
        _hollowCachedMesh = GenHollowMesh();
    }

    if (_defaultCachedMesh == nullptr) {
        _defaultCachedMesh = GenDefaultMesh();
    }

    return isHollow ? _hollowCachedMesh : _defaultCachedMesh;
}

std::vector<Vector3> MeshGenerator::CreateNormals(unsigned size) {
    auto normals = std::vector<Vector3>(size);

    for (unsigned i = 0; i < size; i++) {
        normals[i] = -Vector3::Forward;
    }

    return normals;
}
