//
// Created by Dmitry Mozgin on 25/04/2017.
//

#include <Game/MeshGenerators/MeshGenerator.h>

#include "VoidGameHut.h"
#include "Player.h"
#include "Game.h"

using namespace vd;

VoidGameHut::VoidGameHut(
        const IMeshFactoryRef& meshFactory,
        const IAudioPlayerRef& audioPlayer,
        const IObjectPoolRef& objectPool,
        const ICameraRef& camera
)
        : GameHut(meshFactory)
{
    _objectPool = objectPool;
    _objectPool->Init();

    auto musicSystem = std::make_shared<MusicSystem>(audioPlayer);
    Components.push_back(musicSystem);

    auto player = std::make_shared<Player>(camera);
    Components.push_back(player);

    _camera = camera;
    _camera->GetTransform()->SetPosition(Vector3(0, 0, 6));
    _camera->SetBackgroundColor(Color::Black);

    auto game = std::make_shared<Game>(_objectPool, player, musicSystem, nullptr, nullptr);
    Components.push_back(game);
}

void VoidGameHut::Start() {
    GameHut::Start();

}
