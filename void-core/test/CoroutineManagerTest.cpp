//
// Created by Dmitry Mozgin on 21/04/2017.
//

#include "catch.hpp"

#include <Common/Coroutines/WaitForSeconds.h>
#include <Common/Time.h>
#include "Common/Coroutines/Coroutine.h"
#include "Common/Coroutines/CoroutineManager.h"

using namespace vd;

// Note: StopAll and Stop functions are not fully tested, but they should work.

TEST_CASE("CoroutineManager", "[Coroutine]") {
    auto coroutineManager = CoroutineManager();

    std::vector<int> result;

    auto coroutine1 = coroutineManager.Start([&](Coroutine::YieldHandler &yield) {
        result.push_back(1);
        yield(std::make_shared<WaitForSeconds>(0.07f));
    });

    auto coroutine2 = coroutineManager.Start([&](Coroutine::YieldHandler &yield) {
        yield(std::make_shared<WaitForSeconds>(0.04f));
        result.push_back(2);
        yield(std::make_shared<WaitForSeconds>(0.02f));
        result.push_back(3);
    });

    coroutineManager.Start([&](Coroutine::YieldHandler &yield) {
        yield(std::make_shared<WaitForSeconds>(0.045f));
        coroutineManager.Stop(coroutine2);
    });

    auto start = Time::GetTime();

    while (!coroutine1->IsDone()) {
        coroutineManager.Update();
    }

    auto deltaTime = Time::GetTime() - start;

    REQUIRE(result == std::vector<int>({1, 2}));
    REQUIRE(deltaTime > 0.07f);
    REQUIRE(deltaTime < 0.08f);
}