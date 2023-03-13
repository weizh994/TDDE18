#include <string>
#include <vector>
#include <iostream>
#include <iomanip>

using namespace std;

struct Effect
{
    std::string name;
    std::string description;
};

class Card
{
private:
    Effect top;
    Effect bottom;
    int initiative;

public:
    Card(Effect const &e1, Effect const &e2, int value) : top{e1}, bottom{e2}, initiative{value} {}
    ~Card() {}
    bool operator<(Card const &other) const
    {
        return initiative < other.initiative;
    }
    friend ostream &operator<<(ostream &os, Card const &c)
    {
        os << "Top: " << c.top.name << "\n"
           << "Initiative: " << c.initiative << "\n"
           << "Bottom: " << c.bottom.name << endl;
        return os;
    }
};

class Hand
{
private:
    vector<Card> cards;

public:
    Hand():cards{} {}
    ~Hand() {}
    void draw(Card const &c) { cards.push_back(c); }
    void print(ostream &os)
    {
        for (auto card : cards)
        {
            os << card << '\n'
               << endl;
        }
    }
};

int main()
{
    Effect aid{"Aid from the Ether", "Heals an ally for 3 health"};
    Effect ally{"Summon Mystic Ally", "Summon minion and gain 2 xp"};
    Effect icelance{"Ice Lance", "Deals 2 damage"};
    Effect ridethewind{"Ride the Wind", "Move 8 spaces"};

    Card card1{aid, ally, 91};
    Card const card2{icelance, ridethewind, 25};
    cout << "Card1:\n"
         << card1 << '\n'
         << endl;

    Hand hand{};
    hand.draw(card1);
    hand.draw(card2);
    // hand.print(cout); // could also implement operator<<: cout << hand;

    cout << "card1 is less than card2: " << boolalpha << (card1 < card2) << endl;
    cout << "card2 is less than card1: " << boolalpha << (card2 < card1) << endl;
}
