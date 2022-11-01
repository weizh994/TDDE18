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
#define CATCH_CONFIG_MAIN
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
  l.insert(3);
  l.insert(9);
  l.insert(7);
  l.print(); // 3,5,7,9
  l.insert(1);
  l.print(); // 1,3,5,7,9
  l.insert(1);
  l.print(); // 1,1,3,5,7,9
  l.insert(8);
  l.print(); // 1,1,3,5,7,8,9
  l.insert(11);
  l.print(); // 1,1,3,5,7,8,9,11
}
TEST_CASE("Remove some value")
{
  List l{5, 3, 9, 7};
  REQUIRE(l.is_empty() == false);
  REQUIRE(l.size() == 4);
  l.insert(5);
  l.insert(3);
  l.insert(9);
  l.insert(7);
  l.print();   // 3,5,7,9
  l.remove(1); // cout: "Not exist"
  l.print();   // 3,5,7,9
  l.remove(5);
  l.print(); // 3,7,9
  l.remove(3);
  l.print(); // 7,9
  l.remove(7);
  l.print(); // 9
  l.remove(9);
  l.print(); //"List is Empty"
}
// It is your job to create new test cases and fully test your Sorted_List class
