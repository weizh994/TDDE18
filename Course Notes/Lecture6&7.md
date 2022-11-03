# Inheritance & Polymorphism
[1. std::vector](#1std::vector)  
[2. Inheritance](#2-inheritance)  
[3. Polymorphism](#3-polymorphism)  
[4. Type of information](#4-type-of-information)  
[5. Exceptions](#5-exceptions)  
[6. Command-line argument](#6-command-line-argument)  

## 1. std::vector
### Storage
* Sequential Storage
* Each element in a ```std::vector``` is indexed, beginning
with ```0``` being the first element.
```C++
std::vector<int> v {5, 3, 1, 2};
```
|   5   |   3   |   1   |   2   |
| :---: | :---: | :---: | :---: |
|  [0]  |  [1]  |  [2]  |  [3]  |
* v.at(i) will check that element i exists, so it is
preferred over ```v[i]```.
```C++
v.at(1) = 4;
```
|   5   |   4   |   1   |   2   |
| :---: | :---: | :---: | :---: |
|  [0]  |  [1]  |  [2]  |  [3]  |

```C++
v.push_back(3);
```
|   5   |   4   |   1   |   2   |   3   |
| :---: | :---: | :---: | :---: | :---: |
|  [0]  |  [1]  |  [2]  |  [3]  |  [4]  |

* First element can be accessed with ```v.front()``` and last
with ```v.back()```.
```C++
v.back() = 6;
```
|   5   |   4   |   1   |   2   |   6   |
| :---: | :---: | :---: | :---: | :---: |
|  [0]  |  [1]  |  [2]  |  [3]  |  [4]  |

```C++
v.pop_back();
```
|   5   |   4   |   1   |   2   |
| :---: | :---: | :---: | :---: |
|  [0]  |  [1]  |  [2]  |  [3]  |

### Hint
* ```std::vector``` is defined in ```#include <vector>```
* Declared like this: ```std::vector<T>```.
* A ```std::vector<T>``` contains a sequence of values that
has the data type T.
* For example: ```std::vector<int>``` is a vector that stores
integers.
### Looping through
```C++
vector<string> words {...};
for (string const& word : words)
{
    cout << word << endl;
}
```
* There are multiple ways to loop through a `vector`
* A range based for‐loop looks like this: `for (int e : v)`
* each element is *copied* into `e`.
* Since copying is unnecessary for most cases where we
want to read the elements, it is recommended that you
loop through `v` like this: `for (int const& e : v)`

Example
```C++
#include <vector> 
#include <iostream>
using namespace std;
int main()
{
    vector<int> values{};
    int value{};
    // read values until ctrl
    while (cin >> value) {
        values.push_back(value);
    }
    // double each value
    for(int& e : values)
    {
        e = 2*e;
    }
}
```
## 2. Inheritance
### Terminology
* The class that contains the shared functionality is called
a *Base class*.
* A class that inherits another class (a base class) is called
a *Derived class*.
### Syntax
```C++
class Base
{
    // ...
};
class Derived : public Base
{
    // ...
};
```
* Derived *inherits* from Base.
### `protected`
* `proteceted` is the same as `private`, but with one difference: these
members are also accessible by all derived classes.
* Which means: `protected` things are secrets kept within
the family (inheritance hierarchy), while `private` things
are secrets kept by the individual (class).
```C++
// common code
class Shape
{
public:
    Shape(double w, double h)
        : width{w}, height{h} { }
    double get_height() const
    {
        return height;
    }
    double get_width() const
    {
        return width;
    }
protected:
    double width;
    double height;
};
```
### Delegating constructor
* width and height are `protected` in Shape.
* The constructor can therefore not initialize those
members.
* We can call the constructor of Shape which does in
fact have access to them to initalize these objects.
* You do this by adding `Shape{w, h}` to the start of the
member initialization list.
```c++
class Rectangle : public Shape
{
public:
    Rectangle(double w, double h)
        : Shape{w, h} { }
    double area() const
    {
    return width * height;
    }
};
class Triangle : public Shape
{
public:
    Triangle(double w, double h)
        : Shape{w, h} { }
    double area() const
    {
        return width * height / 2;
    }
};
```
## 3. Polymorphism
```C++
Triangle r{...};
Shape& ref {r};
```
```c++
class Shape
{
public:
    // ...
    virtual double area() const
    {
    return 0;
    }
    // ...
};
```
```c++
Shape s{};
Rectangle r{10, 15};
Triangle t{3, 4};

Shape* ptr {&s};
ptr->area(); // returns 0

ptr = &r;
ptr->area(); // returns 150

ptr = &t;
ptr->area(); // returns 6
```
### There are pitfalls...
```c++
class Cuboid : public Shape
{
public:
    Cuboid(double width, double height, double depth)
        : Shape{width, height}, depth{depth}
    { }
    double area() const
    {
        return 2.0 * (width * height + width * depth + height * depth);
    }
private:
    double depth;
};
```
```c++
Cuboid c{5, 7, 3};
Shape s {c}; // slicing
```
* a variable has a fixed size, so when the derived
class has more members than the base class, these will
be lost.
* This is called *slicing* since we slice away everything that
does not fit in the Shape‐object.
```c++
Cuboid c {2,3,4};
Shape s {c};
cout << s.area() << endl; // prints 0
```
```c++
Cuboid c {2,3,4};
Shape& s {c};
cout << s.area() << endl; // prints 24
```
When calling a member function:
1. through a non‐reference => Call the member function
2. through a non‐pointer => Call the member function
3. that is non‐virtual => Call the member function
4. otherwise => Call the overriden version
### Conclusion
# **Always use pointers or references when dealing with polymorphic objects!**
```c++
std::vector<Shape*> shapes {
    new Triangle{3, 4},
    new Rectangle{5, 6},
    new Cube{3, 5, 7}
};

for (Shape* shape : shapes)
{
    cout << shape->area() << endl;
}
```
* If we have a shared base class with `virtual` functions:
* We can have base class pointer to objects of derived classes
* This means we can store different types inside an `std::vector`.
* This is useful because we can now iterate over objects of
different types and get different results based on the
“real” type of the objects.
#### Example
```C++
class Complex_Shape : public Shape 
{
public:
    // ...
    double area() const {
    double sum{0.0};
    for (Shape* shape : shapes) 
    {
        sum += shape->area();
    }
    return sum;
    }
private:
    std::vector<Shape*> shapes;
};
```
```c++
{
Complex_Shape shape { ... };
cout << shape.area() << endl;
} // what happens here?
```
### Memory leak!
* When deleting ptr the compiler only sees the
Shape‐portion of the object.
* This means that it will call the destructor for Shape, even
though it is really a Complex_Shape.
* So the problem is essentially that the compiler gets
tricked into thinking you are working with a Shape
object.
* We solved this problem earlier by adding `virtual` to our
functions.
```C++
class Complex_Shape : public Shape 
{
public:
    // ...
    ~Complex_Shape() {
        for (Shape* shape : shapes) {
            delete shape;
        }
    }
    // ...
};
```
### `virtual`~destructor
```c++
class Shape
{
public:
    // ...
    virtual ~Shape() = default;
    // ...
};
```
* By declaring the destructor as `virtual` we are allowing
derived classes to override the behaviour with their own
implementation.
* This means that whenever the destructor is called
through a *pointer* or a *reference* it will call the
appropriate destructor.
* **Note**: The destructor of a class must also destroy the
base class, but this is handled by the compiler so we
don’t have to think about it.
### Conclusion
# **Always declare the destructor of a polymorphic base class as `virtual`!**

### Somethines humans make mistakes
```c++
class My_Shape : public Shape
{
public:
    // ...
    double area()
    {
        return 10.0;
    }
// ...
};
```
$\downarrow$
```c++
class My_Shape : public Shape
{
public:
    // ...
    double area() const //We forgot const!
    {
        return 10.0;
    }
    // ...
};
```
* The name, the parameters, specifiers etc. it all must
match with the base class version of the function.
$\downarrow$
```c++
class My_Shape : public Shape
{
public:
    // ...
    double area() override
    {
        return 10.0;
    }
    // ...
};
```
* If you mark a member function as override, compiler will check whether or not it succeded in overriding the function.
* ‚ If something is wrong, the compiler tell us and we can fix
it!
### Rule of thumb
# **Always mark functions that are meant to override as `override`!**

### pure‐virtual function
```c++
class Shape
{
public:
    // ...
    virtual ~Shape() = default;
    virtual double area() const = 0;
};
```
* You can add `= 0` at the end of a virtual function
declaration to mark it as a *pure‐virtual* function.
* This means that this function doesn’t have an
implementation.  
### Abstract class
> A class is abstract if it contains one or more pure‐virtual functions
```c++
Shape s1{1, 3}; // Error: abstract
Triangle t{1,3}; // OK: not abstract
Shape s2{t}; // Error: abstract
Shape& s3{t}; // OK: reference allowed
Shape* s4{&t}; // OK: pointer allowed
```
## 4. Type of information
### Static vs Dynamic type
* The *static* type of a variable is the type it is declared as
(it never changes)
* The *dynamic* type is the type of the object a pointer
points to
* The dynamic type can change to any class in the
hierarchy of the static type.

### Example
```C++
class Cuboid : public Shape
{
public:
    // ...
    virtual double volume() const
    {
        return width * height * depth;
    }
    //...
};
```
```c++
Shape* ptr {new Cuboid{3, 4, 5}};
// doesn't work, volume is not
// declared in Shape
cout << ptr->volume() << endl;
```
* Which functions you can call is directly related to the
static type.
* I.e. it doesn’t matter that the dynamic type of ptr is
Cuboid, we can’t call volume through a Shape pointer.
* Therefore we must, temporarily change the static type
to match the dynamic type.

* We can use `static_cast` to (temporarily) change `ptr`
into a `Cuboid*`, that way we can call volume().
* But this is very dangerous...
``` c++
Shape* ptr {new Rectangle{3, 4}};
cout << static_cast<Cuboid*>(ptr)->volume()
     << endl; //Segmentation Fault
```
### `dynamic_cast`
```c++
Shape* ptr1 {new Cuboid{3, 4, 5}};
Shape* ptr2 {new Rectangle{3, 4}};

Cuboid* c1 {dynamic_cast<Cuboid*>(ptr1)};
Cuboid* c2 {dynamic_cast<Cuboid*>(ptr2)};
// c1 is a pointer to a valid Cuboid object
// c2 == nullptr, since ptr2 does not
// point to a valid Cuboid object
```
* `dynamic_cast` is like `static_cast`, but before it
performs the conversion it will test that the dynamic
type is compatible (i.e. is derived from or equal to the
type we are casting to)
* if they are compatible it will return a valid pointer with
the specified static type,
* if they are not compatible it will return `nullptr`.  

Checking if dynamic type is compatible
```c++
Shape* ptr {...};
Cuboid* cuboid {dynamic_cast<Cuboid*>(ptr)};
if (cuboid != nullptr)
{
    // only print volume if it is a cuboid
    cout << cuboid->volume() << endl;
}
```
## 5. Exceptions(异常)
Model
```c++
int main()
{
    try
    {
        fun1();
        // ...
    }
    catch (std::exception& e)
    {
        cerr << e.what();
    }
}
```
```c++
void fun1()
{
    // ...
    fun2();
    // ...
    return;
}
```
```c++
void fun2()
{
    throw std::exception{""};
}
```
* An exception is an object we *throw*.
* Throwing an exception will abort the current function,
* it will move backwards in the function call chain until it
hits a *try‐catch* block.
* Throwing is seperate from returning.
* We should only throw exceptions when something went
wrong.

### `dynamic_cast`
```c++
#include <stdexcept>

int main()
{
    Rectangle r {3,4};
    Shape& s {c};
    try
    {
        cout << dynamic_cast<Cuboid&>(s).volume() << endl;
    }
    catch (std::bad_cast& e)
    {
        cout << "s is not a Cuboid!" << endl;
    }
    catch (std::exception& e)
    {
        cout << "Unknown error." << endl;
    }
}
```
## 6. Command-line argument

### Command‐line argument
```c++
int main(int argc, char** argv)
{
    for (int i{0}; i < argc; ++i)
    {
        cout << argv[i] << endl;
    }
}
```
```
$ ./a.out 10 20 30
./a.out
10
20
30
```
### Converting arguments
* `std::stoi(argv[1])` ‐ convert argv[1] to `int`
* `std::stod(argv[1])` ‐ convert argv[1] to `double`
* Using std::stringstream:
```c++
std::stringstream ss{};
ss << argv[1];
int number;
ss >> number;
```
```c++
vector<string> args { argv, argv + argc };
// now all arguments reside in the vector
// as std::string instead of C-strings
```