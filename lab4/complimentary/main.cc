#include "circuits.hpp"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// TODO: Complementary work needed: Compiling your code with the  
// "-Wall -Wextra -Wpedantic" flags should result in 0 warnings.      Done
//
// TODO: Complementary work needed: try/catch should only surround the                   
// functions which can throw the exceptions (stod, stoi). If the inputted                
// parameters are correct, the program should run without failure.                       
// Hint: Make sure to stop the program in a correct way such as return N, where N != 0. 
//  Done
// TODO: Complementary work needed: Do not call stod/stoi for the same the same value
// more than once.  Done
//

int main(int argc, char **argv)
{
  int num_iterations{0};
  int line_print{0};
  double time_step{0.0};
  double batteryVolt{0.0};
  int flag{std::stoi(argv[1])};
  vector<Component *> net;
  cout << flag << endl;
  try
  {
    if (flag != 1 && flag != 2 && flag != 3)
    {
      throw std::runtime_error("ERROR: CIRCUITS NOT EXSIST!\n");
    }
    initialCircuits(argc, argv,
                    num_iterations, line_print,
                    time_step, batteryVolt);
  }
  catch (const std::exception &e)
  {
    std::cerr << e.what() << std::endl;
    return 1;
  }

  if (flag == 1)
  {
    Connection p, r124, n, a;
    net.push_back(new Battery("Bat", batteryVolt, &p, &n));
    net.push_back(new Resistor("R1", 6.0, &p, &r124));
    net.push_back(new Resistor("R2", 4.0, &r124, &a));
    net.push_back(new Resistor("R3", 8, &a, &n));
    net.push_back(new Resistor("R4", 12, &r124, &n));
    simulate(net, num_iterations, line_print, time_step);
    deallocate_components(net);
  }
  else if (flag == 2)
  {
    Connection p, l, r, n;
    net.push_back(new Battery("Bat", batteryVolt, &p, &n));
    net.push_back(new Resistor("R1", 150.0, &p, &l));
    net.push_back(new Resistor("R2", 50.0, &p, &r));
    net.push_back(new Resistor("R3", 100, &l, &r));
    net.push_back(new Resistor("R4", 300.0, &l, &n));
    net.push_back(new Resistor("R5", 250, &n, &r));
    simulate(net, num_iterations, line_print, time_step);
    deallocate_components(net);
  }
  else
  {
    Connection p, l, r, n;
    net.push_back(new Battery("Bat", batteryVolt, &p, &n));
    net.push_back(new Resistor("R1", 150.0, &p, &l));
    net.push_back(new Resistor("R2", 50.0, &p, &r));
    net.push_back(new Capacitor("C3", 1.0, &l, &r));
    net.push_back(new Resistor("R4", 300.0, &l, &n));
    net.push_back(new Capacitor("C5", 0.75, &n, &r));
    simulate(net, num_iterations, line_print, time_step);
    deallocate_components(net);
  }
}
