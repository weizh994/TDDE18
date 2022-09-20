#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "Time.h"
#include <iostream>
#include <typeinfo>
using namespace std;
TEST_CASE("is_valid")
{
    TIME t1{0, 0, 0};
    TIME t2{23, -1, 9};
    CHECK(is_valid(t1));
    CHECK_FALSE(is_valid(t2));
}

TEST_CASE("to_string")
{
    TIME t{12, 0, 0};
}
