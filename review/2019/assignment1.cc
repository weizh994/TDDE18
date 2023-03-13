#include <iostream>
#include <string>
using namespace std;
int main()
{
  int iterations;
  cout << "How many iterations? ";
  cin >> iterations;
  string oldString{"A"};
  for (int i = 0; i <= iterations; i++)
  {
    string newString{};
    cout << oldString << endl;
    for (int j = 0; j < (int)oldString.length(); j++)
    {
      if (oldString[j] == 'A')
      {
        newString.append("AT");
      }
      else if (oldString[j] == 'T')
      {
        newString.append("GC");
      }
      else if (oldString[j] == 'G')
      {
        newString.append("G");
      }
      else if (oldString[j] == 'C')
      {
        newString.append("TA");
      }
    }

    oldString = newString;
  }
  return 0;
}