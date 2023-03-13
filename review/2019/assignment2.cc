#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <typeinfo>

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
protected:
    string const name;
    friend class Guest;

public:
    Food(string const &str) : name{str} {}
    virtual ~Food() = default;
    virtual bool is_vegetarian() const = 0;
};

class Pizza : public Food
{
protected:
    bool vegetarian_pizza;

public:
    Pizza(string const &str, bool tf) : Food{str}, vegetarian_pizza{tf} {}
    ~Pizza() override {}
    bool is_vegetarian() const override
    {
        return vegetarian_pizza;
    }
};

class Pizza_Roll : public Pizza
{
    using Pizza::is_vegetarian;
    using Pizza::Pizza;
};

class Salad : public Food
{
public:
    Salad(string const &str) : Food{str} {}
    ~Salad() override {}
    bool is_vegetarian() const override
    {
        return true;
    }
};

class Guest
{
protected:
    string const name;

public:
    Guest(string const &str) : name{str} {}
    virtual ~Guest() = default;
    virtual bool prefer(Food *food) const
    {
        return true;
    }
    void eat(Food *Food) const
    {
        if (prefer(Food))
        {
            cout << name << " eat " << Food->name << endl;
        }
        else
        {
            cout << name << " does not want " << Food->name << endl;
        }
    }
};

class Salad_Lover : public Guest
{
public:
    Salad_Lover(string const &str) : Guest{str} {};
    ~Salad_Lover() override {}
    bool prefer(Food *Food) const override
    {
        return dynamic_cast<Salad const *>(Food);
    }
};
class Pizza_Lover : public Guest
{
public:
    Pizza_Lover(string const &str) : Guest{str} {};
    ~Pizza_Lover() override {}
    bool prefer(Food *Food) const override
    {
        return dynamic_cast<Pizza const *>(Food);
    }
};
class Vegetarian : public Guest
{
public:
    Vegetarian(string const &str) : Guest{str} {};
    ~Vegetarian() override {}
    bool prefer(Food *Food) const override
    {
        return Food->is_vegetarian();
    }
};

int main()
{

    vector<Guest *> guests{

        new Guest{"Gus"},
        new Salad_Lover{"Sally"},
        new Pizza_Lover{"Pete"},
        new Vegetarian{"Velma"}};

    // the true and false parameters represents
    // wheter or not the pizza is vegetarian
    vector<Food *> foods{
        new Pizza{"Vegetarian Pizza", true},
        new Pizza{"Calzone", false},
        new Pizza_Roll{"Ham Pizza", false},
        new Pizza_Roll{"Vegetarian Pizza", true},
        new Salad{"Salad"}};

    for (auto guest : guests)
    {
        for (auto food : foods)
        {
            // guest.eat(food);
            // or
            guest->eat(food);
        }
    }
    for (auto guest : guests)
        delete guest;
    for (auto food : foods)
        delete food;
}
