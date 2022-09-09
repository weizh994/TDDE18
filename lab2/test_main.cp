#define CATCH_CONFIG_MAIN
#include "catch.hh"
#include "time.h"

TEST_CASE("Time Test"){
    time t;
    REQUIRE(t.typeof(time));
}