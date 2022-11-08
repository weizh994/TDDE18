#include "circuits.hpp"
#include <iostream>
#include <string>
#include <math.h>
#include <vector>
using namespace std;

double Resistor::returnCurr()
{
  return getVolt() / Ohm;
}
void Resistor::changeVolt(double const time_step)
{
  if (V_P->can_change)
  {
    if (V_P->Volt > V_N->Volt)
      V_P->Volt -= returnCurr() * time_step;
    else
      V_P->Volt += returnCurr() * time_step;
  }
  if (V_N->can_change)
  {
    if (V_N->Volt > V_P->Volt)
      V_N->Volt -= returnCurr() * time_step;
    else
      V_N->Volt += returnCurr() * time_step;
  }
}