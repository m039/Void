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
    _camera->GetTransform()->SetPosition(Vector3(0, 0, 0));

    _object = _objectPool->GetObject();
    _object->SetShapeType(ShapeType::Square);
    _object->GetTransform()->SetPosition(Vector3(0, 0, 20));
    _object->SetHollow(true);
    _object->Show();

    auto track = std::make_shared<VoidTrack>(1, 1);

    auto game = std::make_shared<Game>(nullptr, nullptr, nullptr, nullptr, nullptr);

    player->MoveToTrack(track);
}

void VoidGameHut::Start() {
    GameHut::Start();

}
