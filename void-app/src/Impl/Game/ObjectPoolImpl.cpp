//
// Created by Dmitry Mozgin on 26/04/2017.
//

#include <iostream>
#include "ObjectPoolImpl.h"
#include "../Common/MeshImpl.h"
#include "cinder/gl/gl.h"

using namespace vd;
using namespace ci;

ObjectPoolImpl::ObjectPoolImpl(VoidApp &app)
        : VoidAppObject(app), _drawQueue(std::make_unique<DrawQueueImpl>()) {
}

IObjectPool::IDrawQueue *ObjectPoolImpl::GetDrawQueue() const {
    return _drawQueue.get();
}

void ObjectPoolImpl::Draw() {
    for ( auto q : _drawQueue->_queue) {
        if (!q->IsHidden()) {
            gl::pushMatrices();

            auto model = q->GetTransform()->GetModelMatrix();
            
            gl::setModelMatrix(mat4(
                    model.m11, model.m12, model.m13, model.m14,
                    model.m21, model.m22, model.m23, model.m24,
                    model.m31, model.m32, model.m33, model.m34,
                    model.m41, model.m42, model.m43, model.m44
            ));

            app.GetShader()->LoadModelMatrix();

            // Set a color.
            auto c = q->GetColor();
            app.GetShader()->SetMainColor(vec4(c.r, c.g, c.b, c.a));

            // Draw a mesh.
            auto mesh = dynamic_cast<MeshImpl*>(q->GetMesh().get());
            mesh->Draw(app);

            gl::popMatrices();
        }
    }
}

void ObjectPoolImpl::DrawQueueImpl::Insert(const VoidObject& object) {
    _queue.push_back(&object);
}

void ObjectPoolImpl::DrawQueueImpl::Remove(const VoidObject& object) {
    _queue.erase(
            std::find(
                    _queue.begin(),
                    _queue.end(),
                    &object
            ),
            _queue.end()
    );
}

ObjectPoolImpl::DrawQueueImpl::DrawQueueImpl() : _queue({}) {

}

