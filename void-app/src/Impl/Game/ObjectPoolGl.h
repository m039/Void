//
// Created by Dmitry Mozgin on 26/04/2017.
//

#pragma once

#include <Game/ObjectPool.h>

namespace vd {

class VoidApp;

class ObjectPoolGl : public ObjectPool {
    class DrawQueueGl : public IDrawQueue {
        friend ObjectPoolGl;

    public:

        DrawQueueGl();

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

    ObjectPoolGl();

    virtual IDrawQueue* GetDrawQueue() const override;

    void Draw(const VoidApp& app);

private:

    const std::unique_ptr<DrawQueueGl> _drawQueue;

};

}

