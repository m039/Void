//
// Created by Dmitry Mozgin on 19/04/2017.
//

#include "UnlitShader.h"

using namespace ci;
using namespace vd;

UnlitShader::UnlitShader(const ci::app::App &app) {
    setupShader(app);
}

const std::string _ShaderFolder = "Shaders/";

#if defined( CINDER_GL_ES )
const std::string _VertixShaderFilename = _ShaderFolder + "UnlitEs2.vert";
const std::string _FragmentShaderFilename = _ShaderFolder + "UnlitEs2.frag";
#else
const std::string _VertixShaderFilename = _ShaderFolder + "Unlit.vert";
const std::string _FragmentShaderFilename = _ShaderFolder + "Unlit.frag";
#endif

void UnlitShader::setupShader(const ci::app::App &app) {
    ci::app::App& cApp = const_cast<ci::app::App&>(app);

    auto format = gl::GlslProg::Format()
            .vertex(cApp.loadAsset(_VertixShaderFilename))
            .fragment(cApp.loadAsset(_FragmentShaderFilename));

    _shader = gl::GlslProg::create(format);

    // Get uniform variable locations.

    _nameToLocation = std::unordered_map<std::string, GLint*> {
            { "cMainColor", &_mainColorLocation },
            { "c_FogEnabled", &_fogEnabledLocation },
            { "c_FogStartPosition", &_fogStartPositionLocation },
            { "c_FogDensity", &_fogDensityLocation },
            { "c_FogColor", &_fogColorLocation },
            { "c_MinFogFactor", &_minFogFactorLocation },
            { "cModel", &_modelLocation },
            { "cView", &_viewLocation  },
            { "cProjView", &_projViewLocation }
    };

    for (const auto& p: _nameToLocation) {
        *p.second = _shader->getUniformLocation(p.first);
    }
}

void UnlitShader::LoadModelMatrix() {
    const auto &model = gl::getModelMatrix();

    _shader->uniform(_modelLocation, model);
}

void UnlitShader::SetMatrices(const ci::Camera &camera) {
    auto view = camera.getViewMatrix();
    const auto &proj = camera.getProjectionMatrix();

    // The game uses left-handed coordinates, but OpenGL is right-handed.
    view = view * ci::mat4(
            -1, 0, 0, 0,
            0, 1, 0, 0,
            0, 0, 1, 0,
            0, 0, 0, 1);

    auto projView = proj * view;

    _shader->uniform(_viewLocation, view);
    _shader->uniform(_projViewLocation, projView);
}

void UnlitShader::SetMainColor(const ci::ColorAf &color) {
    _shader->uniform(_mainColorLocation, color);
}

int UnlitShader::GetLocation(const std::string& name) {
    auto location = _nameToLocation.find(name);
    if (location != _nameToLocation.end()) {
        return *_nameToLocation[name];
    }

    return -1;
}
