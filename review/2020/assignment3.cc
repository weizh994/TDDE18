#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class Adversary
{
protected:
    int health;

public:
    Adversary(int a) : health{a} {}
    virtual ~Adversary() = default;
    virtual string description() = 0;
    virtual string to_string() { return "hp: " + std::to_string(health); }
};

class BanditGuard : public Adversary
{
protected:
    int mobility;

public:
    BanditGuard(int a, int b) : Adversary{a}, mobility{b} {}
    ~BanditGuard() override {}
    string description() override { return "Bandit guard"; }
    string to_string() override { return "hp: " + std::to_string(health) +
                                         " movement: " + std::to_string(mobility); }
};

class BanditArcher : public BanditGuard
{
private:
    int range;

public:
    BanditArcher(int a, int b, int c) : BanditGuard{a, b}, range{c} {}
    ~BanditArcher() override {}
    string description() override { return "Bandit archer"; }
    string to_string() override { return "hp: " + std::to_string(health) +
                                         " movement: " + std::to_string(mobility) +
                                         " range: " + std::to_string(range); }
};

void display_adversaries(vector<Adversary *> &v)
{
    for (auto i : v)
    {
        delete i;
    }
}

int main()
{
    vector<Adversary *> adversaries{};
    adversaries.push_back(new BanditArcher{1, 3, 2});
    adversaries.push_back(new BanditGuard{2, 4});
    adversaries.push_back(new BanditGuard{3, 3});
    cout << "Adversaries:\n=============" << endl;
    for (auto i : adversaries)
    {
        cout << i->description() +":\n";
        cout << i->to_string() << endl;
        cout << endl;
    }

    display_adversaries(adversaries);
}
