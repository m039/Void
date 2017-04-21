//
// Created by Dmitry Mozgin on 21/04/2017.
//

#include "catch.hpp"

#include <Common/Coroutines/WaitForSeconds.h>
#include <Common/Time.h>
#include "Common/Coroutines/Coroutine.h"

using namespace vd;

TEST_CASE("Coroutine", "[Coroutine]") {
    std::vector<int> result;

    auto coroutine = Coroutine([&result](Coroutine::YieldHandler &yield) {
        result.push_back(1);
        yield(std::make_shared<WaitForSeconds>(0.05f));

        result.push_back(4);
        yield(nullptr);

        result.push_back(2);
        yield(std::make_shared<WaitForSeconds>(0.05f));

        result.push_back(3);
        yield(std::make_shared<WaitForSeconds>(0.05f));
    });

    auto start = Time::GetTime();

    while (!coroutine.IsDone()) {
        coroutine.Update();
    }

    auto deltaTime = Time::GetTime() - start;

    REQUIRE(result == std::vector<int>({1, 4, 2, 3}));
    REQUIRE(deltaTime > 0.15f);
    REQUIRE(deltaTime < 0.16f);
}