#include "circuits.hpp"
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
  Connection p, n;
  vector<Component *> net;
  Battery b("Bat", 24.0, p, n);
  // net.push_back(&b);
  // cout << net[0]->returnCurr() << endl;
  cout << "Volt: " << b.getVolt()
       << "Curr:" << b.returnCurr()
       << endl;
  // simulate(net, 10000, 10, 0.1);
  // deallocate_components(net);
}