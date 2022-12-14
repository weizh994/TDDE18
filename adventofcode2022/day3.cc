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
    for (int i = 0; i < length / 2; i++)
    {
      std::map<char, int>::iterator it;
      it = m.find(str[i]);
      if (it == m.end())
      {
        m[str[i]] = 1;
      }
    }
    /*for (auto const &pair : m)
    {
      std::cout << "{" << pair.first << ": " << pair.second << "}\n";
    }*/
    for (int i = length / 2; i < length; i++)
    {
      std::map<char, int>::iterator it;
      it = m.find(str[i]);
      if (it != m.end())
      {
        if (m[str[i]] == 1)//排除在后半部份队列中重复的字母
        {
          if (str[i] <= 'Z' && str[i] >= 'A')
          {
            score += ((int)str[i] - 38);
          }
          else
          {
            score += ((int)str[i] - 96);
          }
        }
        m[str[i]]++;
      }
    }
    cout << score << endl;
  }
}