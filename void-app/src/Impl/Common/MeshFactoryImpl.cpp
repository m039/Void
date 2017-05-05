//
// Created by Dmitry Mozgin on 25/04/2017.
//

#include "MeshFactoryImpl.h"
#include "MeshImpl.h"

using namespace vd;

IMeshRef MeshFactoryImpl::Create(
        const std::vector<Vector3> &vertices,
        const std::vector<int> &triangles,
        const std::vector<Vector3> &normals,
        const std::vector<Vector2> &uv) {
    // Note: normals and uv are ignored for the current game.
    return std::make_shared<MeshImpl>(vertices, triangles);
}
