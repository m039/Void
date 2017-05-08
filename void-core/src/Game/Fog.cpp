//
// Created by Dmitry Mozgin on 05/05/2017.
//

#include "Fog.h"

using namespace vd;

Fog::Fog(const IShadersManagerRef& shadersManager)
        : _shaders(shadersManager),
          _color(Color::Black),
          _density(0),
          _startPosition(0),
          _enabled(false),
          _minFactor(0)
{
}

void Fog::SetColor(const Color& color) {
    _shaders->SetGlobalShaderParameter("_FogColor", color);
    _color = color;
}

Color Fog::GetColor() const {
    return _color;
}

void Fog::SetDensity(float density) {
    _shaders->SetGlobalShaderParameter("_FogDensity", density);
    _density = density;
}

float Fog::GetDensity() const {
    return _density;
}

void Fog::SetStartPosition(float startPosition) {
    _shaders->SetGlobalShaderParameter("_FogStartPosition", startPosition);
    _startPosition = startPosition;
}

float Fog::GetStartPosition() const {
    return _startPosition;
}

void Fog::SetEnabled(bool enable) {
    _shaders->SetGlobalShaderParameter("_FogEnabled", enable ? 1 : 0);
    _enabled = enable;
}

bool Fog::IsEnabled() const {
    return _enabled;
}

void Fog::SetMinFactor(float minFactor) {
    _shaders->SetGlobalShaderParameter("_MinFogFactor", minFactor);
    _minFactor = minFactor;
}

float Fog::GetMinFactor() const {
    return _minFactor;
}
