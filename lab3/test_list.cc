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
#include "linked_list.hh"
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
  CHECK_FALSE(l.is_empty);
  CHECK(l.size == 1);
  CHECK(l.getValue(1) == 5);
  l.insert(3);
  CHECK_FALSE(l.is_empty);
  CHECK(l.size == 2);
  CHECK(l.getValue(1) == 3);
  CHECK(l.getValue(2) == 5);
  l.insert(9);
  CHECK_FALSE(l.is_empty);
  CHECK(l.size == 3);
  CHECK(l.getValue(1) == 3);
  CHECK(l.getValue(2) == 5);
  CHECK(l.getValue(3) == 9);
  l.insert(7);
  CHECK_FALSE(l.is_empty);
  CHECK(l.size == 4);
  CHECK(l.getValue(1) == 3);
  CHECK(l.getValue(2) == 5);
  CHECK(l.getValue(2) == 7);
  CHECK(l.getValue(4) == 9);
}
TEST_CASE("Remove some value")
{
  List l{5, 3, 9, 7};
  REQUIRE(l.is_empty() == false);
  REQUIRE(l.size() == 4);
}
// It is your job to create new test cases and fully test your Sorted_List class
