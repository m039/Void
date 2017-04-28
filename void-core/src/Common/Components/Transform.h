//
// Created by Dmitry Mozgin on 26/04/2017.
//

#pragma once

#include <Common/Vector3.h>

namespace vd {

class ITransform {
public:

    virtual const Vector3 GetLocalScale() const = 0;

    virtual void SetLocaleScale(const Vector3& scale) = 0;

    virtual const Vector3 GetPosition() const = 0;

    virtual void SetPosition(const Vector3& position) = 0;

    /*!
     * Rotates the object.
     *
     * \param xAngle X angle in degrees.
     * \param yAngle Y angle in degrees.
     * \param zAngle Z angle in degrees.
     */
    virtual void Rotate(float xAngle, float yAngle, float zAngle) = 0;

    ~ITransform() {}
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

    virtual void Rotate(float xAngle, float yAngle, float zAngle) override;

    //endregion

private:

    Vector3 _localScale;

    Vector3 _position;
};

}