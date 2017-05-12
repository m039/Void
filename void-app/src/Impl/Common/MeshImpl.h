//
// Created by Dmitry Mozgin on 25/04/2017.
//

#pragma once

#include <Common/Mesh.h>
#include "../../VoidApp.h"

namespace vd {

class MeshImpl : public IMesh {

public:

    MeshImpl(
            VoidApp& app,
            const std::vector<Vector3> &vertices,
            const std::vector<int> &triangles
    );

    void Draw(const VoidApp &app);

private:

    ci::gl::BatchRef _batch;

};

}

