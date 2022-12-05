#ifndef CIRCUITS_H
#define CIRCUITS_H
#include <string>
#include <vector>
#include <math.h>
#include <iostream>
#include <initializer_list>

// TODO: Complementary work needed: If you need to use math.c, include it with the       
// C++ name: cmath. 
//
// TODO: Complementary work needed: Only include headers as needed. 
//
// TODO: Complementary work needed: Header files should not contain any 
// implementation.    
//
// TODO: Complementary work needed: Declare member functions not changing  
// the state of the object as constant. 
//
// TODO: Complementary work needed: Be consistent with where you place modifiers.
// (const, choose left or right, don't mix).
//
// TODO: Complementary work needed: Break up long lines in a suitable way. 
//


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
  Component(const std::string &name, Connection *P, Connection *N);
  virtual ~Component() = default;
  virtual double returnCurr()
  {
    return 0.0;
  }
  virtual void changeVolt(double time_step);
  std::string returnName();
  double getVolt() const;
  // void checkNP();
};

class Battery : public Component
{
private:
  double Volt;

public:
  Battery(std::string const &name, double volt, Connection *P, Connection *N);
  ~Battery() override;
  void setVolt();
  void changeVolt(double time_step) override;
};

class Resistor : public Component
{
private:
  double Ohm;

public:
  Resistor(std::string const &name, double ohm, Connection *P, Connection *N);
  ~Resistor() override;
  double returnCurr() override;
  // void changeVolt(double time_step) override;
};

class Capacitor : public Component
{
private:
  double Fahrad;
  double Charge;

public:
  Capacitor(std::string const &name, double fahrad, Connection *P, Connection *N);
  ~Capacitor() override;
  double returnCurr() override;
  void changeVolt(double time_step) override;
};
/*
class Circuits : public Component
{
private:
  std::vector<Component *> net;
  int num_iterations;
  int line_print;
  double &time_step;
  double batteryVolt;

public:
  Circuits(int argc, char **argv);
  ~Circuits();
  //void initialCircuits(int argc, char **argv);
  void simulate(vector<Component *> net, int num_iterations, int line_print, double time_step);
};*/

void simulate(std::vector<Component *> net, int num_iterations, int line_print, double time_step);
void deallocate_components(std::vector<Component *> net);
void initialCircuits(int argc, char **argv, int &num_iterations, int &line_print, double &time_step, double &batteryVolt);
#endif
