#include "circuits.hpp"
#include <iostream>
#include <string>
#include <math.h>
#include <vector>
using namespace std;
Resistor::Resistor(std::string const &name, double ohm, Connection *P, Connection *N)
    : Component{name, P, N}, Ohm{ohm} {}
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
