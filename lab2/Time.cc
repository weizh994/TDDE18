#include <iostream>
#include "Time.h"
#include <string>
#include <math.h>
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
bool is_am(TIME const &t)
{
    if (!is_valid(t))
    {
        return false;
    }
    else
    {
        if (t.hour < 12)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

string to_string(TIME const &t, bool const &in_24Hformat)
{
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
bool operator<(TIME const &t1, TIME const &t2)
{
    if (t1.hour == t2.hour)
    {
        if (t1.minute == t2.minute)
        {
            if (!(t1.second < t2.second))
            {
                return false;
            }
            else
            {
                return true;
            }
        }
        else if (t1.minute > t2.minute)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    else if (t1.hour > t2.hour)
    {
        return false;
    }
    else
    {
        return true;
    }
}

bool operator>(TIME const &t1, TIME const &t2)
{
    return t2 < t1;
}

bool operator<=(TIME const &t1, TIME const &t2)
{
    return (t1 < t2) || (t1 == t2);
}

bool operator>=(TIME const &t1, TIME const &t2)
{
    return t2 <= t1;
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
        fail();
        is >> t.hour;
        cin.ignore(1024, ':');
        is >> t.minute;
        cin.ignore(1024, ':');
        is >> t.second;
    } while ((!is_valid(t)) || cin.fail());
    return is;
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

void fail()
{
    if (cin.fail())
    {
        error();
        cin.clear();
        cin.ignore(1024, '\n');
    }
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
            t.minute = t.minute - static_cast<int>(ceil(t.second * (-1) / 60.0));
            t.second = t.second * (-1) % 60;
        }
        else if (t.minute > 59)
        {
            t.hour = t.minute / 60 + t.hour;
            t.minute %= 60;
        }
        else if (t.minute < 0)
        {
            t.hour = t.hour - static_cast<int>(ceil(t.minute * (-1) / 60.0));
            t.minute = t.minute * (-1) % 60;
        }
        else if (t.hour > 23)
        {
            t.hour %= 24;
        }
        else
        {
            t.hour = static_cast<int>(ceil(t.hour * (-1) / 24.0));
        }
    }
}
