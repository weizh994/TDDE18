#include <iostream>
#include <vector>
#include <string>
void checkCla(int argc, char **argv, int &num_iterations, int &line_print, double &time_step, double &batteryVolt)
{
  std::vector<std::string> args{argv, argv + argc};
  if (args.size() != 5)
    throw std::runtime_error("ERROR");
  else
  {
    num_iterations = std::stoi(args[1]);
    line_print = std::stoi(args[2]);
    time_step = std::stod(argv[3]);
    batteryVolt = std::stod(argv[4]);
  }
}

int main(int argc, char **argv)
{
  int num_iterations{0};
  int line_print{0};
  double time_step{0.0};
  double batteryVolt{0.0};
  try
  {
    checkCla(argc, argv, num_iterations, line_print, time_step, batteryVolt);
  }
  catch (const std::exception &e)
  {
    std::cerr << e.what();
  }
  std::cout << "num_iterations:" << num_iterations << std::endl;
  std::cout << "line_print:" << line_print << std::endl;
  std::cout << "time_step:" << time_step << std::endl;
  std::cout << "batteryVolt:" << batteryVolt << std::endl;
}
