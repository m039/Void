//
// Created by Dmitry Mozgin on 19/04/2017.
//

#pragma once

#include "cinder/app/App.h"
#include "cinder/gl/gl.h"

namespace vd {

class UnlitShader {

public:

    UnlitShader(const ci::app::App &app);

    ci::gl::GlslProgRef GetInternalShader() const {
        return _shader;
    }

    //! Takes an OpenGL model matrix and sets it to the internal shader.
    void LoadModelMatrix();

    void SetMatrices(const ci::Camera &camera);

    void SetMainColor(const ci::ColorAf &color);

    int GetLocation(const std::string& name);

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

    std::unordered_map<std::string, GLint*> _nameToLocation;

    void setupShader(const ci::app::App &app);
};

typedef std::shared_ptr<UnlitShader> UnlitShaderRef;

}



