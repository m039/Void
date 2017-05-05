//
// Created by Dmitry Mozgin on 05/05/2017.
//

#pragma once

#include <Common/ShadersManager.h>

namespace vd {

class Fog {
public:

    Fog(const IShadersManagerRef& shadersManager);

    void SetColor(const Color& color);

    Color GetColor() const;

    void SetDensity(float density);

    float GetDensity() const;

    void SetStartPosition(float startPosition);

    float GetStartPosition() const;

    void SetEnabled(bool enable);

    bool IsEnabled() const;

    void SetMinFactor(float minFactor);

    float GetMinFactor() const;

private:

    const IShadersManagerRef _shaders;

    Color _color;

    float _density;

    float _startPosition;

    bool _enabled;

    float _minFactor;

};

typedef std::shared_ptr<Fog> FogRef;

}

