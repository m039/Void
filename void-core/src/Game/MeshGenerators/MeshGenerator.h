//
// Created by Dmitry Mozgin on 25/04/2017.
//

#pragma once

#include <Common/Mesh.h>
#include <Game/ShapeType.h>

namespace vd {

//!
//! Warning: meshes are cached! Not suitable for dynamically changing scenes!
//!
class MeshGenerator {

public:

    static IMeshRef Generate(ShapeType shapeType, bool isHollow = true);

protected:

    static constexpr float Size = 0.5f;

    virtual IMeshRef GenHollowMesh() = 0;

    virtual IMeshRef GenDefaultMesh() = 0;

    std::vector<Vector3> CreateNormals(unsigned size);

private:

    IMeshRef _hollowCachedMesh;

    IMeshRef _defaultCachedMesh;

    IMeshRef GenMesh(bool isHollow);

    static const std::unique_ptr<MeshGenerator> _SquareMeshGenerator;

    static const std::unique_ptr<MeshGenerator> _CircleMeshGenerator;

    static const std::unique_ptr<MeshGenerator> _TriangleMeshGenerator;

};

}

