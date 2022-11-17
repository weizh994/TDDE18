#include "circuits.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

void simulate(vector<Component *> net, int num_iterations, int line_print, double time_step)
{
  for (Component *const &Component : net)
  {
    cout << setw(12) << Component->returnName();
  }
  cout << endl;
  for (Component *const &Component : net)
  {
    cout << right << setw(6) << "Volt" << right << setw(6) << "Curr";
  }
  cout << fixed << setprecision(2) << endl;
  for (size_t i = 0; i < line_print; i++)
  {
    for (int j = 0; j < num_iterations / line_print; j++)
    {
      for (Component *const &Component : net)
      {
        Component->changeVolt(time_step);
      }
    }
    for (Component *const &Component : net)
    {
      cout << setw(6) << Component->getVolt() << setw(6) << Component->returnCurr();
    }
    cout << endl;
  }
}

int main(int argc, char **argv)
{
  int num_iterations{0};
  int line_print{0};
  double time_step{0.0};
  double batteryVolt{0.0};

  Connection p, l, r, n;
  vector<Component *> net;
  Battery b1("Bat", 24.0, &p, &n);
  Resistor r1("R1", 150.0, &p, &l);
  Resistor r2("R2", 50.0, &p, &r);
  Capacitor c3("C3", 1.0, &l, &r);
  Resistor r4("R4", 300.0, &l, &n);
  Capacitor c5("C5", 0.75, &n, &r);
  net.push_back(&b1);
  net.push_back(&r1);
  net.push_back(&r2);
  net.push_back(&c3);
  net.push_back(&r4);
  net.push_back(&c5);
  simulate(net, 20000, 10, 0.1);
  // deallocate_components(net);
}