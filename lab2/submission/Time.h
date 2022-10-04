//
// Created by 郑伟雄 on 2022/9/9.
//

#ifndef TDDE18_TIME_H
#define TDDE18_TIME_H
#include <iostream>
#include <string>

struct TIME
{
    int hour;
    int minute;
    int second;
};
bool is_valid(TIME const &t);                                          // Done & Tested
bool is_valid(int const &t, bool const &is_hour);                      // overload with int
bool is_am(TIME const &t);                                             // Done & Tested
std::string to_string(TIME const &t, bool const &in_24Hformat = true); // Done   default ture when call the function as to_string(t)
std::string to_string(int const &t, int);                              // Done   make ever part in time as two digits
TIME operator+(TIME const &t, int const &n);                           // Do we need n+t?//Done
TIME operator-(TIME const &t, int const &n);                           // Do we need n-t?//Done
// TIME &operator+=(TIME &t, int const &n);
// TIME &operator-=(TIME &t, int const &n);
TIME &operator++(TIME &t);                                 // Done & Tested
TIME &operator--(TIME &t);                                 // Done & Tested
TIME operator++(TIME &t, int);                             // Done & Tested
TIME operator--(TIME &t, int);                             // Done & Tested
bool operator<(TIME const &t1, TIME const &t2);            // Done & Tested
bool operator>(TIME const &t1, TIME const &t2);            // Done & Tested
bool operator<=(TIME const &t1, TIME const &t2);           // Done & Tested
bool operator>=(TIME const &t1, TIME const &t2);           // Done & Tested
bool operator==(TIME const &t1, TIME const &t2);           // Done & Tested
bool operator!=(TIME const &t1, TIME const &t2);           // Done & Tested
std::istream &operator>>(std::istream &is, TIME &t);       // Done & Tested
std::ostream &operator<<(std::ostream &os, TIME const &t); // Done & Tested
void error();
// void fix();
void modify(TIME &t);
#endif // TDDE18_TIME_H
