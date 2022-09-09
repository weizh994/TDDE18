#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "Time.h"

TEST_CASE("Time Test"){
    TIME t;
    REQUIRE(t.typeof(TIME));
    cin>>t;
    cout<<t<<endl;
}