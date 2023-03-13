#include <ostream>
#include <iterator>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
  vector<string> v{istream_iterator<string>{cin},
                      istream_iterator<string>{}};
  vector<pair<string, int>> s;
  transform(v.begin(), v.end(), inserter(s, s.end()), [](string s)
            { 
              cout<<s<<endl;
              return make_pair(s,0);
              /* auto it=find(s.begin(), s.end(), [](auto pair)
                 { return (pair.first == s;) });
                 if(it==s.end()){
                  return make_pair(s,0);
                 }
                 else{
                  int a=it->second;
                  return make_pair(s,++a);
                 } */ });
  for (auto i : s)
  {
    cout << i.first << " " << i.second << endl;
  }
}