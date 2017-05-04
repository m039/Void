//
// Created by Dmitry Mozgin on 04/05/2017.
//

#pragma once

#include <memory>
#include "RuntimePlatform.h"

namespace vd {

class IGameContext {
public:

    virtual RuntimePlatform GetRuntimePlatform() = 0;

    virtual float GetScreenDpi() = 0;

    virtual void Quit() = 0;

    virtual ~IGameContext() = 0;

};

typedef std::shared_ptr<IGameContext> IGameContextRef;

class GameContext {
public:

    static RuntimePlatform GetRuntimePlatform();

    static bool IsMobilePlatform();

    static float GetScreenDpi();

    static void Quit();

};

namespace internal {

class GameContext {
    friend vd::GameContext;

public:

    static void RegisterGameContext(const IGameContextRef &context);

private:

    static IGameContextRef _Context;

};

}

}

