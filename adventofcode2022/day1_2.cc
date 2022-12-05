#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main()
{
  string str;
  int max[3]{0};
  int result{0};
  while (getline(cin, str))
  {
    if (str.empty())
    {
      cout << max[0] + max[1] + max[2] << endl;
      result = 0;
    }
    else
    { 
      result += std::stoi(str);
      if (max[0] < result)
      {
        max[2] = max[1];
        max[1] = max[0];
        max[0] = result;
      }
      else if (max[1] < result)
      {
        max[2] = max[1];
        max[1] = result;
      }
      else if (max[2] < result)
      {
        max[2] = result;
      }
    }
  }
}
