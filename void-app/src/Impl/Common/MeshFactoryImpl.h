//
// Created by Dmitry Mozgin on 25/04/2017.
//

#pragma once

#include <Common/Mesh.h>
#include "../../VoidAppObject.h"

namespace vd {

class MeshFactoryImpl : public VoidAppObject, public IMeshFactory {

public:

    MeshFactoryImpl(VoidApp &app);

    virtual IMeshRef Create(
            const std::vector<Vector3> &vertices,
            const std::vector<int> &triangles,
            const std::vector<Vector3> &normals,
            const std::vector<Vector2> &uv
    ) override ;

};

}

