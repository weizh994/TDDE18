#include <iostream>
using namespace std;

int main() {
    cout << "Welcome to dose track!" << endl << endl;
    cout << "What is the total amount of medicine (in gram)? ";

    int total_amount{};
    cin >> total_amount;

    cout << "Over how many hours do you want to take the medicine? ";
    int total_hours{};
    cin >> total_hours;

    int dosage_gram_per_hour{total_amount / total_hours};
    int extra_gram_per_hour{total_amount % total_hours};

    cout << "The dosage is: ";
    while (total_hours--) {
        if (extra_gram_per_hour-- > 0) {
            cout << dosage_gram_per_hour + 1 << " ";
        } else {
            cout << dosage_gram_per_hour << " ";
        }
    }

    cout << endl;
}
