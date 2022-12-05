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
};

editor::editor(int argc, char **argv)
{
  if (checkArg(argc, argv))
  {
    file_name = argv[1];
    std::vector<std::string> text;
    std::vector<std::string> argument{argv + 2, argv + argc};
  }
}

editor::~editor()
{
}

bool editor::checkArg(int argc, char **argv)
{
  if (argc > 2)
  {
  }
  else
    throw std::runtime_error("Thank you for use!");
}

void editor::readFile(std::string file_name) // TODO
{
  std::ifstream read_file;
  read_file.open(file_name, std::ios::in);
  std::string word;
}
#endif