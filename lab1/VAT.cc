#include<iostream>
#include<iomanip>
#include<string>
using namespace std;

// TODO: Complementary work: Seperate the different parts of the
// code with an empty line.
// TODO: Complementary work: Don't repeat characters but use 
// manipulators from iomanip (example setprecision())

int main(){
	cout << "INPUT PART\n"
			 << setfill('=') << setw(10) << "\0"
			 << endl;
	string enter_f_p = "Enter first price";
	int input_lenth = enter_f_p.size();
	cout << setfill(' ') << left << setw(input_lenth) << enter_f_p << ": ";
	float first_price;
	cin >> first_price;
	cin.ignore(9999999,'\n');
	
	
 	while(first_price<0.0)
	{
		cerr << "ERROR: First price must be at least 0 (zero) SEK" << endl;
		cout << left << setw(input_lenth) << "Enter first price" << ": ";
		cin >> first_price;
		cin.ignore(9999999,'\n');
	}
	
	cout << left << setw(input_lenth) << "Enter last prise" << ": ";
	float last_price;
	cin >> last_price;
	cin.ignore(9999999,'\n');
	
	while(last_price<first_price)
	{
		cerr << "ERROR: Last price must be at least "
				 << fixed << setprecision(2) << first_price << " SEK" << endl;
		cout << left << setw(input_lenth) << "Enter last prise" << ": ";
		cin >> last_price;
		cin.ignore(9999999,'\n');
	}
	
	cout << left << setw(input_lenth) << "Enter stride" << ": ";
	float stride;
	cin >> stride;
	cin.ignore(9999999,'\n');
	
	while(stride < 0.01)
	{
		cerr << "ERROR: Stride must be at least 0.01" << endl;
		cout << left << setw(input_lenth) << "Enter stride" << " :";
		cin >> stride;
		cin.ignore(9999999,'\n');
	}
	
	cout << left << setw(input_lenth) << "Enter tax percent" << ": ";
	float tax_percent;
	cin >> tax_percent;
	cin.ignore(9999999,'\n');
	//INPUT PART OVER

	cout << "\nTAX TABLE\n"
			 << setfill('=') << setw(9) << "\0"
			 << endl;
	cout << setfill(' ') << right << setw(12) << "Price"
			 << right << setw(17) << "Tax"
			 << right << setw(20) << "Price with tax" << endl;

	// Comment: Why are you adding inside setw()? It's better to just 
	// write one integer
	cout << setfill('-') << setw(49) << "\0" << endl;				// '\0'->null
	float price = first_price;
	int row;
	row = static_cast<int>((last_price-first_price)/stride);
	
	for(int i = 0; i <= row; ++i)
	{
		price = stride * i + first_price;
		cout << right << setfill(' ') << setw(12) << fixed << setprecision(2) << price;
		float tax = price*tax_percent/100.00;
		cout << right << setw(17)
				 << fixed << setprecision(2) << tax;
		cout << right << setw(20)
				 << fixed << setprecision(2) << tax+price << endl;
	}
	//TAX TABEL OVER
	return 0;
}
