#include "circuits.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

// TODO: Complementary work needed: Insert some blank lines between definitions.

Component::Component(const std::string &name, Connection *P, Connection *N)
    : Name{name}, V_P{P}, V_N{N} {}
std::string Component::returnName()
{
  return Name;
}
double Component::getVolt() const
{
  return abs((V_P->Volt) - (V_N->Volt));
}
void Component::changeVolt(double time_step)
{
  if (V_P->can_change)
  {
    if (V_P->Volt > V_N->Volt)
    {
      V_P->Volt -= returnCurr() * time_step;
    }
    else
    {
      V_P->Volt += returnCurr() * time_step;
    }
  }
  if (V_N->can_change)
  {
    if (V_N->Volt < V_P->Volt)
    {
      V_N->Volt += returnCurr() * time_step;
    }
    else
    {
      V_N->Volt -= returnCurr() * time_step;
    }
  }
}
/*void Component::checkNP()
{
  if (V_N->Volt > V_P->Volt)
  {
    Connection *temp;
    temp = V_N;
    V_N = V_P;
    V_P = temp;
  }
}*/

Battery::Battery(std::string const &name, double volt, Connection *P, Connection *N)
    : Component{name, P, N}, Volt{volt}
{
  setVolt();
}
Battery::~Battery() {}
void Battery::setVolt()
{
  changeVolt(0);
  V_P->can_change = false;
  V_N->can_change = false;
}
void Battery::changeVolt(double time_step)
{
  V_P->Volt = this->Volt;
  V_N->Volt = 0.0;
}
Resistor::Resistor(std::string const &name, double ohm, Connection *P, Connection *N)
    : Component{name, P, N}, Ohm{ohm} {}
Resistor::~Resistor() {}
double Resistor::returnCurr()
{
  return getVolt() / Ohm;
}
Capacitor::Capacitor(std::string const &name, double fahrad, Connection *P, Connection *N)
    : Component{name, P, N}, Fahrad(fahrad), Charge(0.0) {}
Capacitor::~Capacitor() {}
double Capacitor::returnCurr()
{
  return Fahrad * (getVolt() - Charge);
}
void Capacitor::changeVolt(double time_step)
{
  Charge += returnCurr() * time_step;
  Component::changeVolt(time_step);
}

/*Circuits::Circuits(int argc, char **argv)
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
Circuits::~Circuits()
{
  for (Component *Component : net)
  {
    delete Component;
  }
}*/




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
  if (args.size() != 6)
    throw std::runtime_error("ERROR: THE NUMBER OF INPUT IS INCORRECT!");
  else
  {
    num_iterations = std::stoi(args[2]);
    line_print = std::stoi(args[3]);
    time_step = std::stod(argv[4]);
    batteryVolt = std::stod(argv[5]);
    if (num_iterations < line_print)
    {
      throw std::runtime_error("ERROR: THE INPUT IS ILLEGAL!");
    }
  }
}
