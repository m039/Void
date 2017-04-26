//
// Created by Dmitry Mozgin on 25/04/2017.
//

#pragma once

#include <vector>
#include "VoidTrackObject.h"
#include "VoidObject.h"

namespace vd {

class IObjectPool {
public:

    IObjectPool() {}

    //! Initialization. For example, use this method to precreate objects.
    virtual void Init() = 0;

    virtual IVoidTrackObjectRef GetObject() = 0;

    virtual void PutObject(IVoidTrackObjectRef object) = 0;

    virtual void PutObjects(std::vector<IVoidTrackObjectRef> objects) = 0;

    virtual ~IObjectPool() {}

};

class IDrawableObjectPool : public virtual IObjectPool {
public:

    virtual void InsertInDrawQueue(const VoidObject& object) = 0;

    virtual void RemoveFromDrawQueue(const VoidObject& object) = 0;

    virtual ~IDrawableObjectPool() {}

};

class ObjectPool : public virtual IObjectPool {
public:

    ObjectPool();

    //region Implementation of IObjectPool.

    virtual void Init() override;

    virtual IVoidTrackObjectRef GetObject() override;

    virtual void PutObject(IVoidTrackObjectRef object) override;

    virtual void PutObjects(std::vector<IVoidTrackObjectRef> objects) override;

    //endregion

private:

    static const int NumberOfPrecreatedObject = 100;

    static const std::string DefaultObjectsName;

    std::vector<IVoidTrackObjectRef> _freeObjects;

    const IVoidTrackObjectRef CreateObject();

    void PrecreateObjects();

    static void SetDefaults(const IVoidTrackObjectRef& object);
};

typedef std::shared_ptr<IObjectPool> IObjectPoolRef;

}
