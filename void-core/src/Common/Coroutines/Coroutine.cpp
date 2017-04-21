//
// Created by Dmitry Mozgin on 21/04/2017.
//

#include <iostream>

#include "Common/Debug.h"
#include "Coroutine.h"

using namespace vd;

Coroutine::Coroutine(const EnumerationFunction enumerator)
        : _enumerator(enumerator),
          _canceled(false),
          _started(false),
          _done(false),
          _current(nullptr) {
}

void Coroutine::Update() {
    if (!IsValid()) {
        Debug::Log("Coroutine is canceled or finished.");
        return;
    }

    if (!_started) {
        _coroutine = std::make_unique<InternalRepresentation::pull_type>(_enumerator);
        _started = true;
    } else {
        if (_current == nullptr) {
            _current = _coroutine->get();
        }

        if (_current == nullptr) {
            (*_coroutine)();
        } else {
            _current->Update();

            if (!_current->IsDone()) {
                return;
            } else {
                _current = nullptr;
            }
        }
    }

    _done |= !(*_coroutine? true : false);
}

bool Coroutine::IsDone() const {
    return _done;
}

bool Coroutine::IsValid() {
    return !_done && !_canceled;
}

bool Coroutine::IsCanceled() {
    return _canceled;
}

void Coroutine::Stop() {
    _canceled = true;
}
