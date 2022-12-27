#ifndef CIRCUITS_H
#define CIRCUITS_H
#include <string>
#include <vector>
#include <cmath>

// TODO: Complementary work needed: If you need to use math.c, include it with the       
// C++ name: cmath.   Done
//
// TODO: Complementary work needed: Only include headers as needed.   Done
//
// TODO: Complementary work needed: Header files should not contain any 
//  implementation.   Done
//
// TODO: Complementary work needed: Declare member functions not changing  
// the state of the object as constant.    Done
//
// TODO: Complementary work needed: Be consistent with where you place modifiers.
// (const, choose left or right, don't mix).   Done
//
// TODO: Complementary work needed: Break up long lines in a suitable way.    Done
//

struct Connection
{
  double Volt;
  bool can_change;
  Connection();
};

class Component
{
protected:
  std::string Name;
  Connection *V_P;
  Connection *V_N;

public:
  Component(std::string const &name,
            Connection *P, Connection *N);
  virtual ~Component() = default;
  virtual double returnCurr() const;
  virtual void changeVolt(double time_step);
  std::string returnName() const;
  double getVolt() const;
};

class Battery : public Component
{
private:
  double Volt;

public:
  Battery(std::string const &name, double volt,
          Connection *P, Connection *N);
  ~Battery() override;
  void setVolt();
  void changeVolt(double time_step) override;
};

class Resistor : public Component
{
private:
  double Ohm;

public:
  Resistor(std::string const &name, double ohm,
           Connection *P, Connection *N);
  ~Resistor() override;
  double returnCurr() const override;
};

class Capacitor : public Component
{
private:
  double Fahrad;
  double Charge;

public:
  Capacitor(std::string const &name, double fahrad,
            Connection *P, Connection *N);
  ~Capacitor() override;
  double returnCurr() const override;
  void changeVolt(double time_step) override;
};

void simulate(std::vector<Component *> net,
              int num_iterations, int line_print,
              double time_step);
void deallocate_components(std::vector<Component *> net);
void initialCircuits(int argc, char **argv, int &num_iterations,
                     int &line_print, double &time_step,
                     double &batteryVolt);
#endif
