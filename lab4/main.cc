#include "circuits.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <initializer_list>
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
void deallocate_components(vector<Component *> net)
{
  for (Component *Component : net)
  {
    delete Component;
  }
}

void initialCircuits(int argc, char **argv, int &num_iterations, int &line_print, double &time_step, double &batteryVolt)
{
  std::vector<std::string> args{argv, argv + argc};
  if (args.size() != 5)
    throw std::runtime_error("ERROR: THE NUMBER OF INPUT IS INCORRECT!");
  else
  {
    num_iterations = std::stoi(args[1]);
    line_print = std::stoi(args[2]);
    time_step = std::stod(argv[3]);
    batteryVolt = std::stod(argv[4]);
    if (num_iterations < line_print)
    {
      throw std::runtime_error("ERROR: THE INPUT IS ILLEGAL!");
    }
  }
}

int main(int argc, char **argv)
{
  int num_iterations{0};
  int line_print{0};
  double time_step{0.0};
  double batteryVolt{0.0};
  try
  {
    initialCircuits(argc, argv, num_iterations, line_print, time_step, batteryVolt);
    Connection p, l, r, n;
    vector<Component *> net;
    net.push_back(new Battery("Bat", batteryVolt, &p, &n));
    net.push_back(new Resistor("R1", 150.0, &p, &l));
    net.push_back(new Resistor("R2", 50.0, &p, &r));
    net.push_back(new Capacitor("C3", 1.0, &l, &r));
    net.push_back(new Resistor("R4", 300.0, &l, &n));
    net.push_back(new Capacitor("C5", 0.75, &n, &r));
    simulate(net, num_iterations, line_print, time_step);
    deallocate_components(net);
  }
  catch (const std::exception &e)
  {
    std::cerr << e.what()<<std::endl;
  }
}