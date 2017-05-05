//
// Created by Dmitry Mozgin on 04/05/2017.
//

#include "GameContext.h"

using namespace vd;

//region IGameContext

IGameContext::~IGameContext() {
}

//endregion

//region GameContext

RuntimePlatform GameContext::GetRuntimePlatform() {
    return vd::internal::GameContext::_Context->GetRuntimePlatform();
}

bool GameContext::IsMobilePlatform() {
    auto platform = GetRuntimePlatform();
    return platform == RuntimePlatform::Android || platform == RuntimePlatform::iPhone;
}

float GameContext::GetScreenDpi() {
    return vd::internal::GameContext::_Context->GetScreenDpi();
}

void GameContext::Quit() {
    vd::internal::GameContext::_Context->Quit();
}

//endregion

//region internal::GameContext

IGameContextRef vd::internal::GameContext::_Context = nullptr;


void internal::GameContext::RegisterGameContext(const IGameContextRef& context) {
    _Context = context;
}

//endregion
