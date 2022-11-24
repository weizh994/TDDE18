#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <map>
struct inputData
{
  std::string file_name{};
  int num_iterations{0};
  int line_print{0};
  double time_step{0.0};
  double batteryVolt{0.0};
};
void checkCla(int argc, char **argv, inputData &inputData)
{
  std::vector<std::string> args{argv, argv + argc};
  if (args.size() != 6)
    throw std::runtime_error("ERROR");
  else
  {
    inputData.file_name = args[1];
    inputData.num_iterations = std::stoi(args[2]);
    inputData.line_print = std::stoi(args[3]);
    inputData.time_step = std::stod(argv[4]);
    inputData.batteryVolt = std::stod(argv[5]);
  }
}
void readFile(std::string fileName)
{
  std::ifstream read_file;
  read_file.open(fileName, std::ios::in);
  std::string word;
  std::string line;
  std::vector<std::string> File;
  std::vector<std::string> CFile;
  while (getline(read_file, line))
  { // first word
    File.push_back(line);
    // std::cout << word << std::endl;
  }
  read_file.close();
  for (std::string l : File)
  {
    std::stringstream ss{};
    ss << l;
    while (ss >> word)
    {
      CFile.push_back(word);
    }
    for (std::string s : CFile)
    {
      std::cout << s << std::endl;
    }
    CFile.clear();
    std::cout << "END" << std::endl;
  }
}

int main(int argc, char **argv)
{
  inputData inputData;
  // std::map<std::string, int, bool> Connection;
  try
  {
    checkCla(argc, argv, inputData);
    readFile(inputData.file_name);
  }
  catch (const std::exception &e)
  {
    std::cerr << e.what();
  }
  // std::cout << "file_name:" << inputData.file_name << std::endl;
  //  std::cout << "num_iterations:" << inputData.num_iterations << std::endl;
  //  std::cout << "line_print:" << inputData.line_print << std::endl;
  //  std::cout << "time_step:" << inputData.time_step << std::endl;
  //  std::cout << "batteryVolt:" << inputData.batteryVolt << std::endl;
}
