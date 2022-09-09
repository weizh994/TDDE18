#include<iostream>
#include "Time.h"
#include<string>
using namespace std;

time& operator>>(istream& is, time& t)//should use iteration!
{
    is>>t.hour>>t.minute>>t.second;
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

//Edwin edit: adding cout
ostream operator<<(ostream os, TIME consta& t)
{
os<<t.hour << ":"<<t.minute<<":"<<t.second;
return os;

}
//end of cout

void error(){
    cerr << "ERROR: Illegal input!"<<endl;
}
