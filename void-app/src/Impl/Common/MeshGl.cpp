//
// Created by Dmitry Mozgin on 25/04/2017.
//

#include "cinder/gl/gl.h"
#include "MeshGl.h"
#include "../../DrawHelper.h"

using namespace vd;
using namespace ci;

MeshGl::~MeshGl() {

}

MeshGl::MeshGl(const std::vector<Vector3> &vertices,
               const std::vector<int> &triangles) {
    for (auto &v : vertices) {
        _vertices.push_back(v.x);
        _vertices.push_back(v.y);
        _vertices.push_back(v.z);
    }

    _elements = std::vector<GLubyte>(triangles.begin(), triangles.end());
}

void MeshGl::Draw(const VoidApp &app) {
    DrawHelper::Draw(app, _vertices, _elements);
}