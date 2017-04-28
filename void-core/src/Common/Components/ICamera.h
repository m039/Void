//
// Created by Dmitry Mozgin on 28/04/2017.
//

#pragma once

#include <Common/Color.h>
#include <memory>
#include "Transform.h"

namespace vd {

class ICamera {

public:

    virtual const ITransformRef GetTransform() const = 0;

    virtual void SetNearClipPlane(float nearClipPlane) = 0;

    virtual float GetNearClipPlane() const = 0;

    virtual void SetBackgroundColor(const Color& color) = 0;

    virtual Color GetBackgroundColor() const = 0;

    virtual ~ICamera() {}

};

typedef std::shared_ptr<ICamera> ICameraRef;

}