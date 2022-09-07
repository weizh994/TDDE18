#include<iostream>
using namespace std;
bool is_valid();
string to_string();
bool is_am();
time operator+(time const& t,int n);//Do we need n+t?
time operator-(time const& t,int n);//Do we need n-t?
time& operator++(time& t);
time operator--(time& t,int);
bool operator<(time const& t1,time const& t2);
bool operator>(time const& t1,time const& t2);
bool operator<=(time const& t1,time const& t2);
bool operator>=(time const& t1,time const& t2);
bool operator==(time const& t1,time const& t2);
bool operator!=(time const& t1,time const& t2);

struct time
{
	int hour;
	int minute;
	int second;
};

time& operator>>(istream& is, time& t)
{
    is>>t.hour>>t.minute>>t.second;
    return is;
}
