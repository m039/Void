//
// Created by Dmitry Mozgin on 25/04/2017.
//

#include "cinder/gl/gl.h"

#undef None // Shit.. but otherwise a problem with compilation on rpi.

#include "MeshImpl.h"
#include "../../DrawHelper.h"

using namespace vd;
using namespace ci;

MeshImpl::MeshImpl(
        VoidApp& app,
        const std::vector<Vector3> &vertices,
        const std::vector<int> &triangles
) {
    ci::gl::VertBatch vertBatch;

    vertBatch.begin(GL_TRIANGLES);

    for (auto& el: triangles) {
        auto& v = vertices[el];

        vertBatch.vertex(v.x, v.y, v.z);
    }

    vertBatch.end();

    _batch = gl::Batch::create(
            vertBatch,
            app.GetShader()->GetInternalShader()
    );
}

void MeshImpl::Draw(const VoidApp &app) {
    _batch->draw();
}
