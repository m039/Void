//
// Created by Dmitry Mozgin on 21/04/2017.
//

#include "catch.hpp"

#include "Common/Time.h"
#include "Common/Coroutines/WaitForSeconds.h"

#include <iostream>

using namespace vd;
using namespace std::chrono;

class PrettyCoutScope {

public:

    PrettyCoutScope() {
        _flags = std::cout.flags();
        std::cout << std::fixed;
    }

    ~PrettyCoutScope() {
        std::cout.flags(_flags);
    }

private:

    uint _flags;

};

TEST_CASE("WaitForSeconds", "[Coroutine]") {
    auto coroutine = WaitForSeconds(0.1f);

    REQUIRE(!coroutine.IsDone());

    auto start = Time::GetTime();

    do {
        coroutine.Update();
    } while (Time::GetTime() - start <= 0.2f);

    REQUIRE(coroutine.IsDone());
}