//
// Created by Dmitry Mozgin on 21/04/2017.
//

#pragma once

namespace vd {

class Time {

public:

    inline static double GetTime() {
        std::chrono::duration<double> t = std::chrono::system_clock()
                .now()
                .time_since_epoch();

        return t.count();
    }

};

}