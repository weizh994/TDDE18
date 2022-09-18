#include<iostream>
#include<iomanip>
#include<string>
using namespace std;

// TODO: Complementary work: Don't repeat characters but use 
// manipulators from iomanip (example setprecision())

int main()
{
    int varible_int;
    double varible_double;
    char varible_char;
    string varible_string;
    
    //1  static_cast<type>(varible)							//was <int>
    cout << "Enter on integer: ";
    cin >> varible_int;
    cin.ignore(99999999,'\n');
    cout << "You entered the number: " << varible_int << endl;
    cout << endl;

    //2   buffer
    cout << "Enter four integers: ";
    cin >> varible_int;//1
    cout << "You entered the numbers:";
    cout << " " << varible_int;
    cin >> varible_int;//2
    cout << " " << varible_int;
    cin >> varible_int;//3
    cout << " " << varible_int;
    cin >> varible_int;//4
    cout << " " << varible_int;
    cout << "\n" << endl;
    cin.ignore(99999999,'\n');

    //3  setprecision()     cin.ignore(NUM,DEL)
    cout << "Enter one integer and one real number: ";
    cin >> varible_int >> varible_double;
    cin.ignore(99999999,'\n');
    cout << "The real is: "
         << right << setw(11)
         << setprecision(4)
         << varible_double << endl;
    cout << "The integer is: "
         << right << setw(8)
         << varible_int << "\n" << endl;

    //4   setfill()
    cout << "Enter one real and one integer number: ";
    cin >> varible_double >> varible_int;
    cin.ignore(99999999,'\n');
    cout << "The real is: "
         << setfill('.')
         << right << setw(11)
         << fixed << setprecision(3)
         << varible_double << endl;
    cout << "The integer is: "
         << right << setw(8)
         << varible_int << "\n" << endl;

    //5            cin.get()
    cout << "Enter a character: ";
    cin.get(varible_char);
    cin.ignore(99999999,'\n');
    cout << "You entered: "
         << varible_char << "\n" << endl;

    //6   str.size()
    cout << "Enter a word: ";
    cin >> varible_string;
    cin.ignore(99999999,'\n');
    cout << "The word '" << varible_string
         << "' has " << varible_string.size()
         << " charater(s).\n" << endl;

    //77
    cout << "Enter an integer and a word: ";
    cin >> varible_int;
    cin >> varible_string;
    cin.ignore(99999999,'\n');
    cout << "You entered '" << varible_int
         << "' and '" << varible_string
         << "'.\n" << endl;

    //7   " \" "->"     cin.get()
    cout << "Enter an character and a word: ";
    cin.get(varible_char);
    cin >> varible_string;
    cin.ignore(99999999,'\n');
    cout << "You entered the string \""
         << varible_string << "\" and the character '"
         << varible_char << "'.\n" << endl;

    //8    std::fixed->fixed the radix point "."
    cout << "Enter a word and real number: ";
    cin >> varible_string >> varible_double;
    cin.ignore(99999999,'\n');
    cout << "You entered \"" << varible_string
         << "\" and \"" << fixed
         << varible_double
         << "\".\n" << endl;

    //9    getline()
    cout << "Enter a text-line: ";
    getline(cin,varible_string);
    cout << "You entered: \"" << varible_string << "\"\n" << endl;

    //10
    cout << "Enter a second line of text: ";
    getline(cin,varible_string);
    cout << "You entered: \"" << varible_string
         << "\"\n" << endl;

    //11
    cout << "Enter three words: ";
    cin >> varible_string;//1
    cout << "You entered: '"
         << varible_string << " ";
    cin >> varible_string;//2
    cout << " " << varible_string;
    cin >> varible_string;//3
    cout << " " << varible_string;
    cin.ignore(99999999,'\n');
    cout << "'" << endl;

    return 0;
}
