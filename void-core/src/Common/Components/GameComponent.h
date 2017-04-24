//
// Created by Dmitry Mozgin on 24/04/2017.
//

#pragma once

#include <Common/Coroutines/CoroutineManager.h>

namespace vd {

class IGameComponent {

public:

    virtual void Start() = 0;

    virtual void Update() = 0;

};

class GameComponent : IGameComponent {

public:

     void Start() override;

     void Update() override;

protected:

    CoroutineManager& GetCoroutineManager() {
        return _coroutineManager;
    }

    virtual void OnStart() {}

    virtual void OnUpdate() {}

private:

    CoroutineManager _coroutineManager;

};

}