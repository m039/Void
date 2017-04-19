//
// Created by Dmitry Mozgin on 19/04/2017.
//

#pragma once

#include "cinder/app/App.h"
#include "cinder/gl/gl.h"

class UnlitShader {

public:

    UnlitShader(const ci::app::App &app);

    ci::gl::GlslProgRef GetShader() const {
        return _shader;
    }

    void SetMatrices(const ci::Camera &camera);

    void SetMainColor(const ci::ColorAf &color);

    void SetFogEnabled(bool value);

    void SetFogStartPosition(float startPosition);

    void SetFogDensity(float density);

    void SetFogColor(const ci::ColorAf &color);

    void SetMinFogFactor(float minFogFactor);

    operator const ci::gl::GlslProgRef&() {
        return _shader;
    }

private:
    ci::gl::GlslProgRef _shader;

    GLint _mainColorLocation;

    GLint _fogEnabledLocation;

    GLint _fogStartPositionLocation;

    GLint _fogDensityLocation;

    GLint _fogColorLocation;

    GLint _minFogFactorLocation;

    GLint _modelLocation;

    GLint _viewLocation;

    GLint _projViewLocation;

    void setupShader(const ci::app::App &app);
};




