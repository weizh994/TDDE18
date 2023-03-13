#include "editor.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iterator>
using namespace std;

// TODO: Complementary work needed: There is no reason for the program to be
// a class. This results in an awkward design with a lot of pseudo-global variables
// that makes the code harder to read and easier to break.

// TODO: Complementary work needed: Use at least reference for input parameters           
// of class type. Use reference to constant if you don't need to change the value.  
// (Hint: string is a class type) 
//  Done

// TODO: Complementary work needed: checkArg returns a boolean that is not used
//  Done

// TODO: Complementary work needed: You create a new variable text in the constructor.
// This is not the same variable as your class variable text. The same applies to
// dictionary and argument.
//  Done

// TODO: Complementary work needed: There is no reason to explicitly clear your containers
// in the destructor
//  Done

// TODO: Complementary work needed: You do not need to remove executed arguments. It is
// enough to iterate over the vector.
// I instead that by for_each()

// Comment: Using createDictionary() when it is used should decrease the risk of forgetting
// to call the function after changing the text. This becomes much safer if working with
// a local dictionary that is returned rather than a class variable.
// Now, I call createDictionary() before it be printed.

int main(int argc, char **argv)
{
  editor(argc, argv);
}