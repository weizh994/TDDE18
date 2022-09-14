#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "Time.h"
#include <iostream>
#include <typeinfo>
using namespace std;
TEST_CASE("Time Test")
{
    TIME t1{0, 0, 0};
    TIME t2{12, 10, 10};
    // REQUIRE(t.typeof(TIME));
    // CHECK(t1 < t2);
    string s1 = to_string(t1, false);
    string s2 = to_string(t1 - 1, false);
    cout << s1 << endl;
    cout << s2 << endl;
}
