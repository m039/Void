//
// Created by Dmitry Mozgin on 05/05/2017.
//

#include "ShadersManagerImpl.h"

#include "../../VoidApp.h"

using namespace vd;

ShadersManagerImpl::ShadersManagerImpl(VoidApp& app) : VoidAppObject(app) {
}

void ShadersManagerImpl::SetGlobalShaderParameter(const std::string& name, float v) {
    auto shader = app.getShader();
    auto location = shader->GetLocation("c" + name);
    if (location != -1) {
        shader->GetInternalShader()->uniform(location, v);
    }
}

void ShadersManagerImpl::SetGlobalShaderParameter(const std::string& name, int v) {
    auto shader = app.getShader();
    auto location = shader->GetLocation("c" + name);
    if (location != -1) {
        shader->GetInternalShader()->uniform(location, v);
    }
}

void ShadersManagerImpl::SetGlobalShaderParameter(const std::string& name, const Color& v) {
    auto shader = app.getShader();
    auto location = shader->GetLocation("c" + name);
    if (location != -1) {
        shader->GetInternalShader()->uniform(location, ci::vec4(v.r, v.g, v.b, v.a));
    }
}
