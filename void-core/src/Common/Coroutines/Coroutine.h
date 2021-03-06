//
// Created by Dmitry Mozgin on 21/04/2017.
//

#pragma once

#include "YieldInstruction.h"

#include "boost/coroutine2/coroutine.hpp"

namespace vd {

class Coroutine : public IYieldInstruction {

    friend class CoroutineManager;

    typedef boost::coroutines2::coroutine<std::shared_ptr<IYieldInstruction>> InternalRepresentation;

public:

    typedef InternalRepresentation::push_type YieldHandler;

    typedef std::function<void(vd::Coroutine::YieldHandler&)> EnumerationFunction;

    Coroutine(const EnumerationFunction& enumerator);

    //region Implementation of IYieldInstruction.

    void Update() override;

    bool IsDone() const override;

    //endregion

private:

    //region Functions used by CoroutineManager.

    bool IsValid();

    bool IsCanceled();

    void Stop();

    //endregion

    const EnumerationFunction _enumerator;

    std::unique_ptr<InternalRepresentation::pull_type>  _coroutine;

    bool _started;

    bool _done;

    bool _canceled;

    std::shared_ptr<IYieldInstruction> _current;

};

typedef std::shared_ptr<Coroutine> CoroutineRef;

}
