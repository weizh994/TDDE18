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
    CHECK((t1<t2);
    TIME t1(07:58:10);
    TIME t2(06:56:11);
    CHECK (t1<t2);
    TIME t1(04:42:22);
    TIME t2(06:56:11);
    CHECK((t1<t2);
    TIME t1(06:56:11);
    TIME t2(06:56:11);
    CHECK(t1<t2);
    TIME t1(07:24:54);
    TIME t2(06:56:11);
    CHECK_FALSE(t1<t2);

}


TEST_CASE(operator>)
{
    TTIME t1(04:42:22);
    TIME t2(06:56:11);
    CHECK((t1>t2);
    TIME t1(07:58:10);
    TIME t2(06:56:11);
    CHECK (t1>t2);
    TIME t1(04:42:22);
    TIME t2(06:56:11);
    CHECK((t1>t2);
    TIME t1(06:56:11);
    TIME t2(06:56:11);
    CHECK(t1>t2);
    TIME t1(07:24:54);
    TIME t2(06:56:11);
    CHECK_FALSE(t1>t2);

}


TEST_CASE(operator!=)
{
 TIME t1(04:42:22);
    TIME t2(06:56:11);
    CHECK((t1!=t2);
    TIME t1(07:58:10);
    TIME t2(06:56:11);
    CHECK (t1!=t2);
    TIME t1(04:42:22);
    TIME t2(06:56:11);
    CHECK((t1!=t2);
    TIME t1(06:56:11);
    TIME t2(06:56:11);
    CHECK(t1!=t2);
    TIME t1(07:24:54);
    TIME t2(06:56:11);
    CHECK_FALSE(t1!=t2);

}


TEST_CASE(operator>=)
{
    TIME t1(04:42:22);
    TIME t2(06:56:11);
    CHECK((t1>=t2);
    TIME t1(07:58:10);
    TIME t2(06:56:11);
    CHECK (t1>=t2);
    TIME t1(04:42:22);
    TIME t2(06:56:11);
    CHECK((t1>=t2);
    TIME t1(06:56:11);
    TIME t2(06:56:11);
    CHECK(t1>=t2);
    TIME t1(07:24:54);
    TIME t2(06:56:11);
    CHECK_FALSE(t1>=t2);

}


TEST_CASE(operator<=)
{
   TIME t1(04:42:22);
    TIME t2(06:56:11);
    CHECK((t1<=t2);
    TIME t1(07:58:10);
    TIME t2(06:56:11);
    CHECK (t1<=t2);
    TIME t1(04:42:22);
    TIME t2(06:56:11);
    CHECK((t1<=t2);
    TIME t1(06:56:11);
    TIME t2(06:56:11);
    CHECK(t1<=t2);
    TIME t1(07:24:54);
    TIME t2(06:56:11);
    CHECK_FALSE(t1<=t2);

}

TEST_CASE(operator==)
{
    TIME t1(04:42:22);
    TIME t2(06:56:11);
    CHECK((t1==t2);
    TIME t1(07:58:10);
    TIME t2(06:56:11);
    CHECK (t1==t2);
    TIME t1(04:42:22);
    TIME t2(06:56:11);
    CHECK((t1==t2);
    TIME t1(06:56:11);
    TIME t2(06:56:11);
    CHECK(t1==t2);
    TIME t1(07:24:54);
    TIME t2(06:56:11);
    CHECK_FALSE(t1==t2);


}
