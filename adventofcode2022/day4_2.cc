#include <iostream>
#include <string>
using namespace std;
int main()
{
  unsigned int a, b, c, d;
  int count{};
  while (cin >> a)
  {
    cin.ignore(numeric_limits<streamsize>::max(), '-');
    cin >> b;
    cin.ignore(numeric_limits<streamsize>::max(), ',');
    cin >> c;
    cin.ignore(numeric_limits<streamsize>::max(), '-');
    cin >> d;
    if (a <= c && b >= d)
    {
      count++;
    }
    else if (a >= c && b <= d)
    {
      count++;
    }
    else if (a <= c && b >= c)
    {
      count++;
    }
    else if (a <= d && b >= d)
    {
      count++;
    }
    }
  cout << count << endl;
}