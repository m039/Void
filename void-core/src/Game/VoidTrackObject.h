//
// Created by Dmitry Mozgin on 25/04/2017.
//

#pragma once

#include <memory>
#include "VoidObject.h"
#include "ShapeType.h"

namespace vd {

class IVoidTrackObject : public virtual IVoidObject
{
public:

    virtual void SetRotation(float angle) = 0;

    virtual void Rotate(float angle) = 0;

    virtual const std::string& GetTag() const = 0;

    virtual void SetTag(const std::string& tag) = 0;

    virtual bool IsHollow() const = 0;

    virtual void SetHollow(bool hollow) = 0;

    virtual ShapeType GetShapeType() const = 0;

    virtual void SetShapeType(ShapeType type) = 0;

    virtual void SetAnimation(const AnimationRef& animation) = 0;

    virtual AnimationRef GetAnimation() = 0;

};

class VoidTrackObject
        : public VoidObject,
          public IVoidTrackObject
{
public:

    VoidTrackObject(IObjectPool& pool, const std::string& name);

    VoidTrackObject(IObjectPool& pool, const std::string& name, ShapeType shapeType, bool isHollow = false);

    //region Implementation of IVoidTrackObject.

    virtual void SetRotation(float angle) override;

    virtual void Rotate(float angle) override;

    virtual const std::string& GetTag() const override;

    virtual void SetTag(const std::string& tag) override;

    virtual bool IsHollow() const override;

    virtual void SetHollow(bool hollow) override;

    virtual ShapeType GetShapeType() const override;

    virtual void SetShapeType(ShapeType type) override;

    void SetAnimation(const AnimationRef& animation) override;

    AnimationRef GetAnimation() override;

    //endregion

private:

    std::string _tag;

    ShapeType _shapeType;

    bool _isHollow;

    AnimationRef _animation;

    void RegenerateMesh(ShapeType shapeType, bool isHollow);

};

typedef std::shared_ptr<IVoidTrackObject> IVoidTrackObjectRef;

}