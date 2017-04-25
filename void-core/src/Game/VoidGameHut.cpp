//
// Created by Dmitry Mozgin on 25/04/2017.
//

#include <Game/MeshGenerators/MeshGenerator.h>

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

void VoidGameHut::Start() {
    GameHut::Start();

    _mesh = MeshGenerator::Generate(Triangle, false);

    auto a = 12;
}
