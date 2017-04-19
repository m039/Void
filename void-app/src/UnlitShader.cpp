//
// Created by Dmitry Mozgin on 19/04/2017.
//

#include "UnlitShader.h"

using namespace ci;

UnlitShader::UnlitShader(const ci::app::App &app) {
    setupShader(app);
}

void UnlitShader::setupShader(const ci::app::App &app) {
    ci::app::App& cApp = const_cast<ci::app::App&>(app);

    auto format = gl::GlslProg::Format()
            .vertex(cApp.loadAsset("Unlit.vert"))
            .fragment(cApp.loadAsset("Unlit.frag"));

    _shader = gl::GlslProg::create(format);

    std::unordered_map<GLint*, std::string> pairs {
            { &_mainColorLocation, "cMainColor" },
            { &_fogEnabledLocation, "c_FogEnabled" },
            { &_fogStartPositionLocation, "c_FogStartPosition" },
            { &_fogDensityLocation, "c_FogDensity" },
            { &_fogColorLocation, "c_FogColor" },
            { &_minFogFactorLocation, "c_MinFogFactor" },
            { &_modelLocation, "cModel" },
            { &_viewLocation, "cView" },
            { &_projViewLocation, "cProjView" }
    };

    for (const auto& p: pairs) {
        *p.first = _shader->getUniformLocation(p.second);
    }
}

void UnlitShader::SetMatrices(const ci::Camera &camera) {
    const auto &model = gl::getModelMatrix();
    const auto &view = camera.getViewMatrix();
    const auto &proj = camera.getProjectionMatrix();
    auto projView = proj * view;

    _shader->uniform(_modelLocation, model);
    _shader->uniform(_viewLocation, view);
    _shader->uniform(_projViewLocation, projView);
}

void UnlitShader::SetMainColor(const ci::ColorAf &color) {
    _shader->uniform(_mainColorLocation, color);
}

void UnlitShader::SetFogEnabled(bool value) {
    _shader->uniform(_fogEnabledLocation, value? 1 : 0);
}

void UnlitShader::SetFogStartPosition(float startPosition) {
    _shader->uniform(_fogStartPositionLocation, startPosition);
}

void UnlitShader::SetFogDensity(float density) {
    _shader->uniform(_fogDensityLocation, density);
}

void UnlitShader::SetFogColor(const ci::ColorAf &color) {
    _shader->uniform(_fogColorLocation, color);
}

void UnlitShader::SetMinFogFactor(float minFogFactor) {
    _shader->uniform(_minFogFactorLocation, minFogFactor);
}
