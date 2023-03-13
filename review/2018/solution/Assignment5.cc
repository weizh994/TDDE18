#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    istream_iterator<string> iis{cin};
    istream_iterator<string> eof{};

    vector<string> v{iis, eof};
    transform(begin(v), end(v), begin(v), [](string s) {
            string word_ending{"ay"};
            auto first{s.find_first_of("aeiouy")};
            if (first == 0) {
                return s + word_ending;
            }
            return s.substr(first, s.size() - 1) + s.substr(0, first) + 'y' + word_ending;
            });

    ostream_iterator<string> oos{cout, " "};
    int n{40};
    copy_if(begin(v), end(v), oos, [&n](string s) {
            n -= s.size();
            if (--n <= 0) return false;
            return true;
            });

    if (n < 0) {
        cout << "..." << endl;
    }
}

