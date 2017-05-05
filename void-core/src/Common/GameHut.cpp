//
// Created by Dmitry Mozgin on 24/04/2017.
//

#include <Common/Time.h>

#include "GameHut.h"
#include "GameContext.h"

using namespace vd;

GameHut::GameHut(
        const IGameContextRef& gameContext,
        const IMeshFactoryRef& meshFactory
) {
    vd::internal::GameContext::RegisterGameContext(gameContext);
    vd::internal::Mesh::RegisterMeshFactory(meshFactory);
}

void GameHut::Start() {
    Time::Update();

    for (auto& c: Components) {
        c->Start();
    }
}

void GameHut::Update() {
    Time::Update();

    for (auto& c: Components) {
        c->Update();
    }
}

GameHut::~GameHut() {
    vd::internal::Mesh::RegisterMeshFactory(nullptr);
    vd::internal::GameContext::RegisterGameContext(nullptr);
}

