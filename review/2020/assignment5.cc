#include <string>
#include <iostream>

using namespace std;

class GMap
{
public:
    GMap() : start{nullptr} {}
    GMap(GMap &&otherMap)
    {
        start = otherMap.start;
        otherMap.start = nullptr;
    }
    ~GMap()
    {
        while (start)
        {
            remove_tile();
        }
    }
    GMap(GMap const &other) = delete;
    GMap operator=(GMap const &other) = delete;
    void add_tile(string name)
    {
        start = new Tile{name, start};
    }

    void remove_tile()
    {
        Tile *prev = start;
        start = start->next;
        delete prev;
    }

    GMap &operator=(GMap &&rightMap)
    {
        this->~GMap();
        start = rightMap.start;
        rightMap.start = nullptr;
        return *this;
    }

    /* GMap &operator=(GMap const &rightMap)
    {
        this->~GMap();
        GMap tm1;
        Tile *current = rightMap.start;
        while (current)
        {
            tm1.add_tile(current->name);
            current = current->next;
        }
        current = tm1.start;
        while (current)
        {
            add_tile(current->name);
            current = current->next;
        }
        tm1.~GMap();
        return *this;
    }
 */
    void print() const
    {
        cout << "GMap:\n====\nEND |";
        Tile *current = start;
        while (current)
        {
            cout << " <- " << current->name;
            current = current->next;
        }
        cout << " <- | START" << endl;
    }

private:
    struct Tile
    {
        string name;
        Tile *next;
    };
    Tile *start;
};

int main()
{
    GMap gmap{};
    gmap.add_tile("a1");
    gmap.add_tile("c4");
    gmap.add_tile("m2");
    gmap.print();

    return 0;
}
