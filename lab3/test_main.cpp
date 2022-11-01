#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "linked_list.hh"
#include <random>
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