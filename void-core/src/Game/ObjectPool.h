//
// Created by Dmitry Mozgin on 25/04/2017.
//

#pragma once

#include <vector>
#include "VoidTrackObject.h"

namespace vd {

class IObjectPool {
public:

    class IDrawQueue {

    public:

        //! Insert the object into drawing queue.
        virtual void Insert(const VoidObject& object) = 0;

        //! Remove the object from the drawing queue.
        virtual void Remove(const VoidObject& object) = 0;

        ~IDrawQueue() {}

    };

    IObjectPool() {}

    //! Initialization. For example, use this method to precreate objects.
    virtual void Init() = 0;

    //! Returns an object from a cache, the returned object is hidden (or invisible to a scene).
    virtual IVoidTrackObjectRef GetObject() = 0;

    virtual void PutObject(const IVoidTrackObjectRef& object) = 0;

    virtual void PutObjects(const std::vector<IVoidTrackObjectRef>& objects) = 0;

    //! Returns DrawQueue, it may be null if pool doesn't provide it.
    virtual IDrawQueue* GetDrawQueue() const {
        return nullptr;
    }

    virtual ~IObjectPool() {}

};

class ObjectPool : public virtual IObjectPool {
public:

    ObjectPool();

    //region Implementation of IObjectPool.

    virtual void Init() override;

    virtual IVoidTrackObjectRef GetObject() override;

    virtual void PutObject(const IVoidTrackObjectRef& object) override;

    virtual void PutObjects(const std::vector<IVoidTrackObjectRef>& objects) override;

    //endregion

private:

    static const int NumberOfPrecreatedObject = 100;

    static const std::string DefaultObjectsName;

    std::vector<IVoidTrackObjectRef> _freeObjects;

    const IVoidTrackObjectRef CreateObject();

    static void SetDefaults(const IVoidTrackObjectRef& object);

};

typedef std::shared_ptr<IObjectPool> IObjectPoolRef;

}
