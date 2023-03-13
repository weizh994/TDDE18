#include <iostream>
#include <string>
#include <vector>
#include <iterator>

using namespace std;

vector<int> string_to_vector_int(string s)
{
  vector<int> v;
  for (auto c : s)
  {
    v.push_back(c - '0');
  }
  return v;
}

int main()
{
  vector<int> v = string_to_vector_int("234");
  for (auto c : v)
  {
    cout << c << endl;
  }
  cout << v.size() << endl;
}