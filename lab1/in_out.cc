#include<iostream>
#include<iomanip>
#include<string>
#define _IGNORE cin.ignore(99999999,'\n')
using namespace std;
int main(){
	int i;
	double d;
	char c;
	string s;
	//1  static_cast<type>(varible)							//was <int>
	cout<<"Enter on integer: ";
	cin>>d;
	_IGNORE;
	cout<<"You entered the number: "<<static_cast<int>(d)<<endl;
	cout<<endl;
	
	//2   buffer
	cout<<"Enter four integers: ";
	cin>>i;//1
	cout<<"You entered the numbers:";
	cout<<" "<<i;
	cin>>i;//2
	cout<<" "<<i;
	cin>>i;//3
	cout<<" "<<i;
	cin>>i;//4
	cout<<" "<<i;
	cout<<"\n"<<endl;
	_IGNORE;

	//3  setprecision()     cin.ignore(NUM,DEL)
	cout<<"Enter one integer and one real number: "; 
	cin>>i>>d;
	_IGNORE;
	cout<<"The real is: "<<right<<setw(11)<<setprecision(4)<<d<<endl;
	cout<<"The integer is: "<<right<<setw(8)<<i<<"\n"<<endl;

	//4   setfill()
	cout<<"Enter one real and one integer number: "; 
	cin>>d>>i;
	_IGNORE;
	cout<<"The real is: "<<setfill('.')<<right<<setw(11)<<fixed<<setprecision(3)<<static_cast<double>(d)<<endl;
	cout<<"The integer is: "<<setfill('.')<<right<<setw(8)<<static_cast<int>(i)<<"\n"<<endl;
	
	//5            cin.get()
	cout<<"Enter a character: ";
	cin.get(c);
	_IGNORE;
	cout<<"You entered: "<<c<<"\n"<<endl;

	//6   str.size()
	cout<<"Enter a word: ";
	cin>>s;
	_IGNORE;
	cout<<"The word '"<<s<<"' has "<<s.size()<<" charater(s).\n"<<endl; 

	//77
	cout<<"Enter an integer and a word: ";
	cin>>i;
	cin>>s;
	_IGNORE;
	cout<<"You entered '"<<i<<"' and '"<<s<<"'.\n"<<endl;

	//7   " \" "->"     cin.get()
	cout<<"Enter an character and a word: ";
	cin.get(c);
	cin>>s;
	_IGNORE;
	cout<<"You entered the string \""<<s<<"\" and the character '"<<c<<"'.\n"<<endl;

	//8    std::fixed->fixed the radix point "."
	cout<<"Enter a word and real number: ";
	cin>>s>>d;
	_IGNORE;
	cout<<"You entered \""<<s<<"\" and \""<<fixed<<setprecision(3)<<d<<"\".\n"<<endl;

	//9    getline()
	cout<<"Enter a text-line: ";
	getline(cin,s);
	cout<<"You entered: \""<<s<<"\"\n"<<endl;

	//10
	cout<<"Enter a second line of text: ";
	getline(cin,s);
	cout<<"You entered: \""<<s<<"\"\n"<<endl;

	//11
	cout<<"Enter three words: ";
	cin>>s;//1
	cout<<"You entered: '"<<s<<" ";
	cin>>s;//2
	cout<<" "<<s;
	cin>>s;//3
	cout<<" "<<s;
	_IGNORE;
	cout<<"'"<<endl;

	return 0;
}
