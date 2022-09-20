#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "Time.h"
#include <iostream>
#include <typeinfo>
using namespace std;
TEST_CASE("is_valid")
{
    TIME t1{0, 0, 0};
    CHECK(is_valid(t1));
    TIME t2{23, -1, 9};
    CHECK_FALSE(is_valid(t2));
    TIME t3{0, 0, 60};
    CHECK_FALSE(is_valid(t3));
}

TEST_CASE("to_string")
{
    TIME t1{14, 21, 23};
    CHECK(to_string(t1, true) == "14:21:23");
    CHECK(to_string(t1, false) == "02:21:23 am");
    TIME t2{12, 0, 0};
    CHECK(to_string(t2, true) == "12:00:00");
    CHECK(to_string(t2, false) == "12:00:00 pm");
}

