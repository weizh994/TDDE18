#include <string>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <map>
using namespace std;

int main(int argc, char **argv)
{
  std::vector<std::string> text;
  std::map<std::string, int> dictionary;
  std::ifstream read_file("short.txt");

  copy(std::istream_iterator<std::string>(read_file),
       std::istream_iterator<std::string>(),
       inserter(text, text.end()));
  int len = std::max_element(text.begin(), text.end(), [](std::string x, std::string y)
                             { return x.length() < y.length(); })
                ->length();
  std::transform(text.begin(), text.end(), std::inserter(dictionary, dictionary.end()),
                 [&](std::string const &s)
                 {
                   return std::make_pair(s, dictionary[s]++);
                 });
  /* std::transform(dictionary.begin(), dictionary.end(),
                 std::ostream_iterator<std::string>{std::cout, "\n"}, [&len](auto &pair)
                 { std::string str;
            str.append(pair.first);
            str.append(len-pair.first.length()+1,' ');
            str.append(to_string(pair.second));
                 return str; }); */
  std::ofstream output_file("short1.txt");
  std::ostream_iterator<std::string> output_iterator(output_file, " ");
  std::copy(text.begin(), text.end(), output_iterator);
  return 0;
}
