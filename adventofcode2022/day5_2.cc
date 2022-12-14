#include <stack>
#include <vector>
#include <map>
#include <string>
#include <iostream>
using namespace std;
int main()
{
  stack<char> s1, s2, s3, s4, s5, s6, s7, s8, s9, s10;
  string o1{"WDGBHRV"}, o2{"JNGCRF"}, o3{"LSFHDNJ"}, o4{"JDSV"}, o5{"SHDRQWNV"}, o6{"PGHCM"}, o7{"FJBGLZHC"}, o8{"SJR"}, o9{"LGSRBNVM"};
  map<int, stack<char> *> a{{1, &s1}, {2, &s2}, {3, &s3}, {4, &s4}, {5, &s5}, {6, &s6}, {7, &s7}, {8, &s8}, {9, &s9}};
  for (int i = 0; i < static_cast<int>(o1.length()); i++)
    s1.push(o1[i]);
  for (int i = 0; i < static_cast<int>(o2.length()); i++)
    s2.push(o2[i]);
  for (int i = 0; i < static_cast<int>(o3.length()); i++)
    s3.push(o3[i]);
  for (int i = 0; i < static_cast<int>(o4.length()); i++)
    s4.push(o4[i]);
  for (int i = 0; i < static_cast<int>(o5.length()); i++)
    s5.push(o5[i]);
  for (int i = 0; i < static_cast<int>(o6.length()); i++)
    s6.push(o6[i]);
  for (int i = 0; i < static_cast<int>(o7.length()); i++)
    s7.push(o7[i]);
  for (int i = 0; i < static_cast<int>(o8.length()); i++)
    s8.push(o8[i]);
  for (int i = 0; i < static_cast<int>(o9.length()); i++)
    s9.push(o9[i]);
  int j{}, o{}, t{};
  string tmp1, tmp2, tmp3;
  while (cin >> tmp1)
  {
    if (tmp1 == "c")
      break;
    cin >> j;
    cin >> tmp2;
    cin >> o;
    cin >> tmp3;
    cin >> t;
    for (int i = 0; i < j; i++)
    {
      s10.push(a[o]->top());
      a[o]->pop();
    }
    for (int i = 0; i < j; i++)
    {
      a[t]->push(s10.top());
      s10.pop();
    }
  }
  for (int i = 1; i <= 9; i++)
  {
    cout << a[i]->top();
  }
  cout << endl;
}
