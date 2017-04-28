//
// Created by Dmitry Mozgin on 25/04/2017.
//

#pragma once

#include <Common/Mesh.h>
#include "../../VoidApp.h"

namespace vd {

class MeshGl : public IMesh {

public:

    MeshGl(const std::vector<Vector3> &vertices,
           const std::vector<int> &triangles);

    void Draw(const VoidApp &app);

    virtual ~MeshGl() override;

private:

    std::vector<GLfloat> _vertices;

    std::vector<GLubyte> _elements;

};

}

