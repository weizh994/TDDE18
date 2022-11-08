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
  virtual void changeVolt(double const &time_step)
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
};

class Battery : public Component
{
private:
  double Volt;

public:
  Battery(std::string const &name, double const &volt, Connection *P, Connection *N)
      : Component{name, P, N}, Volt{volt}
  {
    setVolt();
  }

  //~Battery();
  void setVolt();
  void changeVolt(double const &time_step) override;
};

class Resistor : public Component
{
private:
  double Ohm;

public:
  Resistor(std::string const &name, double const &ohm, Connection *P, Connection *N)
      : Component{name, P, N}, Ohm{ohm} {}
  //~Resistor() {}
  double returnCurr() override;
  void changeVolt(double const &time_step) override;
};

/*class Capacitor : public Component
{
private:
  double Fahrad;

public:
  Capacitor(std::string const &name, double const &fahrad, Connection P, Connection N)
      : Component(name, P, N), Fahrad(fahrad) {}
  ~Capacitor()
  {
    delete this;
  };
  double returnCurr() override;
  void changeVolt(double const time_step) override;
};

void simulate(std::vector<Component *> net, int const &num_iterations, int const &line_print, double const time_step);
*/
#endif