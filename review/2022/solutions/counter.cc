#include <string>
#include <iostream>

class Counter
{
public:
    Counter(std::string const& name, int start)
        : name{name}, value{start}
    { }

    Counter& operator+=(int rhs)
    {
        value += rhs;
        return *this;
    }

    Counter& operator++()
    {
        return *this += 1;
    }

    Counter operator++(int)
    {
        Counter tmp{*this};
        ++(*this);
        return tmp;
    }

    friend std::ostream& operator<<(std::ostream& os, Counter const& counter)
    {
        os << '[' << counter.name << "] = " << counter.value;
        return os;
    }
    
private:
    std::string name;
    int value;
};

Counter operator+(Counter const& lhs, int rhs)
{
    return Counter{lhs} += rhs;
}

Counter operator+(int lhs, Counter const& rhs)
{
    return rhs + lhs;
}

int main()
{
    Counter my_counter {"My Counter", 1};
    std::cout << my_counter << std::endl;

    std::cout << ++my_counter << std::endl;
    
    std::cout << my_counter++ << std::endl;

    my_counter += 3;
    std::cout << my_counter << std::endl;

    std::cout << (my_counter + 5) << std::endl;

    std::cout << (5 + my_counter) << std::endl;
}
