#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "Time.h"
#include <iostream>
#include <typeinfo>
using namespace std;
TEST_CASE("Time Test")
{
    TIME t;
    // REQUIRE(t.typeof(TIME));
    cin >> t;
    cout << t << endl;
}
TEST_CASE(is_am)
{
    TIME t("03:05:52");
    CHECK(is_am(t))
    TIME t("12:22:52");
    CHECK(is_am(t))
    TIME t("18:05:52");
    CHECK(is_am(t))

}
TEST_CASE(operator<)
{
    TIME t1(04:42:22);
    TIME t2(06:56:11);
    CHECK(operator<(t1,t2));
    TIME t1(07:58:10);
    TIME t2(06:56:11);
    CHECK(operator<(t1,t2));
    TIME t1(04:42:22);
    TIME t2(06:56:11);
    CHECK(operator<(t1,t2));
    TIME t1(06:56:11);
    TIME t2(06:56:11);
    CHECK(operator<(t1,t2));
    TIME t1(07:24:54);
    TIME t2(06:56:11);
    CHECK(operator<(t1,t2);
    CHECK false;
}


TEST_CASE(operator>)
{
    TIME t1(04:42:22);
    TIME t2(06:56:11);
    CHECK(operator>(t1,t2));
    TIME t1(07:58:10);
    TIME t2(06:56:11);
    CHECK(operator>(t1,t2));
    TIME t1(04:42:22);
    TIME t2(06:56:11);
    CHECK(operator>(t1,t2));
    TIME t1(06:56:11);
    TIME t2(06:56:11);
    CHECK(operator>(t1,t2));
    TIME t1(07:24:54);
    TIME t2(06:56:11);
    CHECK(operator>(t1,t2);
    CHECK false;
}


TEST_CASE(operator!=)
{
    TIME t1(04:42:22);
    TIME t2(06:56:11);
    CHECK(operator!=(t1,t2));
    TIME t1(07:58:10);
    TIME t2(06:56:11);
    CHECK(operator!=(t1,t2));
    TIME t1(04:42:22);
    TIME t2(06:56:11);
    CHECK(operator!=(t1,t2));
    TIME t1(06:56:11);
    TIME t2(06:56:11);
    CHECK(operator!=(t1,t2));
    TIME t1(07:24:54);
    TIME t2(07:24:54);
    CHECK(operator<(t1,t2);
    CHECK false;
}


TEST_CASE(operator>=)
{
    TIME t1(04:42:22);
    TIME t2(06:56:11);
    CHECK(operator>=(t1,t2));
    TIME t1(07:58:10);
    TIME t2(06:56:11);
    CHECK(operator>=(t1,t2));
    TIME t1(04:42:22);
    TIME t2(06:56:11);
    CHECK(operator>=(t1,t2));
    TIME t1(06:56:11);
    TIME t2(06:56:11);
    CHECK(operator>=(t1,t2));
    TIME t1(07:24:54);
    TIME t2(06:56:11);
    CHECK(operator>=(t1,t2);
    CHECK false;
}


TEST_CASE(operator<=)
{
    TIME t1(04:42:22);
    TIME t2(06:56:11);
    CHECK(operator<=(t1,t2));
    TIME t1(07:58:10);
    TIME t2(06:56:11);
    CHECK(operator<=(t1,t2));
    TIME t1(04:42:22);
    TIME t2(06:56:11);
    CHECK(operator<=(t1,t2));
    TIME t1(06:56:11);
    TIME t2(06:56:11);
    CHECK(operator<=(t1,t2));
    TIME t1(07:24:54);
    TIME t2(06:56:11);
    CHECK(operator<=(t1,t2);
    CHECK false;
}

TEST_CASE(operator==)
{
    TIME t1(12:24:44);
    TIME t2(12:24:44);
    CHECK(operator==(t1,t2));
    TIME t1(01:01:01);
    TIME t2(01:01:01);
    CHECK(operator==(t1,t2));
    TIME t1(01:01:01);
    TIME t2(12:12:12);
    CHECK(operator==(t1,t2));
    CHECK false;
    

}
TEST_CASE(operator<<)
{
    TIME t(04:32:44);
    CHECK(operator>>(t,cout));

}