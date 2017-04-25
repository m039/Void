//
// Created by Dmitry Mozgin on 24/04/2017.
//

#include <Common/Time.h>

#include "GameHut.h"

using namespace vd;

GameHut::GameHut(const IMeshFactoryRef& meshFactory) {
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

