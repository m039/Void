//
//  SimpleTest.cpp
//  VoidCore
//
//  Created by Dmitry Mozgin on 12/04/2017.
//  Copyright © 2017 BTG. All rights reserved.
//

#include <stdio.h>
#include "catch.hpp"
#include <VoidCore.hpp>

TEST_CASE("Testing Library") {
    SECTION("Doing shit") {
        INFO("Ok, starting doing shit") // Only appears on a FAIL
        CAPTURE("on3Fail"); // Displays this variable on a FAIL

        auto v = VoidCore();

        CHECK(v.number == 14);
    }
}

#include "boost/coroutine2/coroutine.hpp"

typedef boost::coroutines2::coroutine<int> coro;

static int j = 30;

void xrange_impl(coro::push_type &yield, int limit) {
    j = 0;
    for (int i = 0; i < limit; i++) {
        yield(i);
        j++;
    }
}

TEST_CASE("Testing1", "Test2") {
    coro::pull_type xrange(std::bind(xrange_impl, std::placeholders::_1, 2));

    j = 1;

    xrange();

    REQUIRE(j == 0);

    xrange();

    REQUIRE(j == 1);

    xrange();

    REQUIRE(j == 1);
}
