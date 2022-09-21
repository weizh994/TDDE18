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

TEST_CASE("is_am")
{
    TIME t1{233, 100, 2};
    CHECK_FALSE(is_am(t1));
    TIME t2{0, 0, 0};
    CHECK(is_am(t2));
    TIME t3{12, 0, 0};
    CHECK_FALSE(is_am(t3));
}

TEST_CASE("to_string")
{
    TIME t1{14, 21, 23};
    CHECK(to_string(t1, true) == "14:21:23");
    CHECK(to_string(t1, false) == "02:21:23 pm");
    TIME t2{12, 0, 0};
    CHECK(to_string(t2, true) == "12:00:00");
    CHECK(to_string(t2, false) == "12:00:00 pm");
    TIME t3{24, 0, 0};
    CHECK(to_string(t3, true) == "ERROR: Illegal Time!");
    CHECK(to_string(t3, false) == "ERROR: Illegal Time!");
}

TEST_CASE("operator+")
{
    TIME t1{0, 0, 0};
    CHECK(t1 + 86400 == t1);
    TIME t2{0, 0, 1};
    CHECK(t1 + 1 == t2);
    TIME t3{0, 1, 1};
    CHECK(t2 + 60 == t3);
    TIME t4{1, 1, 1};
    CHECK(t3 + 3600 == t4);
}

TEST_CASE("operator-")
{
    TIME t1{0, 0, 0};
    CHECK(t1 - 86400 == t1);
    TIME t2{23, 59, 59};
    CHECK(t1 - 1 == t2);
    TIME t3{23, 57, 59};
    CHECK(t2 - 120 == t3);
    TIME t4{22, 57, 59};
    CHECK(t3 - 3600 == t4);
}

TEST_CASE("operator++")
{
    TIME t1{0, 0, 59};
    TIME t2(t1++);
    CHECK(to_string(t1) == "00:01:00");
    CHECK(to_string(t2) == "00:00:59");
}

TEST_CASE("operator--")
{
    TIME t1{0, 1, 0};
    TIME t2(t1--);
    CHECK(to_string(t1) == "00:00:59");
    CHECK(to_string(t2) == "00:01:00");
}

TEST_CASE("operator++,int")
{
    TIME t1{0, 0, 59};
    TIME t2(++t1);
    CHECK(to_string(t1) == "00:01:00");
    CHECK(to_string(t2) == "00:01:00");
}

TEST_CASE("operator--,int")
{
    TIME t1{0, 1, 0};
    TIME t2(--t1);
    CHECK(to_string(t1) == "00:00:59");
    CHECK(to_string(t2) == "00:00:59");
}

/*TEST_CASE("operator>>")
{
    istringstream iss{"11:00:00 "};
    TIME t{};
    iss >> t;
    CHECK(iss.fail());
    CHECK(to_string(t) == "11:00:00");
}*/

TEST_CASE("operator<<")
{
    std::ostringstream oss{}; // fake "cout"
    TIME t{1, 2, 2};
    oss << t;
    CHECK(oss.str() == "01:02:02");
    std::ostringstream oss{}; // fake "cout"
    TIME t{13, 2, 2};
    oss << t;
    CHECK(oss.str() == "13:02:02");
}