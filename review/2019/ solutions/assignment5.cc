#include <algorithm>
#include <iomanip>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int main()
{
    map<string, double> balances { };
    
    string payer;
    string receiver;
    double amount;

    while (cin >> payer >> receiver >> amount)
    {
        balances[receiver] -= amount;
        balances[payer]    += amount;
    }

    vector<pair<string, double>> data { balances.begin(),
                                        balances.end() };

    sort(data.begin(), data.end(),
         [](auto const& lhs, auto const& rhs)
         {
             return lhs.second > rhs.second;
         });

    cout << left  << setw(6) << "Name"
         << right << setw(7) << "Balance" << endl;
    
    cout << setw(13) << setfill('-') << ""
         << setfill(' ') << setprecision(2) << fixed << endl;
    
    for (pair<string, double> const& p : data)
    {
        cout << left  << setw(6) << p.first
             << right << setw(7) << p.second << endl;
    }
}
