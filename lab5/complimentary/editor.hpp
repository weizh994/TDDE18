#ifndef EDITOR_H
#define EDITOR_H
#include <string>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <map>

void editor(int argc, char **argv);
void executeArg(std::string const &Arg, std::vector<std::string> *text);
void readArg(std::string const &Arg, std::string &flag, std::string &parameter);
void readFile(std::string const &file_name, std::vector<std::string> *text); // Done
// void writeFile();                                                            // Done
int longestWord(std::vector<std::string> *const text);                                               // Done
void createDictionary(std::vector<std::string> *const text, std::map<std::string, int> *dictionary); // Done
void print(std::vector<std::string> *const text);                                                    // Done
void table(std::vector<std::string> *const text);                                                    // Done
void frequency(std::vector<std::string> *const text);                                                // Done
void substitute(std::string const &parameter, std::vector<std::string> *text);                       // Done
void remove(std::string const &parameter, std::vector<std::string> *text);                           // Done

void executeProgram(std::vector<std::string> *argument, std::vector<std::string> *text);

#endif