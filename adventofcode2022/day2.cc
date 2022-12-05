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
      score += 1;
      if (str[0] == 'A')
      {
        score += 3;
      }
      else if (str[0] == 'B')
      {
        score += 0;
      }
      else if (str[0] == 'C')
      {
        score += 6;
      }
    }
    else if (str[2] == 'Y')
    {
      score += 2;
      if (str[0] == 'A')
      {
        score += 6;
      }
      else if (str[0] == 'B')
      {
        score += 3;
      }
      else if (str[0] == 'C')
      {
        score += 0;
      }
    }
    else if (str[2] == 'Z')
    {
      score += 3;
      if (str[0] == 'A')
      {
        score += 0;
      }
      else if (str[0] == 'B')
      {
        score += 6;
      }
      else if (str[0] == 'C')
      {
        score += 3;
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