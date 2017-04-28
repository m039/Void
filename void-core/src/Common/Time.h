//
// Created by Dmitry Mozgin on 21/04/2017.
//

#pragma once

#include <chrono>
#include "Common.h"

namespace vd {

class Time {

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

    // Todo: add friend declaration.
    static void Update();

private:

    static sec_t _DeltaTime;

    static sec_t _PreviousTime;

    static bool _Started;

};



}