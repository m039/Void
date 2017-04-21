//
// Created by Dmitry Mozgin on 21/04/2017.
//

#pragma once

#include "IYieldInstruction.h"

#include "boost/coroutine2/coroutine.hpp"

namespace vd {

class Coroutine : public IYieldInstruction {

    typedef boost::coroutines2::coroutine<std::shared_ptr<IYieldInstruction>> InternalRepresentation;

public:

    typedef InternalRepresentation::push_type YieldHandler;

    typedef std::function<void(vd::Coroutine::YieldHandler&)> EnumeratorFunction;

    Coroutine(const EnumeratorFunction enumerator);

    void Update() override;

    bool IsDone() const override;

    //region Internal usage (may be to add friend declaration instead?)

    bool IsValid();

    bool IsCanceled();

    void Stop();

    //endregion

private:

    const EnumeratorFunction _enumerator;

    std::unique_ptr<InternalRepresentation::pull_type>  _coroutine;

    std::shared_ptr<IYieldInstruction> _current;

    bool _started;

    bool _done;

    bool _canceled;

};

}