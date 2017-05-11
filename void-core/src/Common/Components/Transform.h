//
// Created by Dmitry Mozgin on 26/04/2017.
//

#pragma once

#include <memory>

#include <Common/Vector3.h>
#include <Common/Matrix4.h>

namespace vd {

class ITransform {
public:

    virtual const Vector3 GetLocalScale() const = 0;

    virtual void SetLocaleScale(const Vector3& scale) = 0;

    virtual const Vector3 GetPosition() const = 0;

    virtual void SetPosition(const Vector3& position) = 0;

    virtual Quaternion GetRotation() const = 0;

    virtual void SetRotation(const Quaternion& quaternion) = 0;

    virtual Matrix4 GetModelMatrix() = 0;

    virtual ~ITransform();

};

typedef std::shared_ptr<ITransform> ITransformRef;

class Transform : public ITransform {
public:

    Transform();

    //region Implementation of ITransform.

    virtual const Vector3 GetLocalScale() const override;

    virtual void SetLocaleScale(const Vector3& scale) override;

    virtual const Vector3 GetPosition() const override;

    virtual void SetPosition(const Vector3& position) override;

    virtual Quaternion GetRotation() const override;

    virtual void SetRotation(const Quaternion& quaternion) override;

    virtual Matrix4 GetModelMatrix() override;

    //endregion

private:

    Vector3 _localScale;

    Vector3 _position;

    Quaternion _rotation;

    bool _translationIsDirty;

    bool _scaleIsDirty;

    bool _rotationIsDirty;

    Matrix4 _modelMatrix;

};

}
