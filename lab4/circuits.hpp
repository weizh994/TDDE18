#ifndef CIRCUITS_H
#define CIRCUITS_H
#include <string>
#include <vector>
#include <math.h>
#include <iostream>

struct Connection
{
  double Volt;
  bool can_change;
  Connection()
  {
    Volt = 0;
    can_change = true;
  }
};

class Component
{
protected:
  std::string Name;
  Connection *V_P;
  Connection *V_N;

public:
  Component(const std::string &name, Connection *P, Connection *N)
      : Name{name}, V_P{P}, V_N{N} {}
  /*virtual*/ ~Component() {} //= default;
  virtual double returnCurr()
  {
    return 0.0;
  }
  virtual void changeVolt(double time_step)
  {
    std::cout << "Wrong Call" << std::endl;
  }
  std::string returnName()
  {
    return Name;
  }
  double getVolt() const
  {
    return abs((V_P->Volt) - (V_N->Volt));
  }
  void checkNP()
  {
    if (V_N->Volt > V_P->Volt)
    {
      Connection *temp;
      temp = V_N;
      V_N = V_P;
      V_P = temp;
    }
  }
};

class Battery : public Component
{
private:
  double Volt;

public:
  Battery(std::string const &name, double volt, Connection *P, Connection *N)
      : Component{name, P, N}, Volt{volt}
  {
    setVolt();
  }

  //~Battery();
  void setVolt();
  void changeVolt(double time_step) override;
};

class Resistor : public Component
{
private:
  double Ohm;

public:
  Resistor(std::string const &name, double ohm, Connection *P, Connection *N)
      : Component{name, P, N}, Ohm{ohm} {}
  //~Resistor() {}
  double returnCurr() override;
  void changeVolt(double time_step) override;
};

class Capacitor : public Component
{
private:
  double Fahrad;
  double Charge;

public:
  Capacitor(std::string const &name, double fahrad, Connection *P, Connection *N)
      : Component{name, P, N}, Fahrad(fahrad), Charge(0.0) {}
  ~Capacitor() {}
  double returnCurr() override;
  void changeVolt(double time_step) override;
};

#endif