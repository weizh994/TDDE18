#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class Adversary
{
public:
    Adversary(int hp): hp{hp} {}
    virtual ~Adversary() = default;

    virtual string description() const = 0;

    virtual string to_string() const
    {
	stringstream ss{};
	ss << "hp: " << hp;
	return ss.str();			  
    }
    
private:
    int hp;
};

class BanditGuard: public Adversary
{
public:
    BanditGuard(int hp, int movement): Adversary{hp}, movement{movement} {}
    
    virtual string description() const override
    {
	return "Bandit guard";
    }
    
    virtual string to_string() const override
    {
	stringstream ss{};
	ss << Adversary::to_string() << " " << "movement: " << movement;
	return ss.str();
    }
    
private:
    int movement;
};

class BanditArcher: public BanditGuard
{
public:
    BanditArcher(int hp, int movement, int range): BanditGuard{hp, movement}, range{range} {}

    virtual string description() const override
    {
	return "Bandit archer";
    }

    virtual string to_string() const override
    {
	stringstream ss{};
	ss << BanditGuard::to_string() << " " << "range: " << range;
	return ss.str();
    }
    
private:
    int range;
};


void display_adversaries(vector<Adversary*> const& adversaries)
{
    cout << "Adversaries:\n";
    cout << "=============\n";
    for( auto a: adversaries )
    {
	cout << a -> description() << ":\n" << a -> to_string() << "\n\n";
    }
    //cout << endl;
}

int main()
{
    vector<Adversary*> adversaries{};
    adversaries.push_back(new BanditArcher {1, 3, 2});
    adversaries.push_back(new BanditGuard {2, 4});
    adversaries.push_back(new BanditGuard {3, 3});
    display_adversaries(adversaries);

    for( auto a: adversaries )
    {
	delete(a);
    }
}

int main()
{
    vector<Adversary> adversaries{};
    adversaries.push_back(BanditArcher {1, 3, 2});
    adversaries.push_back(BanditGuard {2, 4});
    adversaries.push_back(BanditGuard {3, 3});
    display_adversaries(adversaries);
}
