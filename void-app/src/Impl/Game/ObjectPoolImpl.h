//
// Created by Dmitry Mozgin on 26/04/2017.
//

#pragma once

#include <Game/ObjectPool.h>
#include "../../VoidAppObject.h"

namespace vd {

class VoidApp;

class ObjectPoolImpl :
        public VoidAppObject,
        public ObjectPool
{
    class DrawQueueImpl : public IDrawQueue {
        friend ObjectPoolImpl;

    public:

        DrawQueueImpl();

        virtual void Insert(const VoidObject& object) override;

        virtual void Remove(const VoidObject& object) override;

    private:

        /**
         * Warning:
         *
         * Raw pointers, no way to determine if an object is deleted or not:
         * - It should be ok for the current game.
         * - Not suitable for a multithreaded environment.
         */
        std::vector<const VoidObject*> _queue;
    };

public:

    ObjectPoolImpl(VoidApp &app);

    virtual IDrawQueue* GetDrawQueue() const override;

    void Draw();

private:

    const std::unique_ptr<DrawQueueImpl> _drawQueue;

};

}

