- [Standard library](#standard-library)
  - [1 Containers](#1-containers)
    - [Introduction](#introduction)
    - [Sequence container](#sequence-container)
    - [Sequence adapters](#sequence-adapters)
    - [Associative containers](#associative-containers)
  - [2 Iterators](#2-iterators)
    - [Iteration](#iteration)
    - [Range-based for-loop](#range-based-for-loop)
      - [A container can be looped through if:](#a-container-can-be-looped-through-if)
    - [Iterators](#iterators)
    - [Iterator categories](#iterator-categories)
  - [3 Standard Library](#3-standard-library)
    - [What is the Standard Library?](#what-is-the-standard-library)
    - [STL](#stl)
    - [Design goals](#design-goals)
    - [Components](#components)
  - [4 Algorithms](#4-algorithms)
    - [Modifying algorithms](#modifying-algorithms)
    - [Copying](#copying)
    - [Iterator categories](#iterator-categories-1)
    - [std::transform](#stdtransform)
  - [5 Lambda Functions](#5-lambda-functions)
    - [Temporary functions](#temporary-functions)
    - [Return type](#return-type)
    - [std::transform](#stdtransform-1)
    - [Lambda Functions and STL](#lambda-functions-and-stl)
    - [`operator`()](#operator)
    - [Capture](#capture)
    - [Function objects in STL](#function-objects-in-stl)
  - [6 More on iterators](#6-more-on-iterators)
    - [std::for\_each](#stdfor_each)
    - [Print a container](#print-a-container)
    - [std::ostream\_iterator](#stdostream_iterator)
    - [Read from a stream](#read-from-a-stream)
  - [7 Smart pointers](#7-smart-pointers)
# Standard library
## 1 Containers
### Introduction
* Sequence containers(Index based containers)
  * Store values of the same type in a given sequence
  * Normally we use an index to retrieve the values
* Sequence adaptors
  * Adapted interface for a given sequence container
  * Represents ADT:s such as stacks, queues and priority queues
* Associative containers(Dictionary in Pythone & JS)
  * Store values associated with given keys
  * Values must be of the same data type
  * Keys must be of the same data type
  * Use the key to retrieve corresponding value
### Sequence container
* vector
  * Store values in consecutive memory
  * Grows to accommodate its content
  * The most common containers
* array
  * Store values in consecutive memory
  * Fixed size that is known during compilation
  * Is more effective (both in memory and speed) than vector
* deque
  * Double‐ended queue
  * Does not store values in consecutive‐memory
  * Very good to use if you want to add/remove values in the beginning AND end
* list
  * A doubly‐linked list (previous pointer as well as a
next pointer)
  * Does not store values in consecutive‐memory
  * Very good to use if you want to add/remove values
in the beginning
  * Can step backwards and forward in the list
* forward_list
  * A singly‐linked list
  * Does not store values in consecutive‐memory
  * Very good to use if you want to add/remove values
in the beginning
  * Can only step forward in the list
```C++
#include <vector>
#include <array>
#include <deque>
#include <list>
#include <forward_list>
int main()
{
// likewise for list, forward_list and deque
std::vector<int> v {1, 2, 3};
// we have to specify a size for array
std::array<int, 3> a {1, 2, 3};
std::forward_list<double>l;
push_back(5.3);//same as vector
push_front(3.1);//not in vector
//It's more ecpensive to access an element at a specific index
std::lisk<double>//双链表
}
```
### Sequence adapters
* stack
  * Usually built on top of deque
  * Can only access/remove the last inserted value
* queue
  * First‐In First‐Out, a queue
  * Usually built on top of deque
  * Can only add values to the end and remove from
the beginning
* priority_queue
  * A queue that is ordered after a given priority
  * Can only access/remove the value with the highest
priority
  * Values are always sorted by their priority
``` C++
#include <stack>
#include <queue>
#include <priority_queue>
int main()
{
// likewise for all adapters
std::stack<int> s1 {};
// we can change which container it uses
std::stack<int, std::vector<int>> s2 {};
}
```
### Associative containers
* map
  * Associates a value with a key
  * Requires the keys to be comparable with
`operator`<
  * Sorted by the keys
  * Each key can only occur once
* set
  * Like map but only store keys
  * Guarantees that all inserted values are unique and
sorted
* multi*
  * multimap and multiset
  * Like map and set respectively, but the keys doesn’t
have to be unique anymore
* unordered_*
  * unordered_map, unordered_multimap,
unordered_set and unordered_multiset,
  * The keys are no longer sorted
  * The keys doesn’t have to be comparable anymore
(however they need to be hashable)
```C++
#include <map>
#include <set>
#include <string>
int main()
{
// associates "a" with 1 and "b" with 2
std::map<std::string, int> m { {"a", 1},
{"b", 2} };
m["a"];//1
m["c"]//insert a new node with value 0
m["b"]=3;//change the value from 2 to 3
std::set<double> s { 1.0, 3.0, -1.0 };
}
```
## 2 Iterators
### Iteration
* We want to be able to loop through our containers
* It would be nice if we could do it the same way for all
containers
* The problem is that containers doesn’t always have the
same way of accessing values
* Therefore we have to generalize our understanding of
looping through containers
```c++
int main()
{
set<int> v {1, 2, 3};
for (int i{0}; i < v.size(); ++i)
{
cout << v[i] << endl; // doesn't work
}
}
```
```c++
int main()
{
set<int> v {1, 2, 3};
for (int e : v)
{
cout << e << endl; // works!
}
}
```
### Range-based for-loop
* It is possible to create your own containers and use iterators
```c++
using iterator = std::vector<int>::iterator;
for (iterator it{v.begin()}; it != v.end(); ++it)
{
cout << *it << endl;
}
```
#### A container can be looped through if:
* There is an inner class called iterator
* There are member functions begin and end, both of
which return iterator objects
* iterator has defined `operator`++, `operator`*,
`operator`== and `operator`!=
### Iterators
* Iterators are generalized pointers
* Represent a general way of iterating over containers
* Points to a value in the container
* Possible to access values with `operator`*
* Go to the next element with `operator`++
```c++
vector<int> v{1,2,3};
```
|    begin     |       |       |     end      |
| :----------: | :---: | :---: | :----------: |
| $\downarrow$ |       |       | $\downarrow$ |
|      1       |   2   |   3   |              |
```c++
vector<int>::iterator it{v.begin()};
```
|   `begin`    |       |       |     end      |
| :----------: | :---: | :---: | :----------: |
| $\downarrow$ |       |       | $\downarrow$ |
|      1       |   2   |   3   |              |
|  $\uparrow$  |       |       |              |
|     `it`     |       |       |              |
```c++
++it;
```
|    begin     |            |       |     end      |
| :----------: | :--------: | :---: | :----------: |
| $\downarrow$ |            |       | $\downarrow$ |
|      1       |     2      |   3   |              |
|              | $\uparrow$ |       |              |
|              |    `it`    |       |              |
```c++
int x{*it};
```
|    begin     |              |       |     end      |
| :----------: | :----------: | :---: | :----------: |
| $\downarrow$ |              |       | $\downarrow$ |
|      1       |      2       |   3   |              |
|              |  $\uparrow$  |       |              |
|              |      it      |       |              |
|              | $\downarrow$ |       |              |
|              |    `x=2`     |       |              |
```c++
++it;
```
|    begin     |       |            |     end      |
| :----------: | :---: | :--------: | :----------: |
| $\downarrow$ |       |            | $\downarrow$ |
|      1       |   2   |     3      |              |
|              |       | $\uparrow$ |              |
|              |       |    `it`    |              |
|              |  x=2  |            |              |
```c++
*it = 4;
```

|    begin     |       |            |     end      |
| :----------: | :---: | :--------: | :----------: |
| $\downarrow$ |       |            | $\downarrow$ |
|      1       |   2   |    `4`     |              |
|              |       | $\uparrow$ |              |
|              |       |     it     |              |
|              |  x=2  |            |              |
* It is important that `the end‐iterator doesn’t point to the
last value`
* If it does we will miss the last element in the container
since the loop is ended whe it == v.end()
* We must be able to uniquely identify that we have
iterated through all elements
* Therefore we think of the end‐iterator as a pointer to
the value after the last one
### Iterator categories
There are different types of iterators, these are:
* Input
  * Can ready already existing values in a container
* Output
  * Can add new values in a container
* Forward
  * Can read/overwrite existing values in a container
  * Can step forward in the container
  * Is also an Input iterator
* Bidirectional(双向的)
  * Is a forward iterator
  * But can also step backwards with `operator`--
* Random Access
  * Can access arbitrary elements in the container with
`operator`+
  * Is also a Bidirectional iterator  

| Operationer |  Input  | Output  |  Forward   | Bidirectional | Random Access |
| :---------: | :-----: | :-----: | :--------: | :-----------: | :-----------: |
|    ==,!=    | $\surd$ | $\surd$ |  $\surd$   |    $\surd$    |    $\surd$    |
|    *,->     |  Read   |  Write  | Read/Write |  Read/Write   |  Read/Write   |
|     ++      | $\surd$ | $\surd$ |  $\surd$   |    $\surd$    |    $\surd$    |
|      -      |         |         |            |    $\surd$    |    $\surd$    |
|  +,+=,-,-=  |         |         |            |               |    $\surd$    |
|  <,<=,>,>=  |         |         |            |               |    $\surd$    |
|    i[n]     |         |         |            |               |    $\surd$    |

## 3 Standard Library
### What is the Standard Library?
* Available for everyone
  * Same behaviour regardless of computer and
operating system
  * Is included with the compiler
  * ISO C++ requires everything to be implemented
* Solves common problems
  * Reinventing the wheel takes time
  * There are problems all programmers face
  * Should be widely applicable
* Components
  * Don’t pay for what you don’t use
  * Import only the parts that you need
  * Everything is compatible with each other
* Effective
  * The people that implement the library know what
they are doing
  * Everything is highly optimized
  * It is not your responsibility to make sure it works
### STL
**S**tandard **T**emplate **L**ibrary
### Design goals
* Should be as general as possible
* Solves common problems
* The common case should be easy
* Must work with the users code
* Should be effective enough to replace hand‐written
alternatives
* Should have robust error handling
### Components
* Algorithms
  * General functions to solve common problems
  * Perform operations on containers
  * Uses iterators as an interface against containers
  * Optimized for speed and memory usage
* Containers
  * Different ways to structure data
  * Based on common abstractions
  * We shouldn’t have to know how it works
* Iterators
  * Interface for iterating over data
  * Used as an abstraction for containers
* Others
  * General functions and classes
  * Solves various problems
  * Should be usable for as many types as possible
## 4 Algorithms
### Modifying algorithms
|   1   |   2   |   3   |   1   |   4   |   1   |
| :---: | :---: | :---: | :---: | :---: | :---: |
```C++
auto it {std::remove(v.begin(), v.end(), 1)};
```
|       |       |       |  it   |       |       |
| :---: | :---: | :---: | :---: | :---: | :---: |
|   2   |   3   |   4   |   1   |   1   |   1   |
```C++
v.erase(it, v.end());
```
|   2   |   3   |   4   |
| :---: | :---: | :---: |
```C++
std::vector<int> v {1, 2, 3, 1, 4, 1};
v.erase(std::remove(v.begin(), v.end(), 1),v.end());
```
* Some algorithms remove values
* There is no functionality in iterators that allows us to
actually remove (or insert) values
* What happens instead is that the algorithm moves all
removed values to the end of the container and return
an iterator to the first of the removed values
* Then it is up to the developer to actually remove these
values (most often with erase)
### Copying
```C++
// command-line argument
std::vector<string> args {argv, argv + argc};
// empty vector
std::vector<string> v {};
// copy all arguments to the empty vector
std::copy(args.begin(), args.end(), v.begin());
```
* The empty vector have no values
* These iterators can only read and overwrite existing
values
* Therefore we try to copy values from args to a vector (v)
that doesn’t have any elements that can be written to
```C++
// command-line arguments
std::vector<string> args {argv, argv + argc};
// vector with the right amout on elements
std::vector<string> v (args.size());
// copy all arguments to the empty vector
std::copy(args.begin(), args.end(), v.begin());
```
### Iterator categories
```C++
std::vector<int> v{1, 2, 7, 4, -1};
std::sort(v.begin(), v.end());
std::list<int> l{1, 2, 7, 4, -1};
std::sort(l.begin(), l.end());//Doesn't work
!
```
* sorting data requires the use of jumping
between arbitrary values
* it requires RandomAccessIterator (the
one with operator+)
* `std::list` only have BidirectionalIterator
### std::transform
```c++
int add_2(int n)
{
return n + 2;
}
int main()
{
std::vector<int> v {1, 2, 3};
std::vector<int> result (v.size());
std::transform(v.begin(), v.end(),
result.begin(), add_2);
}
```
* copy each value from `v`,
add 2 to the value, and then placing it into `result`
```C++
int main()
{
std::vector<int> v {1, 2, 3};
std::transform(v.begin(), v.end(),
v.begin(), add_2);
}
```
* use `std::transform` to write into the same
vector 
* it requires that the return type from the
function is the same as the values in the vector
## 5 Lambda Functions
### Temporary functions
* A lambda function is an expression that creates a
temporary function
* They allow us to create and use functions without giving
them a name
* They are also more general than normal functions
```C++
[](int n) -> int { return n + 2; }
```
>`[]` capture  
>`(int n)` inparameter  
>`-> int` return type  
>`{ return n + 2; }` body
### Return type
```C++
[](int n) -> auto { return n + 2; }
```
* We can have auto as return type
* But the nice thing with lambda functions are that this
happens automatically if we don’t specify a return type
```C++
[](int n) -> { return n + 2; }
```
### std::transform
```C++
std::vector<int> v {1, 2, 3};
std::transform(v.begin(), v.end(), v.begin(),
                [](int n) { return n + 2; });
```
### Lambda Functions and STL
* There are many algorithms that take functions as
arguments
* Increadibly common that we use lambda functions in
this context
* The code becomes shorter and easier to read
* The user doesn’t have find the function declaration and
can see directly what the function does
```C++
auto add_2 = [](int n) { return n + 2; };//Give lambda functions a name
std::transform(v.begin(), v.end(),
                v.begin(), add_2);
```
* This way we can keep the abstraction of treating our
lambda as a function
* But we don’t have to force the reader to look for the
functions definition far way, because it is right above the
algorithm call
* This also means that add_2 is a variable, not a function
since it only exists locally in the current scope.
### `operator`()
```c++
struct My_Lambda
{
auto operator()(int n)
{
return n + 2;
}
};
```
* `operator`() is called the *function‐call* operator
* If we have an object `obj` that is of a type where
`operator`() is defined, then: `obj`(x) is translated to
`obj.operator`()(x)
* All classes that defines `operator`() are called function
objects
### Capture
```c++
auto add_2 {
[](int n)
{
return n + 2;
}};
My_Lambda add_2 {};
int x {2};
std::vector<int> v {1, 2, 3};
std::transform(v.begin(), v.end(), v.begin(),
              [](int n) { return n + x; });//Doesn't work!
```
* Within [] one can specify which variables should be
available inside the lambda function
* This is called the lambda functions *capture*
* This will create a local copy of the variables (these
copies are only available inside the lambda)
```c++
[x](int n)
{
  return n + x;
}
```
```c++
struct My_Lambda
{
  My_Lambda(int x)
    : x{x} { }
  auto operator()(int n)
  {
    return n + x;
  }
private:
  int x;
};
```
```c++
int x {2};
auto add_x {
[x](int n)
{
return n + x;
}};
```
```c++
int x {2};
My_Lambda add_x {x};
```
```c++
int x {2};
auto add_x = [x](int n) { return n + x; };
cout << add_x(5) << endl; // 7
x = 3;
cout << add_x(5) << endl; // 7
```
```c++
int x {2};
auto add_x = [&x](int n) { return n + x; };
cout << add_x(5) << endl; // 7
x = 3;
cout << add_x(5) << endl; // 8
```
* If we add a & before the variables name in the caputre
then it will be bound as a reference instead
```c++
[&x](int n)
{
  return n + x;
}
```
```c++
struct My_Lambda
{
  My_Lambda(int &x)
    : x{x} { }
  auto operator()(int n)
  {
    return n + x;
  }
private:
  int &x;
};
```
```c++
int x{2};
int y{3};
auto f = [&](int n) { return y*n + x; };//capture all, use [&x,&y]
std::vector<int> v {1, 2, 3};
std::transform(v.begin(), v.end(),
              v.begin(), f);
// v == {5, 8, 11}
```
* If we only write [&] then we capture *all* variables that
are available at the point of definition for the lambda
* In reality it only capture those variable that are used
inside the lambda function
* Captures everything as a reference
### Function objects in STL
```C++
std::vector<int> v {4, 6, 3, 7, 1};
std::sort(v.begin(), v.end());
// v == {1, 3, 4, 6, 7}

std::sort(v.begin(), v.end(),
[](int x, int y) { return x > y; });
// v == {7, 6, 4, 3, 1}

std::sort(v.begin(), v.end(), greater<int>{});
// v == {7, 6, 4, 3, 1}
```
* There are a couple of builtin function objects that can be
used with algorithms
* Some useful examples: std::less, std::greater,
std::plus, etc.
## 6 More on iterators
### std::for_each
```C++
std::vector<int> v {1, 2, 3, 4};
for (int e : v)
{
  cout << e << ' ';
}
```
```C++
std::vector<int> v {1, 2, 3, 4};
std::for_each(v.begin(), v.end(), [](int e)
{
cout << e << ' ';
});
```
* std::for_each is a relic from the old days
* C++ have developed to such a level that std::for_each
is almost never needed
* So avoid std::for_each whenever possible
### Print a container
```c++
std::vector<int> v {1, 2, 3, 4};
std::copy(v.begin(), v.end(),
          std::ostream_iterator<int>{cout});
//1234
```
```c++
std::vector<int> v {1, 2, 3, 4};
std::copy(v.begin(), v.end(),
          std::ostream_iterator<int>{cout," "});
//1 2 3 4
```
### std::ostream_iterator
* Is an OutputIterator
* Given std::ostream_iterator<int> it{cout} the
expression *it = 5 will print 5 to cout
* `++it` and `it++` does nothing
### Read from a stream
```C++
std::vector<int> v {
std::istream_iterator<int>{cin},
std::istream_iterator<int>{}
};
```
## 7 Smart pointers