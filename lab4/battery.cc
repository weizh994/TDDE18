#include "circuits.hpp"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void Battery::setVolt()
{
  V_P->Volt = this->Volt;
  V_P->can_change = false;
  V_N->Volt = 0;
  V_N->can_change = false;
}
void Battery::changeVolt(double const time_step)
{
  V_P->Volt = this->Volt;
  V_N->Volt = 0.0;
}