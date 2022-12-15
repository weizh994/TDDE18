#include "editor.hpp"
#include <string>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

editor::editor(int argc, char **argv)
{

  try
  {
    checkArg(argc);
    file_name = argv[1];
    std::vector<std::string> text;
    readFile();
    std::map<std::string, int> dictionary;
    createDictionary();
    std::vector<std::string> argument{argv + 2, argv + argc};
    executeProgram(argument);
  }
  catch (const std::exception &e)
  {
    std::cerr << e.what() << '\n';
  }
}

editor::~editor()
{
  // writeFile();
  text.clear();
  dictionary.clear();
  argument.clear();
}

void editor::executeProgram(std::vector<std::string> &argument) // TODO
{
  argument.erase(std::remove_if(argument.begin(), argument.end(), [&](std::string Arg)
                                { executeArg(Arg);return true; }),
                 argument.end());
}

bool editor::checkArg(int argc) const
{
  if (argc < 2)
  {
    throw std::runtime_error("Arguments are incorrect!\n");
    return false;
  }
  else
    return true;
}

void editor::readArg(std::string &Arg, std::string &flag, std::string &parameter)
{
  Arg = Arg.substr(2);
  Arg.erase(std::remove_if(Arg.begin(),
                           Arg.end(),
                           [](unsigned char x)
                           { return std::isspace(x); }),
            Arg.end());
  if (Arg.find('=') != std::string::npos)
  {
    int eqPlace{static_cast<int>(Arg.find('='))};
    flag = Arg.substr(0, eqPlace);
    parameter = Arg.substr(eqPlace + 1);
  }
  else
  {
    flag = Arg;
    parameter = "ERROR: No parameter!\n";
  }
}

void editor::executeArg(std::string Arg)
{

  std::string flag{}, parameter{};
  readArg(Arg, flag, parameter);
  if (flag == "print")
  {
    print();
  }
  else if (flag == "frequency")
  {
    frequency();
  }
  else if (flag == "table")
  {
    table();
  }
  else if (flag == "substitute")
  {
    substitute(parameter);
  }
  else if (flag == "remove")
  {
    remove(parameter);
  }
  else
  {
    std::cerr << flag + " Arguments are incorrect!\n";
  }
}

void editor::readFile()
{
  std::ifstream read_file(file_name);
  if (!read_file.is_open())
  {
    throw std::runtime_error("Cannot find the file!\n");
  }
  copy(std::istream_iterator<std::string>(read_file),
       std::istream_iterator<std::string>(),
       inserter(text, text.end()));
}

void editor::writeFile()
{
  std::ofstream output_file(file_name);
  std::ostream_iterator<std::string> output_iterator(output_file, " ");
  std::copy(text.begin(), text.end(), output_iterator);
}

void editor::createDictionary()
{
  dictionary.clear(); // Avoid repaeat count
  std::transform(text.begin(), text.end(), std::inserter(dictionary, dictionary.end()),
                 [&](std::string const &s)
                 {
                   return std::make_pair(s, dictionary[s]++);
                 });
}

int editor::longestWord(std::vector<std::string> *const text) const
{
  int len{0};
  len = std::max_element(text->begin(), text->end(), [](std::string x, std::string y)
                         { return x.length() < y.length(); })
            ->length();
  return len;
}

void editor::print()
{
  std::copy(text.begin(), text.end(),
            std::ostream_iterator<std::string>{std::cout, " "});
  std::cout << std::endl;
}

void editor::table()
{
  std::transform(dictionary.begin(), dictionary.end(),
                 std::ostream_iterator<std::string>{std::cout, "\n"}, [&](auto &pair)
                 { std::string str;
            str.append(pair.first);
            str.append(longestWord(&text)-pair.first.length()+1,' ');
            str.append(std::to_string(pair.second));
                 return str; });
  std::cout << std::endl;
}

void editor::frequency()
{
  std::vector<std::pair<std::string, int>> vec;

  // copy key-value pairs from the map to the vector
  std::copy(dictionary.begin(),
            dictionary.end(),
            std::back_inserter<std::vector<std::pair<std::string, int>>>(vec));

  // sort the vector by increasing the order of its pair's second value
  // if the second value is equal, order by the pair's first value
  std::sort(vec.begin(), vec.end(),
            [](const std::pair<std::string, int> &l, const std::pair<std::string, int> &r)
            {
              if (l.second != r.second)
              {
                return l.second > r.second;
              }
              return l.first > r.first;
            });

  // print the vector
  std::transform(vec.begin(), vec.end(),
                 std::ostream_iterator<std::string>{std::cout, "\n"}, [&](auto &pair)
                 { std::string str;
                 str.append(longestWord(&text)-pair.first.length(),' ');
                 str.append(pair.first);
                 str.append(1,' ');
                 str.append(std::to_string(pair.second));
                 return str; });
  std::cout << std::endl;
} // high cohesion,low coupling？

void editor::substitute(std::string parameter)
{
  if (parameter == "ERROR: No parameter!")
  {
    std::cerr << "ERROR: No parameter!\n";
    //  throw std::runtime_error(parameter);
  }
  std::cout << parameter << std::endl;
  int addPlace{static_cast<int>(parameter.find('+'))};
  std::string oldWord{parameter.substr(0, addPlace)}, newWord{parameter.substr(addPlace + 1)}; // if there is no '+',oldWord==newWord
  std::transform(text.begin(), text.end(), text.begin(), [&oldWord, &newWord](std::string str)
                 {if(str==oldWord){
                  str=newWord;
                 }
                 return str; });
  createDictionary();
}

void editor::remove(std::string parameter)
{
  if (parameter == "ERROR: No parameter!")
  {
    std::cerr << "ERROR: No parameter!\n";
    // throw std::runtime_error(parameter);
  }
  text.erase(std::remove_if(text.begin(), text.end(), [&parameter](std::string Rem)
                            { return Rem == parameter; }),
             text.end());
  createDictionary();
}