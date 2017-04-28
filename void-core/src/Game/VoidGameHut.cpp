//
// Created by Dmitry Mozgin on 25/04/2017.
//

#include <Game/MeshGenerators/MeshGenerator.h>

#include "VoidGameHut.h"

using namespace vd;

VoidGameHut::VoidGameHut(
        const IMeshFactoryRef& meshFactory,
        const IAudioPlayerRef& audioPlayer,
        const IObjectPoolRef& objectPool
)
        : GameHut(meshFactory)
{
    auto musicSystem = std::make_shared<MusicSystem>(audioPlayer);
    Components.push_back(musicSystem);

    _objectPool = objectPool;
    _objectPool->Init();
}

void VoidGameHut::Start() {
    GameHut::Start();

    _object = _objectPool->GetObject();
    _object->SetShapeType(ShapeType::Square);
    _object->SetHollow(true);
//    _object->SetColor(Color::Blue);
//    _object->GetTransform()->SetPosition(Vector3(0, 0, -4));
//    _object->GetTransform()->SetLocaleScale(Vector3(0.3f, 0.3f, 0.3f));
    _object->Show();
}
