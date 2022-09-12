#include <iostream>
#include "Time.h"
#include <string>
using namespace std;

bool is_valid(TIME const &t)
{
    return is_valid(t.hour, true) && is_valid(t.minute, false) && is_valid(t.second, false);
}
bool is_valid(int const &t, bool const &is_hour)
{
    if (is_hour)
    {
        if (t <= 23 && t >= 0)
            return true;
        else
            return false;
    }
    else
    {
        if (t <= 59 && t >= 0)
            return true;
        else
            return false;
    }
}

TIME operator+(TIME const &t, int const &n)
{
    TIME tmp{t};
    tmp.second += n;
    modify(tmp);
    return tmp;
}

TIME operator-(TIME const &t, int const &n)
{
    TIME tmp{t};
    tmp.second -= n;
    modify(tmp);
    return tmp;
}

TIME &operator++(TIME &t)
{
    ++t.second;
    modify(t);
    return t;
}
TIME &operator--(TIME &t)
{
    --t.second;
    modify(t);
    return t;
}
TIME operator++(TIME &t, int)
{
    TIME tmp{t};
    ++t.second;
    modify(t);
    return tmp;
}

TIME operator--(TIME &t, int)
{
    TIME tmp{t};
    --t.second;
    modify(t);
    return tmp;
}

bool operator==(TIME const &t1, TIME const &t2)
{
    return (t1.hour == t2.hour) && (t1.minute == t2.minute) && (t1.second == t2.second);
}

bool operator!=(TIME const &t1, TIME const &t2)
{
    return !(t1 == t2);
}

istream &operator>>(istream &is, TIME &t) // should use iteration!
{
    do
    {
        is >> t.hour;
    } while (!is_valid(t.hour, true));
    do
    {
        is >> t.minute;
    } while (!is_valid(t.minute, false));
    do
    {
        is >> t.second;
    } while (!is_valid(t.second, false));
    /*while(is>>t.hour){
        if(is.bad()||is.eof()||is.fail()){
            is.clear();
            is.ignore(999999,'\n');
            error();
        }
        else if((t.hour > 23) || (t.hour < 0)){
            error();
        }
        else{
            break;
        }
    }
    while(is>>t.minute){
        if(is.bad()||is.eof()||is.fail()){
            is.clear();
            is.ignore(999999,'\n');
            error();
        }
        else if((t.minute > 59) || (t.minute < 0)){
            error();
        }
        else{
            break;
        }
    }
    while(is>>t.second){
        if(is.bad()||is.eof()||is.fail()){
            is.clear();
            is.ignore(999999,'\n');
            error();
        }
        else if((t.second > 59) || (t.second < 0)){
            error();
        }
        else{
            break;
        }
    }
    return is;*/
}

// Edwin edit: adding cout
ostream &operator<<(ostream &os, TIME const &t)
{
    os << t.hour << ":" << t.minute << ":" << t.second;
    return os;
}
// end of cout

void error()
{
    cerr << "ERROR: Illegal Time!" << endl;
}
void modify(TIME &t)
{
    while (!is_valid(t))
    {
        if (t.second > 59)
        {
            t.minute = t.second / 60 + t.minute;
            t.second %= 60;
        }
        else if (t.second < 0)
        {
            t.minute = t.minute - t.second * (-1) / 60;
            t.second = t.second * (-1) % 60;
        }
        else if (t.minute > 59)
        {
            t.hour = t.minute / 60 + t.hour;
            t.minute %= 60;
        }
        else if (t.minute < 0)
        {
            t.hour = t.hour - t.minute * (-1) / 60;
            t.minute = t.minute * (-1) % 60;
        }
        else if (t.hour > 23)
        {
            t.hour %= 24;
        }
        else
        {
            t.hour = t.hour * (-1) % 24;
        }
    }
}
