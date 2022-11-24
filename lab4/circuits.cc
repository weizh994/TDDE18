#include "circuits.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <initializer_list>
using namespace std;

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
void Component::checkNP()
{
  if (V_N->Volt > V_P->Volt)
  {
    Connection *temp;
    temp = V_N;
    V_N = V_P;
    V_P = temp;
  }
}

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
void Resistor::changeVolt(double time_step)
{
  checkNP();
  if (V_P->can_change)
  {
    V_P->Volt -= returnCurr() * time_step;
  }
  if (V_N->can_change)
  {
    V_N->Volt += returnCurr() * time_step;
  }
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
  checkNP();
  Charge += returnCurr() * time_step;
  if (V_P->can_change)
  {
    V_P->Volt -= returnCurr() * time_step;
  }
  if (V_N->can_change)
  {
    V_N->Volt += returnCurr() * time_step;
  }
}
/*
Circuits::Circuits(std::initializer_list<int> list)
{

}
Circuits::~Circuits()
{
  for (Component *Component : net)
  {
    delete Component;
  }
}
*/