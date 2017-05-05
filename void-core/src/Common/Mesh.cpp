//
// Created by Dmitry Mozgin on 25/04/2017.
//

#include "Mesh.h"

using namespace vd;

//region IMesh

IMesh::~IMesh() {
}

//endregion

//region IMeshFactory

IMeshFactory::~IMeshFactory() {
}

//endregion

//region Mesh

IMeshRef Mesh::Create(
        const std::vector<Vector3> &vertices,
        const std::vector<int> &triangles,
        const std::vector<Vector3> &normals
) {
    return Mesh::Create(vertices, triangles, normals, std::vector<Vector2>());
}

IMeshRef Mesh::Create(
        const std::vector<Vector3> &vertices,
        const std::vector<int> &triangles,
        const std::vector<Vector3> &normals,
        const std::vector<Vector2> &uv
) {
    if (vd::internal::Mesh::_Factory == nullptr) {
        throw std::domain_error("Mesh factory is not registered!");
    }

    return vd::internal::Mesh::_Factory->Create(vertices, triangles, normals, uv);
}

//endregion

//region internal::Mesh

IMeshFactoryRef vd::internal::Mesh::_Factory = nullptr;

void vd::internal::Mesh::RegisterMeshFactory(const IMeshFactoryRef& factory) {
    _Factory = factory;
}

//endregion

