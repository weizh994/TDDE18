#include <string>
#include <vector>
#include <iostream>
#include <iomanip>

using namespace std;

struct Effect
{
    string name;
    string description;
};

class Card
{
public:
    Card(Effect top, Effect bottom, short unsigned int initiative):
	top{top}, bottom{bottom}, initiative{initiative}
    {}

    bool operator < (Card const& other) const
    {
	return initiative < other.initiative;
    }

    friend ostream& operator << (ostream& os, Card const& card)
    {
	return os << "Top: " << card.top.name <<
	    "\nInitiative: " << card.initiative <<
	    "\nBottom: " << card.bottom.name;
    }
    
private:
    Effect top;
    Effect bottom;
    short unsigned int initiative;
};

class Hand
{
public:
    Hand(): cards{} {}

    void draw(Card const& card)
    {
	cards.push_back(card);
    }

    void print(ostream& os)
    {
	for(auto card : cards)
	{
	    os << card << '\n' << endl;
	}
    }
    
private:
    vector<Card> cards;
};

int main()
{
    Effect aid{"Aid from the Ether", "Heals an ally for 3 health"};
    Effect ally{"Summon Mystic Ally", "Summon minion and gain 2 xp"};
    Effect icelance{"Ice Lance", "Deals 2 damage"};
    Effect ridethewind{"Ride the Wind", "Move 8 spaces"};

    Card card1{aid, ally, 91};
    Card const card2{icelance, ridethewind, 25};
    cout << "Card1:\n" << card1 << '\n' << endl;

    Hand hand{};
    hand.draw(card1);
    hand.draw(card2);
    hand.print(cout);

    cout << "card1 is less than card2: " << boolalpha << (card1 < card2) << endl;
    cout << "card2 is less than card1: " << boolalpha << (card2 < card1) << endl;

	       
}
