//
// Created by 郑伟雄 on 2022/9/9.
//

#ifndef TDDE18_TIME_H
#define TDDE18_TIME_H
struct TIME
{
    int hour;
    int minute;
    int second;
};
bool is_valid();
string to_string();
bool is_am();
time operator+(TIME const& t,int const& n);//Do we need n+t?
time operator-(TIME const& t,int const& n);//Do we need n-t?
time& operator+=(TIME& t,int const& n);
time& operator-=(TIME& t,int const& n);
time& operator++(TIME& t);
time operator--(TIME& t,int);
bool operator<(TIME const& t1,TIME const& t2);
bool operator>(TIME const& t1,TIME const& t2);
bool operator<=(TIME const& t1,TIME const& t2);
bool operator>=(TIME const& t1,TIME const& t2);
bool operator==(TIME const& t1,TIME const& t2);
bool operator!=(TIME const& t1,TIME const& t2);
time& operator>>(istream& is,TIME& t);
void error();
//edwin edit
#endif //TDDE18_TIME_H
