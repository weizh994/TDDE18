#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <utility>
#include <algorithm>

using namespace std;

int main(int argc, char * argv[]) {
    if (argc < 2) {
        cerr << "Error: No arguments given.\nUsage: a.out FILE" << endl;
        return 1;
    }

    ifstream is{argv[1]};
    if (!is) {
        cerr << "Error: No file named \"" << argv[1] << endl;
        cerr << "Usage: a.out FILE" << endl;
        return 2;
    }

    map<string, int> m{};
    string line{};

    while (getline(is, line)) {
        stringstream s{line};
        int question{};
        string player{};
        string correct{};
        int score{};
        int score_no_bonus{};
        s >> question >> player >> correct >> score >> score_no_bonus;
        m[player] += score;
    }

    vector<pair<string, int>> v{begin(m), end(m)};
    sort(begin(v), end(v), [](pair<string, int> p1, pair<string, int> p2){ return p1.second > p2.second;});

    cout << "1st place: " << v[0].first << " with " << v[0].second << " total points" << endl;
    cout << "2st place: " << v[1].first << " with " << v[1].second << " total points" << endl;
    cout << "3st place: " << v[2].first << " with " << v[2].second << " total points" << endl;
}
