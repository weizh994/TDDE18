#include <iostream>
#include <string>
#include <map>

using namespace std;
using coordinate = std::pair<int, int>;
using hexagon = std::string;

class Tile
{
private:
    string name;
    map<coordinate, hexagon> hexes;

public:
    Tile(string n) : name{n} {}
    ~Tile(){}
    void create_hexagon(coordinate c1, hexagon h) { hexes[c1] = h; }
    void print_hexagon(coordinate c)
    {
        cout<<"Hexagon("<<c.first<<", "<<c.second<<"): ["
        <<hexes[c][hexes[c].length()-1]<<"]"<<endl;
    }
    void push(coordinate c, char ch)
    {
        hexes[c] += ch;
    }
    void print_tile()
    {
        cout << name << endl;
        for(auto c : hexes){
            print_hexagon(c.first);
        }
    }
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

// coordinate and hexagon that are used in the main program above is
// just an alias for std::pair<int, int> and std::string respectively.
// See the using-directive on line 5 and 6. If we did not create these
// aliases the main program would be:
// int main()
// {
//     Tile b1{"b1"};
//     b1.create_hexagon(pair<int, int>{0, 0}, string{"HXOX"});
//     b1.print_hexagon(pair<int, int>{0, 0});
//     b1.push(pair<int, int>{0, 0}, 'O');
//     b1.create_hexagon(pair<int, int>{0, 1}, string{"OXXXH"});
//     b1.print_tile();
// }
