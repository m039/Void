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

TEST_CASE("Testing1", "Test2") {
    int n = 1;
    REQUIRE(n == 1);
}
