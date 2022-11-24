#include "circuits.hpp"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char **argv)
{
  int num_iterations{0};
  int line_print{0};
  double time_step{0.0};
  double batteryVolt{0.0};
  try
  {
    initialCircuits(argc, argv, num_iterations, line_print, time_step, batteryVolt);
    vector<Component *> net;
    if (std::stoi(argv[1]) == 1)
    {
      Connection p, r124, n, a;
      net.push_back(new Battery("Bat", batteryVolt, &p, &n));
      net.push_back(new Resistor("R1", 6.0, &p, &r124));
      net.push_back(new Resistor("R2", 4.0, &r124, &a));
      net.push_back(new Resistor("R3", 8, &a, &n));
      net.push_back(new Resistor("R4", 12, &r124, &n));
    }
    else if (std::stoi(argv[1]) == 2)
    {
      Connection p, l, r, n;
      net.push_back(new Battery("Bat", batteryVolt, &p, &n));
      net.push_back(new Resistor("R1", 150.0, &p, &l));
      net.push_back(new Resistor("R2", 50.0, &p, &r));
      net.push_back(new Resistor("R3", 100, &l, &r));
      net.push_back(new Resistor("R4", 300.0, &l, &n));
      net.push_back(new Resistor("R5", 250, &n, &r));
    }
    else if (std::stoi(argv[1]) == 3)
    {
      Connection p, l, r, n;
      net.push_back(new Battery("Bat", batteryVolt, &p, &n));
      net.push_back(new Resistor("R1", 150.0, &p, &l));
      net.push_back(new Resistor("R2", 50.0, &p, &r));
      net.push_back(new Capacitor("C3", 1.0, &l, &r));
      net.push_back(new Resistor("R4", 300.0, &l, &n));
      net.push_back(new Capacitor("C5", 0.75, &n, &r));
    }
    else
      throw std::runtime_error("ERROR: CIRCUITS NOT EXSIST!");
    simulate(net, num_iterations, line_print, time_step);
    deallocate_components(net);
  }
  catch (const std::exception &e)
  {
    std::cerr << e.what() << std::endl;
  }
}