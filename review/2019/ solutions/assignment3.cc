#include <algorithm>
#include <fstream>
#include <map>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void print(map<string, int> const& m)
{
    vector<pair<string, int>> sorted {m.begin(), m.end()};
    sort(sorted.begin(), sorted.end(), [](auto& p1, auto& p2)
         { return p1.second > p2.second; });
    for (pair<string, int> const& p : sorted)
    {
        cout << p.first << " " << p.second << endl;
    }
}

int main(int argc, char** argv)
{
    if (argc <= 1)
    {
        cerr << "Error: No arguments given." << endl
             << "Usage: " << argv[0] << " FILE" << endl;
        return 1;
    }

    fstream ifs{argv[1]};
    if (!ifs)
    {
        cerr << "Error: No file named \"" << argv[1] << "\"" << endl
             << "Usage: " << argv[0] << "FILE" << endl;
        return 2;
    }

    map<string, int> people {};
    map<string, int> stocks {};
    string person;
    string stock;
    int amount;
    while (ifs >> person >> stock >> amount)
    {
        people[person] += amount;
        stocks[stock]  += amount;
    }


    print(people);
    cout << endl;
    print(stocks);
    
    return 0;
}
