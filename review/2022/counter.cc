#include <string>
#include <iostream>
#include <istream>
#include <ostream>

class Counter
{
private:
    std::string name;
    int value;

public:
    Counter(std::string n, int v) : name{n}, value{v} {}
    ~Counter() {}
    friend std::ostream &operator<<(std::ostream &os, Counter const &c)
    {
        return (os << "[" << c.name << "] = " << std::to_string(c.value));
    }
    Counter &operator++()
    {
        ++value;
        return *this;
    }
    Counter operator++(int)
    {
        Counter temp{*this};
        ++(*this);
        return temp;
    }
    Counter operator+=(int n)
    {
        value += n;
        return *this;
    }
};

Counter operator+(Counter &c, int n)
{
    Counter temp{c};
    return temp += n;
}
Counter operator+(int n, Counter &c)
{
    return c + n;
}

int main()
{
    Counter my_counter{"My Counter", 1};
    std::cout << my_counter << std::endl;

    std::cout << ++my_counter << std::endl;

    std::cout << my_counter++ << std::endl;

    my_counter += 3;
    std::cout << my_counter << std::endl;

    std::cout << (my_counter + 5) << std::endl;

    std::cout << (5 + my_counter) << std::endl;
}
