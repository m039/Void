//
// Created by Dmitry Mozgin on 28/04/2017.
//

#pragma once

#include <Common/Components/Transform.h>
#include <Common/Color.h>
#include <Common/Components/ICamera.h>
#include <cinder/Camera.h>
#include "../../VoidAppObject.h"

namespace vd {

class Camera :
        public VoidAppObject,
        public ICamera {

public:

    Camera(VoidApp &app);

    virtual const ITransformRef GetTransform() const override;

    virtual void SetNearClipPlane(float nearClipPlane) override;

    virtual float GetNearClipPlane() const override;

    virtual void SetBackgroundColor(const Color &color) override;

    virtual Color GetBackgroundColor() const override;

    //! Set up the object with the last defaults.
    void Setup();

    //! Set up OpenGL matrices: it sets projection and view matrices.
    void LoadMatrices();

    ~Camera();

private:

    ci::CameraPersp _camera;

    float _nearClipPlane;

    Color _backgroundColor;

    ITransformRef _transform;

};

class CameraTransform : public Transform {
public:

    CameraTransform(Camera& camera);

    //region Transform's overrides.

    virtual void SetPosition(const Vector3& position) override;

    //endregion

private:

    Camera& _camera;
};

}