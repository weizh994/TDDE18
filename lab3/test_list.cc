// This test program uses a test framework supporting TDD and BDD.
// You are not required to use the framework, but encouraged to.
// Code:
// https://github.com/philsquared/Catch.git
// Documentation:
// https://github.com/philsquared/Catch/blob/master/docs/tutorial.md

// You ARE however required to implement all test cases outlined here,
// even if you do it by way of your own function for each case.  You
// are recommended to solve the cases in order, and rerun all tests
// after you modify your code.

// This define lets Catch create the main test program
// (Must be in only one place!)
#include "catch.hpp"
#include "linked_list.h"
#include <random>

//=======================================================================
// Test cases
//=======================================================================

TEST_CASE("Create an empty list")
{
  List l{};
  REQUIRE(l.is_empty() == true);
  REQUIRE(l.size() == 0);
}

TEST_CASE("Add some value")
{
  List l{};
  REQUIRE(l.is_empty() == true);
  REQUIRE(l.size() == 0);
  l.insert(5);
  CHECK_FALSE(l.is_empty());
  CHECK(l.size() == 1);
  CHECK(l.getValue(1) == 5);
  l.insert(3);
  CHECK_FALSE(l.is_empty());
  CHECK(l.size() == 2);
  CHECK(l.getValue(1) == 3);
  CHECK(l.getValue(2) == 5);
  l.insert(9);
  CHECK_FALSE(l.is_empty());
  CHECK(l.size() == 3);
  CHECK(l.getValue(1) == 3);
  CHECK(l.getValue(2) == 5);
  CHECK(l.getValue(3) == 9);
  l.insert(7);
  CHECK_FALSE(l.is_empty());
  CHECK(l.size() == 4);
  CHECK(l.getValue(1) == 3);
  CHECK(l.getValue(2) == 5);
  CHECK(l.getValue(3) == 7);
  CHECK(l.getValue(4) == 9);
}
TEST_CASE("Remove some value")
{
  List l{5, 3, 9, 7};
  REQUIRE(l.is_empty() == false);
  CHECK(l.size() == 4);
  l.remove(5);
  CHECK(l.size() == 3);
  CHECK(l.getValue(1) == 3);
  CHECK(l.getValue(2) == 7);
  CHECK(l.getValue(3) == 9);
  l.remove(3);
  CHECK(l.size() == 2);
  CHECK(l.getValue(1) == 7);
  CHECK(l.getValue(2) == 9);
  l.remove(9);
  CHECK(l.size() == 1);
  CHECK(l.getValue(1) == 7);
  l.remove(7);
  CHECK(l.size() == 0);
  CHECK(l.is_empty());
}

TEST_CASE("print some values")
{
  List l{5, 3, 9, 7};
  REQUIRE(l.is_empty() == false);
  REQUIRE(l.size() == 4);
  l.print();
}

TEST_CASE("print the index values")
{
  List l{5, 3, 9, 7};
  REQUIRE(l.is_empty() == false);
  REQUIRE(l.size() == 4);
  CHECK(l.findIndex(1) == -1);
  CHECK(l.findIndex(3) == 1);
  CHECK(l.findIndex(4) == -1);
  CHECK(l.findIndex(5) == 2);
  CHECK(l.findIndex(7) == 3);
  CHECK(l.findIndex(9) == 4);
  CHECK(l.findIndex(11) == -1);
}

TEST_CASE("get some values")
{
  List l{5, 3, 9, 7};
  REQUIRE(l.is_empty() == false);
  REQUIRE(l.size() == 4);
  CHECK(l.getValue(1) == 3);
  CHECK(l.getValue(2) == 5);
  CHECK(l.getValue(3) == 7);
  CHECK(l.getValue(4) == 9);
  CHECK(l.getValue(6) == -1);
}
TEST_CASE(" deep copy with '=' operator")

{
  List l1{5, 3, 9, 7};
  List l2{6, 7, 8, 9, 10};
  REQUIRE(l1.is_empty() == false);
  REQUIRE(l1.size() == 4);
  REQUIRE(l2.is_empty() == false);
  REQUIRE(l2.size() == 5);
  l1 = l2;
  CHECK(l1.getValue(1) == l2.getValue(1));
  CHECK(l1.getValue(2) == l2.getValue(2));
  CHECK(l1.getValue(3) == l2.getValue(3));
  CHECK(l1.getValue(4) == l2.getValue(4));
}
TEST_CASE(" deep copy without '=' operator")
{
  List l1{5, 3, 9, 7};
  List l2{l1};
  REQUIRE(l1.is_empty() == false);
  REQUIRE(l1.size() == 4);
  CHECK(l1.size() == l2.size());
  CHECK(l1.getValue(1) == l2.getValue(1));
  CHECK(l1.getValue(2) == l2.getValue(2));
  CHECK(l1.getValue(3) == l2.getValue(3));
  CHECK(l1.getValue(4) == l2.getValue(4));
}

TEST_CASE(" move ")
{
  List l1{5, 3, 9, 7};
  CHECK_FALSE(l1.is_empty());
  CHECK(l1.size() == 4);
  List l2(std::move(l1));
  CHECK(l1.is_empty());
  CHECK(l1.size() == 0);
  CHECK(l2.is_empty() == false);
  CHECK(l2.size() == 4);
}
TEST_CASE(" move with equal to ")
{
  List l1{5, 3, 9, 7};
  List l2{};
  CHECK_FALSE(l1.is_empty());
  CHECK(l1.size() == 4);
  l2 = std::move(l1);
  CHECK(l1.is_empty());
  CHECK(l1.size() == 0);
  CHECK(l2.is_empty() == false);
  CHECK(l2.size() == 4);
}

// It is your job to create new test cases and fully test your Sorted_List class
