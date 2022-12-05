#ifndef EDITOR_H
#define EDITOR_H
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
class editor
{
private:
  std::vector<std::string> text;
  std::vector<std::string> argument;
  std::string file_name;

public:
  editor(int argc, char **argv);
  ~editor();
  bool checkArg(int argc, char **argv);
  void readFile(std::string file_name);
  void print();
};

#endif