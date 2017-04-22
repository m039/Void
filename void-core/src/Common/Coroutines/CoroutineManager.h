//
// Created by Dmitry Mozgin on 21/04/2017.
//

#pragma once

#include <memory>

#include "Common/Common.h"

#include "Coroutine.h"

namespace vd {

class CoroutineManager {

public:

    CoroutineManager();

    CoroutineRef Start(const Coroutine::EnumerationFunction &enumerator);

    void StopAll();

    void Stop(const CoroutineRef& coroutine);

    void Update();

private:

    std::vector<CoroutineRef> _coroutines;

    std::vector<Action> _pendingOperations;

    bool _inUpdate;

};

}