#include "circuits.hpp"
#include <iostream>
#include <string>
#include <vector>
using namespace std;
Battery::Battery(std::string const &name, double volt, Connection *P, Connection *N)
    : Component{name, P, N}, Volt{volt}
{
  setVolt();
}
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
