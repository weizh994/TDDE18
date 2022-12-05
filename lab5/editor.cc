#include "editor.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iterator>
editor::editor(int argc, char **argv)
{
  if (checkArg(argc, argv))
  {
    file_name = argv[1];
    std::vector<std::string> text;
    readFile(file_name);
    // std::vector<std::string> argument{argv + 2, argv + argc};
  }
}

editor::~editor()
{
}

bool editor::checkArg(int argc, char **argv)
{
  if (argc < 2)
  {
    throw std::runtime_error("Arguments are incorrect!");
    return false;
  }
  else
    return true;
}

void editor::readFile(std::string file_name) // TODO
{
  std::ifstream read_file(file_name);
  if (!read_file.is_open())
  {
    throw std::runtime_error("Cannot open the file!");
  }
  else
  {
    copy(std::istream_iterator<std::string>(read_file),
         std::istream_iterator<std::string>(),
         inserter(text, text.end()));
    // std::cout << "START" << std::endl;
  }
}

void editor::print()
{
  std::copy(text.begin(), text.end(),
            std::ostream_iterator<std::string>{std::cout, " "});
  std::cout << std::endl;
}