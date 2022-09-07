#include<iostream>
using namespace std;
struct time
{
	int hour;
	int minute;
	int second;
}

time& operator>>(istream& is, time& t)
{
    is>>t.hour>>t.minute>>t.second;
    return is;
}
