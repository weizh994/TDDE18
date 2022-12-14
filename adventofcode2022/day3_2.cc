#include <iostream>
#include <map>
#include <string>
#include <iterator>
using namespace std;
int main()
{
  string str;
  int score{};
  while (getline(cin, str))
  {
    map<char, int> m{};
    int length = str.length();
    for (int i = 0; i < length; i++)
    {
      std::map<char, int>::iterator it;
      it = m.find(str[i]);
      if (it == m.end())
      {
        m[str[i]] = 1;
      }
    }
    getline(cin, str); // second
    length = str.length();
    for (int i = 0; i < length; i++)
    {
      std::map<char, int>::iterator it;
      it = m.find(str[i]);
      if (it != m.end())
      {
        if (m[str[i]] == 1)
        {
          m[str[i]]++;
        }
      }
    }
    getline(cin, str); // third
    length = str.length();
    for (int i = 0; i < length; i++)
    {
      std::map<char, int>::iterator it;
      it = m.find(str[i]);
      if (it != m.end())
      {
        if (m[str[i]] == 2) // exclude repeat char
        {
          if (str[i] <= 'Z' && str[i] >= 'A')
          {
            score += ((int)str[i] - 38);
          }
          else
          {
            score += ((int)str[i] - 96);
          }
          m[str[i]]++;
        }
      }
    }
    cout << score << endl;
  }
}