//
// Created by Dmitry Mozgin on 24/04/2017.
//

#include "GameComponent.h"

using namespace vd;

//region IGameComponent

IGameComponent::~IGameComponent() {
}

//endregion

//region GameComponent

void GameComponent::Start() {
    OnStart();
}

void GameComponent::Update() {
    _coroutineManager.Update();

    OnUpdate();
}

//endregion

