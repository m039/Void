//
// Created by Dmitry Mozgin on 25/04/2017.
//

#pragma once

#include "MusicSystem.h"
#include "Common/GameHut.h"
#include "Common/Mesh.h"

namespace vd {

class VoidGameHut : public GameHut {

public:

    VoidGameHut(
            const IMeshFactoryRef& meshFactory,
            IAudioPlayerRef& audioPlayer
    );

};

}

