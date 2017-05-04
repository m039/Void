//
// Created by Dmitry Mozgin on 04/05/2017.
//

#include "GameContext.h"

using namespace vd;

IGameContextRef vd::internal::GameContext::_Context = nullptr;

IGameContext::~IGameContext() {
}

void internal::GameContext::RegisterGameContext(const IGameContextRef& context) {
    _Context = context;
}

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
