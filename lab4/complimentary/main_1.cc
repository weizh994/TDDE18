#include "circuits_2.hpp"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// TODO: Complementary work needed: Your program doesn't work as it is
// supposed to do. Make sure to handle the command line arguments
// correctly. You should be able to run your program by writing
// ./a.out 200000 10 0.01 24 in the terminal. Rigth now it throws an
// error.

int main(int argc, char **argv)
{
  int num_iterations{0};
  int line_print{0};
  double time_step{0.0};
  double batteryVolt{0.0};
  double StringtoInt{0.0};
  
    initialCircuits(argc, argv, num_iterations, line_print, time_step, batteryVolt);
    vector<Component *> net;
    try
    {
    StringtoInt=std::stoi(argv[1]);
    }
   catch (const std::invalid_argument & e) 
   {
      std::cout << e.what() << "\n";
    }
  catch (const std::out_of_range & e) 
    {
      std::cout << e.what() << "\n";
    }
    if (StringtoInt == 1)
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
    else if (StringtoInt == 2)
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
    else if (StringtoInt == 3)
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
    else
    {
      return -1;
    }
      
}
