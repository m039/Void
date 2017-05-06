//
// Created by Dmitry Mozgin on 25/04/2017.
//

#include <Game/MeshGenerators/MeshGenerator.h>
#include <Game/Screens/TryAgainScreen.h>
#include <Game/Screens/MovementHelpScreen.h>
#include <Game/Screens/IntroScreen.h>

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
        const IShadersManagerRef& shaders,
        const ISimplifiedUiRef& ui
)
        : GameHut(gameContext, meshFactory),
          _ui(ui),
          _drawables({})
{
    objectPool->Init();

    auto player = std::make_shared<Player>(camera);
    Components.push_back(player);

    auto musicSystem = std::make_shared<MusicSystem>(audioPlayer);
    Components.push_back(musicSystem);

    auto scene = std::make_shared<Scene>(camera, shaders);
    Components.push_back(scene);

    auto inputSystem = std::make_shared<InputSystem>(input);
    Components.push_back(inputSystem);

    auto tryAgainScreen = std::make_shared<TryAgainScreen>();
    Components.push_back(tryAgainScreen);

    auto introScreen = std::make_shared<IntroScreen>();
    Components.push_back(introScreen);

    auto movementHelpScreen = std::make_shared<MovementHelpScreen>();
    Components.push_back(movementHelpScreen);

    auto game = std::make_shared<Game>(
            objectPool,
            player,
            musicSystem,
            inputSystem,
            scene,
            tryAgainScreen,
            introScreen,
            movementHelpScreen
    );
    Components.push_back(game);

    // Register UI callbacks.

    _drawables.push_back(tryAgainScreen);
    _drawables.push_back(introScreen);
    _drawables.push_back(movementHelpScreen);

    for (auto& d: _drawables) {
        _ui->Register(d);
    }
}

VoidGameHut::~VoidGameHut() {
    // Unregister UI callbacks.

    for (auto& d: _drawables) {
        _ui->Unregister(d);
    }
}
