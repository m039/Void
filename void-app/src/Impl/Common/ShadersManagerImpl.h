//
// Created by Dmitry Mozgin on 05/05/2017.
//

#pragma once

#include <Common/ShadersManager.h>
#include "../../VoidAppObject.h"

namespace vd {

class ShadersManagerImpl
        : public VoidAppObject,
          public IShadersManager {
public:

    ShadersManagerImpl(VoidApp &app);

    virtual void SetGlobalShaderParameter(const std::string& name, float v) override;

    virtual void SetGlobalShaderParameter(const std::string& name, int v) override;

    virtual void SetGlobalShaderParameter(const std::string& name, const Color& v) override;

};

}
