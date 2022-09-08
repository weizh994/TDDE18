#include<iostream>
using namespace std;
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
struct time
{
	int hour;
	int minute;
	int second;
};

time& operator>>(istream& is, time& t)//should use iteration!
{
    //is>>t.hour>>t.minute>>t.second;
    while(is>>t.hour){
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
    return is;
}

void error(){
    cerr << "ERROR: Illegal input!"<<endl;
}