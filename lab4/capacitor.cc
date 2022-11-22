#include "circuits.hpp"
#include <iostream>
#include <string>
#include <math.h>
#include <vector>
using namespace std;

Capacitor::Capacitor(std::string const &name, double fahrad, Connection *P, Connection *N)
    : Component{name, P, N}, Fahrad(fahrad), Charge(0.0) {}
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
