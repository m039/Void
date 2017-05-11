//
// Created by Dmitry Mozgin on 05/05/2017.
//

#pragma once

#include <string>
#include <memory>

#include "Color.h"

namespace vd {

class IShadersManager
{
public:

    virtual void SetGlobalShaderParameter(const std::string& name, float v) = 0;

    virtual void SetGlobalShaderParameter(const std::string& name, int v) = 0;

    virtual void SetGlobalShaderParameter(const std::string& name, const Color& v) = 0;

    virtual ~IShadersManager();

};

typedef std::shared_ptr<IShadersManager> IShadersManagerRef;

}
