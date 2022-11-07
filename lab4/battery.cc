#include "circuits.hpp"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void Battery::setVolt(double Volt, Connection *V_P, Connection *V_N)
{
  V_P->Volt = this->Volt;
  V_P->can_change = false;
  V_N->Volt = 0;
  V_N->can_change = false;
}
double Battery::returnCurr()
{
  return 0.0;
}