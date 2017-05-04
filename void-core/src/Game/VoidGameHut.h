//
// Created by Dmitry Mozgin on 25/04/2017.
//

#pragma once

#include <Common/Components/ICamera.h>
#include <Common/Input.h>
#include "Common/GameHut.h"
#include "Common/Mesh.h"

#include "MusicSystem.h"
#include "ObjectPool.h"

namespace vd {

class VoidGameHut : public GameHut {

public:

    VoidGameHut(
            const IMeshFactoryRef& meshFactory,
            const IAudioPlayerRef& audioPlayer,
            const IObjectPoolRef& objectPool,
            const ICameraRef& camera,
            const IInputRef& input
    );

    //region Implementation of GameHut

    // Todo: remove temporary code.
    virtual void Start() override;

    //endregion

private:

    // Todo: remove temporary code.
    IObjectPoolRef _objectPool;

    // Todo: remove temporary code.
    IVoidTrackObjectRef _object;

    // Todo: remove temporary code.
    ICameraRef _camera;

};

}

