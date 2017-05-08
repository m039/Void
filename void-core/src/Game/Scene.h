//
// Created by Dmitry Mozgin on 28/04/2017.
//

#pragma once

#include <memory>

#include <Common/Components/GameComponent.h>
#include <Common/Components/Camera.h>
#include <Common/ShadersManager.h>

#include "Fog.h"

namespace vd {

class IScene {
public:

    virtual void SetBackgroundColor(const Color& color) = 0;

    virtual ~IScene();
};

typedef std::shared_ptr<IScene> ISceneRef;

class Scene
        : public GameComponent,
          public IScene
{
public:

    Scene(const ICameraRef& camera, const IShadersManagerRef& shaders);

    //region GameComponent's overrides.

    virtual void OnStart() override;

    virtual void OnUpdate() override;

    //endregion

    //region Implementation of IScene.

    virtual void SetBackgroundColor(const Color& color) override;

    //endregion

private:

    //region Default constants.

    static constexpr bool _EnableFog = true;

    static constexpr float _PowFactor = 2.0f;

    static constexpr float _FogDensity = 0.2f;

    static constexpr float _FogDisappearTime = 1.5f; // 0 to disable

    static constexpr float _FogDisappearTimeOnBlack = 0.5f; // 0 to disable

    static constexpr float _FogDisappearVelocity = 0.0f; // 0 to disable

    //endregion

    const ICameraRef _camera;

    const FogRef _fog;

    float _minFactor;

    float _startPosition;

};

}

