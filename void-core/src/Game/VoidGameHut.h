//
// Created by Dmitry Mozgin on 25/04/2017.
//

#pragma once

#include <Common/Components/Camera.h>
#include <Common/Input.h>
#include <Common/ShadersManager.h>
#include <Common/GameHut.h>
#include <Common/Mesh.h>

#include "MusicSystem.h"
#include "ObjectPool.h"
#include "SimplifiedUi.h"

namespace vd {

class VoidGameHut : public GameHut {

public:

    VoidGameHut(
            const IGameContextRef& gameContext,
            const IMeshFactoryRef& meshFactory,
            const IAudioPlayerRef& audioPlayer,
            const IObjectPoolRef& objectPool,
            const ICameraRef& camera,
            const IInputRef& input,
            const IShadersManagerRef& shaders,
            const ISimplifiedUiRef& ui
    );

    virtual ~VoidGameHut();

private:

    const ISimplifiedUiRef _ui;

    std::vector<IScreenDrawableRef> _drawables;

};

}

