//
// Created by Dmitry Mozgin on 25/04/2017.
//

#pragma once

#include <Common/Mesh.h>

namespace vd {

class MeshFactory : public IMeshFactory {

public:

    virtual IMeshRef Create(
            const std::vector<Vector3> &vertices,
            const std::vector<int> &triangles,
            const std::vector<Vector3> &normals,
            const std::vector<Vector2> &uv
    ) override ;

};

}

