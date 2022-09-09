#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "Time.h"

TEST_CASE("Time Test"){
    time t;
    REQUIRE(t.typeof(time));
}