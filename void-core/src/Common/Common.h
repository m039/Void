//
// Created by Dmitry Mozgin on 22/04/2017.
//

#pragma once

#include <functional>

namespace vd {

typedef std::function<void()> Callback;

/// Time in seconds.
typedef double sec_t;

struct EnumClassHash
{
    template <typename T>
    
    std::size_t operator()(T t) const
    {
        return static_cast<std::size_t>(t);
    }
};

}
