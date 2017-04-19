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

    _mainColorLocation = _shader->getUniformLocation("cMainColor");
    _fogEnabledLocation = _shader->getUniformLocation("c_FogEnabled");
    _fogStartPositionLocation = _shader->getUniformLocation("c_FogStartPosition");
    _fogDensityLocation = _shader->getUniformLocation("c_FogDensity");
    _fogColorLocation = _shader->getUniformLocation("c_FogColor");
    _minFogFactorLocation = _shader->getUniformLocation("c_MinFogFactor");
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
