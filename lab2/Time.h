//
// Created by 郑伟雄 on 2022/9/9.
//

#ifndef TDDE18_TIME_H
#define TDDE18_TIME_H
#include<iostream>
#include <string>
using namespace std;
struct TIME
{
    int hour;
    int minute;
    int second;
};
bool is_valid();
string to_string();
bool is_am();
TIME operator+(TIME const& t,int const& n);//Do we need n+t?
TIME operator-(TIME const& t,int const& n);//Do we need n-t?
TIME& operator+=(TIME& t,int const& n);
TIME& operator-=(TIME& t,int const& n);
TIME& operator++(TIME& t);
TIME operator--(TIME& t,int);
bool operator<(TIME const& t1,TIME const& t2);
bool operator>(TIME const& t1,TIME const& t2);
bool operator<=(TIME const& t1,TIME const& t2);
bool operator>=(TIME const& t1,TIME const& t2);
bool operator==(TIME const& t1,TIME const& t2);
bool operator!=(TIME const& t1,TIME const& t2);
TIME& operator>>(istream& is,TIME& t);
ostream& operator<<(ostream& os, TIME const& t);//edwin edit--> declared cout function.
void error();


#endif //TDDE18_TIME_H
