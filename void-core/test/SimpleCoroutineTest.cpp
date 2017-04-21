//
// Created by Dmitry Mozgin on 21/04/2017.
//

#include <stdio.h>
#include "catch.hpp"

#include "boost/coroutine2/coroutine.hpp"
#include <iostream>

typedef boost::coroutines2::coroutine<int> coro;

static volatile int j;

void xrange_impl(coro::push_type &yield, int limit) {
    yield(-1);

    j = 0;
    for (int i = 0; i < limit; i++) {
        yield(i + 44);
        j++;
    }
}

TEST_CASE("Testing1", "[Sandbox]") {
    j = -11;

    coro::pull_type xrange(std::bind(xrange_impl, std::placeholders::_1, 2));

    REQUIRE(j == -11);
    REQUIRE(true);

    xrange();

    REQUIRE(j == 0);
    REQUIRE(xrange);

    xrange();

    REQUIRE(j == 1);
    REQUIRE(xrange);

    xrange();

    REQUIRE(!xrange);
}