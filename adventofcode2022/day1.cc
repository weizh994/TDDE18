#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main()
{
  string str;
  int max{0};
  int result{0};
  while (getline(cin, str))
  {
    if (str.empty())
    {
      cout << max << endl;
      result = 0;
    }
    else
    {
      result += std::stoi(str);
      if (max < result)
        max = result;
    }
  }
}
