#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <utility>
#include <algorithm>
int main(int agrc, char **agrv)
{
  if (agrc == 1)
  {
    std::cerr << "Error: "
              << "No arguments given." << '\n';
    std::cerr << "Usage: a.out FILE" << std::endl;
    return 1;
  }
  std::ifstream read_file(agrv[1]);
  if (!read_file.is_open())
  {
    std::cerr << "Error: "
              << "No file named \"" << agrv[1] << "\"" << '\n';
    std::cerr << "Usage: a.out FILE" << std::endl;
    return 1;
  }
  std::vector<std::pair<std::string, int>> data{};
  int Question, Score, Score_no_bonus;
  std::string Player, Correct;
  while (read_file >> Question >> Player >> Correct >> Score >> Score_no_bonus)
  {
    auto it = find_if(data.begin(), data.end(), [&](auto pair)
                      { return (pair.first == Player); });
    if (it == data.end())
    {
      auto temp = make_pair(Player, Score);
      data.push_back(temp);
    }
    else
    {
      it->second += Score;
    }
  }
  std::sort(data.begin(), data.end(),[](auto a,auto b){return a.second>b.second;});
  std::cout << "1st place: " << data[0].first << " with " << data[0].second << " total points" << std::endl;
  std::cout << "2nd place: " << data[1].first << " with " << data[1].second << " total points" << std::endl;
  std::cout << "3rd place: " << data[2].first << " with " << data[2].second << " total points" << std::endl;
}
