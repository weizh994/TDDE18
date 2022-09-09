//
// Created by 郑伟雄 on 2022/9/9.
//

#ifndef TDDE18_TIME_H
#define TDDE18_TIME_H
bool is_valid();
string to_string();
bool is_am();
time operator+(time const& t,int const& n);//Do we need n+t?
time operator-(time const& t,int const& n);//Do we need n-t?
time& operator+=(time& t,int const& n);
time& operator-=(time& t,int const& n);
time& operator++(time& t);
time operator--(time& t,int);
bool operator<(time const& t1,time const& t2);
bool operator>(time const& t1,time const& t2);
bool operator<=(time const& t1,time const& t2);
bool operator>=(time const& t1,time const& t2);
bool operator==(time const& t1,time const& t2);
bool operator!=(time const& t1,time const& t2);
time& operator>>(istream& is,time& t);
void error();
#endif //TDDE18_TIME_H
