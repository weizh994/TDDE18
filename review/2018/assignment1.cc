#include <iostream>
#include <cmath>
using namespace std;
int main()
{
  double gram;
  int hours;
  cout << "Welcome to dose track!\n"
       << endl;
  cout << "What is the total amount of medicine (in gram)?";
  cin >> gram;
  cout << "Over how many hours do you want to take the medicine?";
  cin >> hours;

  int dose;
  cout << "The dosage is: ";
  for (int i = 0; i < hours; i++)
  {
    dose = (int)ceil(gram / (hours - i));
    cout << " " << dose;
    gram -= dose;
  }
  cout << "\n";
  return 0;
}