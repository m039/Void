//
// Created by Dmitry Mozgin on 25/04/2017.
//

#pragma once

#include <vector>
#include "Vector3.h"
#include "Vector2.h"

namespace vd {

//! A mesh implementation is hardware dependendent (OpenGL, DirectX or whatever).
class IMesh {
public:

    virtual ~IMesh();

};

typedef std::shared_ptr<IMesh> IMeshRef;

class IMeshFactory {
public:

    virtual IMeshRef Create(
            const std::vector<Vector3> &vertices,
            const std::vector<int> &triangles,
            const std::vector<Vector3> &normals,
            const std::vector<Vector2> &uv
    ) = 0;

    virtual ~IMeshFactory();

};

typedef std::shared_ptr<IMeshFactory> IMeshFactoryRef;

class Mesh {
public:

    static IMeshRef Create(
            const std::vector<Vector3>& vertices,
            const std::vector<int>& triangles,
            const std::vector<Vector3>& normals
    );

    //! Factory method to create a mesh (or model).
    static IMeshRef Create(
            const std::vector<Vector3>& vertices,
            const std::vector<int>& triangles,
            const std::vector<Vector3>& normals,
            const std::vector<Vector2>& uv
    );

};

// Hide factory methods somewhere no one sees.
namespace internal {

class Mesh {
    friend vd::Mesh;

public:

    static void RegisterMeshFactory(const IMeshFactoryRef& factory);

private:

    static IMeshFactoryRef _Factory;

};

}

}
