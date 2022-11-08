#include "circuits.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

/*void simulate(vector<Component *> net, int const &num_iterations, int const &line_print, double const time_step)
{
  for (Component *const &Component : net)
  {
    cout << Component->returnName() << setw(5);
  }
  cout << setprecision(2) << endl;
  for (size_t i = 0; i < line_print; i++)
  {
    for (int j = 0; j <= num_iterations / line_print; j++)
    {
      for (Component *const &Component : net)
      {
        Component->changeVolt(time_step);
      }
    }
    for (Component *const &Component : net)
    {
      cout << " " << Component->getVolt() << " " << Component->returnCurr();
    }
    cout << endl;
  }
}*/

int main()
{
  Connection p, n;
  //vector<Component *> net;
  Battery b("Bat", 24.0,&p, &n);
  // net.push_back(&b);
  // cout << net[0]->returnCurr() << endl;
  cout<<b.returnName()<<endl;
  cout << "Volt: " << b.getVolt()
       << "Curr:" << b.returnCurr()
       << endl;
  // simulate(net, 10000, 10, 0.1);
  // deallocate_components(net);
}