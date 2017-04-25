//
// Created by Dmitry Mozgin on 25/04/2017.
//

#include "MeshFactory.h"
#include "MeshGl.h"

using namespace vd;

IMeshRef MeshFactory::Create(
        const std::vector<vd::Vector3, std::allocator<vd::Vector3>> &vertices,
        const std::vector<int> &triangles,
        const std::vector<vd::Vector3, std::allocator<vd::Vector3>> &normals,
        const std::vector<vd::Vector2, std::allocator<vd::Vector2>> &uv) {
    return std::make_shared<MeshGl>();
}
