#include <string>
#include <iostream>

using namespace std;

class GMap
{
public:
    GMap(): start{nullptr} {}
    ~GMap()
    {
	while( start )
	{
	    remove_tile();
	}
    }
    
    GMap(GMap const& other) = delete;
    GMap operator= (GMap const& other) = delete;
    
    GMap(GMap && other): GMap{}
    {
	swap(start, other.start);
    }

    GMap& operator= (GMap && other)
    {
	swap(start, other.start);
	return *this;
    }
    
    void add_tile(string name)
    {
	start = new Tile{name, start};
    }

    void remove_tile()
    {
	Tile* prev = start;
	start = start->next;
	delete prev;
    }

    void print() const
    {
	cout << "GMap:\n====\nEND |";
	Tile* current = start;
	while( current )
	{
	    cout << " <- " << current -> name;
			    current = current -> next;
	}
		cout << " <- | START" << endl;
    }
    
private:
    struct Tile
    {
	string name;
	Tile* next;
    };
    Tile* start;
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
