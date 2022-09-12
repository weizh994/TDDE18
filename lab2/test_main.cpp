#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "Time.h"
#include<iostream>
#include<typeinfo>
using namespace std;
TEST_CASE("Time Test"){
    TIME t;
    //REQUIRE(t.typeof(TIME));
    CHECK(cin>>t);
    cout<<t<<endl;
}
