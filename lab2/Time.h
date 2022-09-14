//
// Created by 郑伟雄 on 2022/9/9.
//

#ifndef TDDE18_TIME_H
#define TDDE18_TIME_H
#include <iostream>
#include <string>
using namespace std;
struct TIME
{
    int hour;
    int minute;
    int second;
};
bool is_valid(TIME const &t);                     // Done
bool is_valid(int const &t, bool const &is_hour); // overload with int
string to_string(TIME const &t, bool const &in_24Hformat);
bool is_am(TIME const &t);
TIME operator+(TIME const &t, int const &n); // Do we need n+t?//Done
TIME operator-(TIME const &t, int const &n); // Do we need n-t?//Done
// TIME &operator+=(TIME &t, int const &n);
// TIME &operator-=(TIME &t, int const &n);
TIME &operator++(TIME &t);     // Done
TIME &operator--(TIME &t);     // Done
TIME operator++(TIME &t, int); // Done
TIME operator--(TIME &t, int); // Done
bool operator<(TIME const &t1, TIME const &t2);
bool operator>(TIME const &t1, TIME const &t2);
bool operator<=(TIME const &t1, TIME const &t2);
bool operator>=(TIME const &t1, TIME const &t2);
bool operator==(TIME const &t1, TIME const &t2); // Done
bool operator!=(TIME const &t1, TIME const &t2); // Done
istream &operator>>(istream &is, TIME &t);       // need to be check
ostream &operator<<(ostream &os, TIME const &t); // edwin edit--> declared cout function.
void error();
void fail();
void modify(TIME &t);
#endif // TDDE18_TIME_H
