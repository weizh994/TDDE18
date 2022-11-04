#ifndef CIRCUITS_H
#define CIRCUITS_H
#include <string>

struct Connection
{
  double Volt = 0.0;
  bool can_change = true;
};

class Components
{
protected:
  string Name;
  Connection *V_P;
  Connection *V_N;

public:
  Components();
  ~Components();
};

class Battery : public Components
{
private:
  double Volt;

public:
  Battery(/* args */);
  ~Battery();
};

class Resistor : public Components
{
private:
  double Ohm;

public:
  Resistor();
  ~Resistor();
};

class Capacitor : public Components
{
private:
  double Fahrad;

public:
  Capacitor(/* args */);
  ~Capacitor();
};

#endif