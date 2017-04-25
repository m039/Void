//
// Created by Dmitry Mozgin on 25/04/2017.
//

#pragma once

#include "Common/GameHut.h"
#include "Common/Mesh.h"

#include "MusicSystem.h"

namespace vd {

class VoidGameHut : public GameHut {

public:

    VoidGameHut(
            const IMeshFactoryRef& meshFactory,
            IAudioPlayerRef& audioPlayer
    );

    // Todo: remove temporary code.
    virtual void Start() override;

private:

    // Todo: remove temporary code.
    IMeshRef _mesh;

};

}

