//
// Created by Dmitry Mozgin on 26/04/2017.
//

#include <iostream>
#include "ObjectPoolGl.h"
#include "../Common/MeshGl.h"

using namespace vd;

ObjectPoolGl::ObjectPoolGl() : _drawQueue(std::make_unique<DrawQueueGl>()) {
}

IObjectPool::IDrawQueue *ObjectPoolGl::GetDrawQueue() const {
    return _drawQueue.get();
}

void ObjectPoolGl::Draw() {
    for ( auto q : _drawQueue->_queue) {
        if (!q->IsHidden()) {
            auto mesh = dynamic_cast<MeshGl*>(q->GetMesh().get());
            mesh->Draw();
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

