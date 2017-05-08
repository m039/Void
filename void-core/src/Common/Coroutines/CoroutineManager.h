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

    ~CoroutineManager();

    CoroutineRef Start(const Coroutine::EnumerationFunction &enumerator);

    void Stop(const CoroutineRef& coroutine);

    void StopAll();

    void Update();

private:

    std::vector<CoroutineRef> _coroutines;

    std::vector<Callback> _pendingOperations;

    bool _inUpdate;

};

}