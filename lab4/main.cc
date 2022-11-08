#include "circuits.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

void simulate(vector<Component *> net, int const &num_iterations, int const &line_print, double const time_step)
{
  for (Component *const &Component : net)
  {
    cout << Component->returnName() << setw(10);
  }
  cout << setprecision(2) << endl;
  for (Component *const &Component : net)
  {
    cout << "Volt" << setw(5) << "Curr" << setw(5);
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
}

int main()
{
  Connection p, n, a, b;
  vector<Component *> net;
  Battery b1("Bat", 24.0, &p, &n);
  Resistor r1("R1", 6.0, &p, &a);
  Resistor r2("R2", 4.0, &a, &b);
  Resistor r3("R3", 8.0, &b, &n);
  Resistor r4("R4", 12.0, &a, &n);
  net.push_back(&b1);
  net.push_back(&r1);
  net.push_back(&r2);
  net.push_back(&r3);
  net.push_back(&r4);
  simulate(net, 10000, 10, 0.1);
  // deallocate_components(net);
}