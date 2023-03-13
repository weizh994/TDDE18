#include <iostream>
#include <vector>
#include <string>

using namespace std;

/* if implemented correctly this program
   should give the following output:

Gus eat Vegetarian Pizza.
Gus eat Calzone.
Gus eat Salad.
Sally does not want Vegetarian Pizza.
Sally does not want Calzone.
Sally eat Salad.
Pete eat Vegetarian Pizza.
Pete eat Calzone.
Pete does not want Salad.
Velma eat Vegetarian Pizza.
Velma does not want Calzone.
Velma eat Salad.
*/

class Food
{
public:
    Food(string const& name)
        : name{name}
    { }
    
    virtual ~Food() = default;

    virtual bool is_vegetarian() const = 0;
    
    string const name;
};

class Pizza : public Food
{
public:
    Pizza(string const& name, bool vegetarian)
        : Food{name}, vegetarian{vegetarian}
    { }

    bool is_vegetarian() const
    {
        return vegetarian;
    }

private:
    bool const vegetarian;
};

class Salad : public Food
{
public:
    using Food::Food;

    bool is_vegetarian() const
    {
        return true;
    }
};

class Guest
{
public:
    Guest(string const& name)
        : name{name}
    { }
    
    virtual ~Guest() = default;

    virtual bool prefer(Food const* food) const
    {
        return true;
    }

    void eat(Food const* food) const
    {
        cout << name;
        if (prefer(food))
        {
            cout << " eat ";
        }
        else
        {
            cout << " does not want ";
        }
        cout << food->name << endl;
    }
    
    string const name;
};

class Salad_Lover : public Guest
{
public:
    using Guest::Guest;
    
    bool prefer(Food const* food) const override
    {
        return dynamic_cast<Salad const*>(food);
    }
};

class Pizza_Lover : public Guest
{
public:
    using Guest::Guest;
    
    bool prefer(Food const* food) const override
    {
        return dynamic_cast<Pizza const*>(food);
    }
};

class Vegetarian : public Guest
{
public:
    using Guest::Guest;
    
    bool prefer(Food const* food) const override
    {
        return food->is_vegetarian();
    }
};

int main()
{
    vector<Guest*> guests {
        new Guest {"Gus"},
        new Salad_Lover {"Sally"},
        new Pizza_Lover {"Pete"},
        new Vegetarian {"Velma"}
    };

    // the true and false parameters represents
    // wheter or not the pizza is vegetarian
    vector<Food*> foods {
        new Pizza {"Vegetarian Pizza", true},
        new Pizza {"Calzone", false},
        new Salad {"Salad"}
    };

    for (auto guest : guests)
    {
        for (auto food : foods)
        {
            guest->eat(food);
        }
    }

    for (auto guest : guests)
    {
        delete guest;
    }

    for (auto food : foods)
    {
        delete food;
    }
}
