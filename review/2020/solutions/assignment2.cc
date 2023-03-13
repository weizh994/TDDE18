#include <iostream>
#include <map>
#include <string>

using namespace std;
using coordinate = std::pair<int, int>;
using hexagon = std::string;

class Tile
{
public:
    Tile(string name): name{name}, hexagones{} {}

    void create_hexagon(coordinate const& coord, hexagon const& str)
    {
	hexagones.emplace(make_pair(coord, str));
    }

    void print_tile(ostream& os = cout) const
    {
	os << name << ":\n";
	for( auto h: hexagones )
	{
	    print_hexagon(h.first, os);
	}
    }

    void print_hexagon(coordinate const& coord, ostream& os = cout) const
    {
	os << "Hexagon(" << coord.first << ", " << coord.second << "): ";
	os << "[" << hexagones.at(coord).back() << "]";
	os << endl;
    }

    void push(coordinate const& coord, char c)
    {
	hexagones.at(coord).push_back(c);
    }
    
private:
    string name;
    map<coordinate, string> hexagones;
};

int main()
{
    Tile b1{"b1"};
    b1.create_hexagon(coordinate{0, 0}, hexagon{"HXOX"});
    b1.print_hexagon(coordinate{0, 0});
    b1.push(coordinate{0, 0}, 'O');
    b1.create_hexagon(coordinate{0, 1}, hexagon{"OXXXH"});
    b1.print_tile();
}
