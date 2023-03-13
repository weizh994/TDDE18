#include "editor.hpp"
#include <string>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

void editor(int argc, char **argv)
{
  std::vector<std::string> argument{argv + 2, argv + argc};
  std::vector<std::string> text;
  try
  {
    if (argc < 2)
    {
      throw std::runtime_error("Arguments are incorrect!\n");
    }
    std::string file_name = argv[1];
    readFile(file_name, &text);
    executeProgram(&argument, &text);
  }
  catch (const std::exception &e)
  {
    std::cerr << e.what() << '\n';
  }
}

void executeProgram(std::vector<std::string> *argument, std::vector<std::string> *text) // TODO
{
  /*   argument.erase(std::remove_if(argument.begin(), argument.end(), [&](std::string Arg)
                                  { executeArg(Arg);return true; }),
                   argument.end()); */
  std::for_each(argument->begin(), argument->end(), [&](std::string Arg)
                { executeArg(Arg, text); });
}

void readArg(std::string const &Arg, std::string &flag, std::string &parameter)
{
  std::string NArg = Arg.substr(2);
  NArg.erase(std::remove_if(NArg.begin(),
                            NArg.end(),
                            [](unsigned char x)
                            { return std::isspace(x); }),
             NArg.end());
  if (NArg.find('=') != std::string::npos)
  {
    int eqPlace{static_cast<int>(Arg.find('='))};
    flag = NArg.substr(0, eqPlace - 2);
    parameter = NArg.substr(eqPlace - 1);
  }
  else
  {
    flag = NArg;
    parameter = "ERROR: No parameter!\n";
  }
}

void executeArg(std::string const &Arg, std::vector<std::string> *text)
{

  std::string flag{}, parameter{};
  readArg(Arg, flag, parameter);
  if (flag == "print")
  {
    print(text);
  }
  else if (flag == "frequency")
  {
    frequency(text);
  }
  else if (flag == "table")
  {
    table(text);
  }
  else if (flag == "substitute")
  {
    substitute(parameter, text);
  }
  else if (flag == "remove")
  {
    remove(parameter, text);
  }
  else
  {
    std::cerr << flag + " Arguments are incorrect!\n";
  }
}

void readFile(std::string const &file_name, std::vector<std::string> *text)
{
  std::ifstream read_file(file_name);
  if (!read_file.is_open())
  {
    throw std::runtime_error("Cannot find the file!\n");
  }
  copy(std::istream_iterator<std::string>(read_file),
       std::istream_iterator<std::string>(),
       inserter(*text, text->end()));
}

/* void writeFile()
{
  std::ofstream output_file(file_name);
  std::ostream_iterator<std::string> output_iterator(output_file, " ");
  std::copy(text->begin(), text->end(), output_iterator);
} */

void createDictionary(std::vector<std::string> *const text, std::map<std::string, int> *dictionary)
{
  dictionary->clear(); // Avoid repaeat count
  std::transform(text->begin(), text->end(), std::inserter(*dictionary, dictionary->end()),
                 [&](std::string const &s)
                 {
                   return std::make_pair(s, (*dictionary)[s]++);
                 });
}

int longestWord(std::vector<std::string> *const text)
{
  int len{0};
  len = std::max_element(text->begin(), text->end(), [](std::string x, std::string y)
                         { return x.length() < y.length(); })
            ->length();
  return len;
}

void print(std::vector<std::string> *const text)
{
  std::copy(text->begin(), text->end(),
            std::ostream_iterator<std::string>{std::cout, " "});
  std::cout << std::endl;
}

void table(std::vector<std::string> *const text)
{
  std::map<std::string, int> dictionary;
  createDictionary(text, &dictionary);
  std::transform(dictionary.begin(), dictionary.end(),
                 std::ostream_iterator<std::string>{std::cout, "\n"}, [&](auto &pair)
                 { std::string str;
            str.append(pair.first);
            str.append(longestWord(text)-pair.first.length()+1,' ');
            str.append(std::to_string(pair.second));
                 return str; });
  std::cout << std::endl;
}

void frequency(std::vector<std::string> *const text)
{
  std::map<std::string, int> dictionary;
  createDictionary(text, &dictionary);
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
                 str.append(longestWord(text)-pair.first.length(),' ');
                 str.append(pair.first);
                 str.append(1,' ');
                 str.append(std::to_string(pair.second));
                 return str; });
  std::cout << std::endl;
} // high cohesion,low coupling？

void substitute(std::string const &parameter, std::vector<std::string> *text)
{
  if (parameter == "ERROR: No parameter!")
  {
    std::cerr << "ERROR: No parameter!\n";
    //  throw std::runtime_error(parameter);
  }
  int addPlace{static_cast<int>(parameter.find('+'))};
  std::string oldWord{parameter.substr(0, addPlace)}, newWord{parameter.substr(addPlace + 1)}; // if there is no '+',oldWord==newWord
  std::transform(text->begin(), text->end(), text->begin(), [&oldWord, &newWord](std::string str)
                 {if(str==oldWord){
                  str=newWord;
                 }
                 return str; });
  // createDictionary();
}

void remove(std::string const &parameter, std::vector<std::string> *text)
{
  if (parameter == "ERROR: No parameter!")
  {
    std::cerr << "ERROR: No parameter!\n";
    // throw std::runtime_error(parameter);
  }
  text->erase(std::remove_if(text->begin(), text->end(), [&parameter](std::string Rem)
                             { return Rem == parameter; }),
              text->end());
  // createDictionary();
}