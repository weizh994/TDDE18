#include<iostream>
#include<iomanip>
#include<string>
#define _IGNORE cin.ignore(9999999,'\n')
using namespace std;
int main(){
	cout<<"INPUT PART\n==========\n";
	string enter_f_p="Enter first price";
	int input_lenth = enter_f_p.size();
	cout<<left<<setw(input_lenth)<<enter_f_p<<": ";
	float first_price;
	cin>>first_price;
	_IGNORE;
	while(first_price<0.0){
		cerr<<"ERROR: First price must be at least 0 (zero) SEK"<<endl;
		cout<<left<<setw(input_lenth)<<"Enter first price"<<": ";
		cin>>first_price;
		_IGNORE;
	}
	cout<<left<<setw(input_lenth)<<"Enter last prise"<<": ";
	float last_price;
	cin>>last_price;
	_IGNORE;
	while(last_price<first_price){
		cerr<<"ERROR: Last price must be at least "<<fixed<<setprecision(2)<<first_price<<" SEK"<<endl;
		cout<<left<<setw(input_lenth)<<"Enter last prise"<<": ";
		cin>>last_price;
		_IGNORE;
	}
	cout<<left<<setw(input_lenth)<<"Enter stride"<<": ";
	float stride;
	cin>>stride;
	_IGNORE;
	while(stride<0.01){
		cerr<<"ERROR: Stride must be at least 0.01"<<endl;
		cout<<left<<setw(input_lenth)<<"Enter stride"<<" :";
		cin>>stride;
		_IGNORE;
	}
	cout<<left<<setw(input_lenth)<<"Enter tax percent"<<": ";
	float tax_percent;
	cin>>tax_percent;
	_IGNORE;
	//INPUT PART OVER
	cout<<"\nTAX TABLE\n========="<<endl;
	cout<<right<<setw(12)<<"Price"<<right<<setw(17)<<"Tax"<<right<<setw(20)<<"Price with tax"<<endl;
	cout<<setfill('-')<<setw(12+17+20)<<"\0"<<endl;				// '\0'->null
	float price = first_price;
	while(price<=last_price){
		cout<<right<<setfill(' ')<<setw(12)<<fixed<<setprecision(2)<<price;
		float tax = price*tax_percent/100.00;
		cout<<right<<setw(17)<<fixed<<setprecision(2)<<tax;
		cout<<right<<setw(20)<<fixed<<setprecision(2)<<tax+price<<endl;
		price+=stride;

	}
	//TAX TABEL OVER
	return 0;
}
