#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <iterator>
using namespace std;
int main(int argc, char **argv)
{
  if (argc == 1)
  {
    cerr << "Error: No arguments given\n";
    cerr << "Usage: a.out FILE" << endl;
    return 1;
  }
  std::ifstream read_file(argv[1]);
  if (!read_file.is_open())
  {
    cerr << "Error: No file named \"" << argv[1] << "\"\n";
    cerr << "Usage: a.out FILE" << endl;
    return 1;
  }
  else
  {
    string Name{}, Stock{};
    int Amount{};
    std::map<std::string, int> person{};
    std::map<std::string, int> stock{};
    while (read_file >> Name >> Stock >> Amount)
    {
      person[Name]+=Amount;
      stock[Stock]+=Amount;
    }
    vector<pair<string, int>> v1{begin(person), end(person)};
    vector<pair<string, int>> v2{begin(stock), end(stock)};

    std::sort(v1.begin(), v1.end(), [](auto a, auto b)
              { return a.second > b.second; });
    std::sort(v2.begin(), v2.end(), [](auto a, auto b)
              { return a.second > b.second; });
    for (auto it : v1)
    {
      cout << it.first << " " << it.second << endl;
    }
    cout << "\n";
    for (auto it : v2)
    {
      cout << it.first << " " << it.second << endl;
    }
  }
}