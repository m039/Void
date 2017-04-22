//
// Created by Dmitry Mozgin on 21/04/2017.
//

#include "CoroutineManager.h"

using namespace vd;

CoroutineManager::CoroutineManager() :
        _inUpdate(false) {
}

CoroutineRef CoroutineManager::Start(const Coroutine::EnumerationFunction &enumerator) {
    auto coroutine = std::make_shared<Coroutine>(enumerator);

    if (!_inUpdate) {
        _coroutines.push_back(coroutine);
    } else {
        _pendingOperations.push_back([&]() {
            _coroutines.push_back(coroutine);
        });
    }

    return coroutine;
}

void CoroutineManager::Stop(const CoroutineRef &coroutine) {
    if (coroutine == nullptr)
        return;

    if (!_inUpdate) {
        _coroutines.erase(
                std::find(
                        _coroutines.begin(),
                        _coroutines.end(),
                        coroutine
                ),
                _coroutines.end()
        );
        coroutine->Stop();
    } else {
        _pendingOperations.push_back([&]() {
            CoroutineManager::Stop(coroutine);
        });
    }
}

void CoroutineManager::StopAll() {
    if (!_inUpdate) {
        for (auto& c: _coroutines) {
            c->Stop();
        }

        _coroutines.clear();
    } else {
        _pendingOperations.push_back([&] () {
            CoroutineManager::StopAll();
        });
    }
}

void CoroutineManager::Update() {
    _inUpdate = true;
    for (auto& c : _coroutines) {
        c->Update();
    }
    _inUpdate = false;

    _coroutines.erase(
            std::remove_if(
                    _coroutines.begin(),
                    _coroutines.end(),
                         [] (CoroutineRef& coroutine) {
                             return coroutine->IsDone();
                         }
            ),
            _coroutines.end()
    );

    // It could be a call to other functions from the Update.

    if (_pendingOperations.size() > 0) {
        for (auto& op: _pendingOperations) {
            op();
        }
        _pendingOperations.clear();
    }
}