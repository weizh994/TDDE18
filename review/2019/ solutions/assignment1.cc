#include <map>
#include <string>
#include <iostream>

using namespace std;

int main()
{
    map<char, string> rules {
        { 'A', "AT" },
        { 'T', "GC" },
        { 'C', "TA" }
    };

    int N;
    cout << "How many iterations? ";
    cin >> N;

    string dna {"A"};
    cout << dna << endl;
    for (int i{0}; i < N; ++i)
    {
        string new_dna{};
        for (char c : dna)
        {
            auto it {rules.find(c)};
            if (it != rules.end())
            {
                new_dna += it->second;
            }
            else
            {
                new_dna += c;
            }
        }
        dna = new_dna;
        cout << dna << endl;
    }    
}
