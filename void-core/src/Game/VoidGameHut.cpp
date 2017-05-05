//
// Created by Dmitry Mozgin on 25/04/2017.
//

#include <Game/MeshGenerators/MeshGenerator.h>

#include "VoidGameHut.h"
#include "Player.h"
#include "Game.h"

using namespace vd;

VoidGameHut::VoidGameHut(
        const IGameContextRef& gameContext,
        const IMeshFactoryRef& meshFactory,
        const IAudioPlayerRef& audioPlayer,
        const IObjectPoolRef& objectPool,
        const ICameraRef& camera,
        const IInputRef& input,
        const IShadersManagerRef& shaders
)
        : GameHut(gameContext, meshFactory)
{
    _objectPool = objectPool;
    _objectPool->Init();

    auto musicSystem = std::make_shared<MusicSystem>(audioPlayer);
    Components.push_back(musicSystem);

    auto player = std::make_shared<Player>(camera);
    Components.push_back(player);

    auto scene = std::make_shared<Scene>(camera, shaders);
    Components.push_back(scene);

    auto inputSystem = std::make_shared<InputSystem>(input);
    Components.push_back(inputSystem);

    auto game = std::make_shared<Game>(_objectPool, player, musicSystem, inputSystem, scene);
    Components.push_back(game);
}

void VoidGameHut::Start() {
    GameHut::Start();

}
