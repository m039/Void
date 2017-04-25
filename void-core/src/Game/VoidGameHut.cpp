//
// Created by Dmitry Mozgin on 25/04/2017.
//

#include "VoidGameHut.h"

using namespace vd;

VoidGameHut::VoidGameHut(
        const IMeshFactoryRef& meshFactory,
        IAudioPlayerRef& audioPlayer
)
        : GameHut(meshFactory)
{
    auto musicSystem = std::make_shared<MusicSystem>(audioPlayer);
    Components.push_back(musicSystem);
}
