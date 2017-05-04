//
// Created by Dmitry Mozgin on 26/04/2017.
//

#include <iostream>
#include "ObjectPoolGl.h"
#include "../Common/MeshGl.h"
#include "cinder/gl/gl.h"

using namespace vd;
using namespace ci;

ObjectPoolGl::ObjectPoolGl(VoidApp &app)
        : VoidAppObject(app), _drawQueue(std::make_unique<DrawQueueGl>()) {
}

IObjectPool::IDrawQueue *ObjectPoolGl::GetDrawQueue() const {
    return _drawQueue.get();
}

void ObjectPoolGl::Draw() {
    for ( auto q : _drawQueue->_queue) {
        if (!q->IsHidden()) {
            gl::pushMatrices();

            auto tr = q->GetTransform();

            // Note: for OpenGL matrices should be applied in reverse order.

            // Set a position.
            auto p = tr->GetPosition();
            gl::translate(vec3(p.x, p.y, p.z));

            // Set a localScale.
            auto s = tr->GetLocalScale();
            gl::scale(s.x, s.y, s.z);

            app.getShader()->LoadModelMatrix();

            // Set a color.
            auto c = q->GetColor();
            app.getShader()->SetMainColor(vec4(c.r, c.g, c.b, c.a));

            // Draw a mesh.
            auto mesh = dynamic_cast<MeshGl*>(q->GetMesh().get());
            mesh->Draw(app);

            gl::popMatrices();
        }
    }
}

void ObjectPoolGl::DrawQueueGl::Insert(const VoidObject& object) {
    _queue.push_back(&object);
}

void ObjectPoolGl::DrawQueueGl::Remove(const VoidObject& object) {
    _queue.erase(
            std::find(
                    _queue.begin(),
                    _queue.end(),
                    &object
            ),
            _queue.end()
    );
}

ObjectPoolGl::DrawQueueGl::DrawQueueGl() : _queue({}) {

}

