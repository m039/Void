//
// Created by Dmitry Mozgin on 25/04/2017.
//

#pragma once

#include <Common/Mesh.h>
#include "../../VoidApp.h"

namespace vd {

class MeshImpl : public IMesh {

public:

    MeshImpl(const std::vector<Vector3> &vertices,
           const std::vector<int> &triangles);

    void Draw(const VoidApp &app);

    virtual ~MeshImpl() override;

private:

    std::vector<GLfloat> _vertices;

    std::vector<GLubyte> _elements;

};

}

