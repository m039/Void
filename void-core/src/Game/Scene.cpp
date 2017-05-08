//
// Created by Dmitry Mozgin on 28/04/2017.
//

#include <Common/Time.h>

#include "Scene.h"
#include "Colors.h"

using namespace vd;

//region IScene

IScene::~IScene() {
}

//endregion

//region Scene

Scene::Scene(const ICameraRef& camera, const IShadersManagerRef& shaders)
        : _camera(camera),
          _fog(std::make_shared<Fog>(shaders)),
          _minFactor(0),
          _startPosition(0)
{
}

void Scene::SetBackgroundColor(const Color& color) {
    _camera->SetBackgroundColor(color);
    _fog->SetColor(color);
    _fog->SetMinFactor(0);
    _minFactor = 0;
    _startPosition = 0;
}

void Scene::OnStart() {
    GameComponent::OnStart();

    _fog->SetEnabled(_EnableFog);
    _fog->SetDensity(_FogDensity);
}

void Scene::OnUpdate() {
    GameComponent::OnUpdate();

    // Handle min factor.
    if (_minFactor < 1 && _FogDisappearTime > 0) {
        if (_fog->GetColor() == Colors::Black && _FogDisappearTimeOnBlack  > 0) {
            _minFactor += Time::GetDeltaTime() / _FogDisappearTimeOnBlack;
            _fog->SetMinFactor(MathF::SmoothStep(0, 1, MathF::Min(MathF::Pow(0.5f + _minFactor, _PowFactor), 1)));
        } else {
            _minFactor += Time::GetDeltaTime()  / _FogDisappearTime;
            _fog->SetMinFactor(MathF::SmoothStep(0, 1, _minFactor));
        }
    }

    // Handle start position.
    if (_startPosition < 1 && _FogDisappearVelocity  > 0) {
        _startPosition += Time::GetDeltaTime() ;
        _fog->SetStartPosition(MathF::SmoothStep(0, 1, _startPosition) * _FogDisappearVelocity);
    }
}

//endregion
