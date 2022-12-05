#include <iostream>
#include <string>
using namespace std;
int main()
{
  string str;
  int score{0};
  while (getline(cin, str))
  {
    if (str[2] == 'X')
    {
      score += 0;
      if (str[0] == 'A')
      {
        score += 3;
      }
      else if (str[0] == 'B')
      {
        score += 1;
      }
      else if (str[0] == 'C')
      {
        score += 2;
      }
    }
    else if (str[2] == 'Y')
    {
      score += 3;
      if (str[0] == 'A')
      {
        score += 1;
      }
      else if (str[0] == 'B')
      {
        score += 2;
      }
      else if (str[0] == 'C')
      {
        score += 3;
      }
    }
    else if (str[2] == 'Z')
    {
      score += 6;
      if (str[0] == 'A')
      {
        score += 2;
      }
      else if (str[0] == 'B')
      {
        score += 3;
      }
      else if (str[0] == 'C')
      {
        score += 1;
      }
    }
    else
    {
      break;
    }
    str = "000";
  }
  cout << score << endl;
}