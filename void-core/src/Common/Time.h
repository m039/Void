//
// Created by Dmitry Mozgin on 21/04/2017.
//

#pragma once

#include <chrono>
#include "Common.h"

namespace vd {

namespace internal {

class Time {

public:

    static void Update();

private:

    static sec_t _PreviousTime;

    static bool _Started;

};

}

class Time {
    friend internal::Time;

public:

    inline static sec_t GetTime() {
        std::chrono::duration<double> t = std::chrono::system_clock()
                .now()
                .time_since_epoch();

        return t.count();
    }

    inline static sec_t GetDeltaTime() {
        return _DeltaTime;
    }

private:

    static sec_t _DeltaTime;

};


}