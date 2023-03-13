#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> string_to_vector_int(string s) {
    vector<int> v;
    for (auto c : s) {
        v.push_back(c - '0');
    }
    return v;
}

struct Node {
    int value;
    Node * grey_line;
    Node * red_line;
};

class Mod7 {
public:
    Mod7() {
        Node* start=new Node{0,nullptr,nullptr};
        first=start;
        for(int i=1;i<7;i++){
            start->grey_line=new Node{i,nullptr,nullptr};
            start=start->grey_line;
        }
        start->grey_line=first;//6
        start=start->grey_line;//0
        start->red_line=first;
        start=start->grey_line;//1
        start->red_line=start->grey_line->grey_line;
        start=start->grey_line;//2
        start->red_line=start->grey_line->grey_line->grey_line->grey_line;
        start=start->grey_line;//3
        start->red_line=start->grey_line->grey_line->grey_line->grey_line->grey_line->grey_line;
        start=start->grey_line;//4
        start->red_line=start->grey_line;
        start=start->grey_line;//5
        start->red_line=first->grey_line;
        start=start->grey_line;//6
        start->red_line=start->grey_line->grey_line->grey_line->grey_line->grey_line;
        // Create the graph here
    }

    int remainder(string number) {
        vector<int> v=string_to_vector_int(number);
        int left=(int)v.size();
        Node* start=first;
        for(auto c : v){
            for(int i=0;i<c;i++){
                start=start->grey_line;
            }
            --left;
            if(left!=0){
            start=start->red_line;
            }
            else return start->value;
        }
        // change this member function to make the test pass
        return 0;
    }

    // Insert your help functions here
    ~Mod7(){
    while (first->grey_line!=nullptr)
    {
        Node * temp=first;
        first=first->grey_line;
        delete temp;
    }
    
}

private:
    Node *first;
    // Insert extra data members if needed
};


int main() {
    string test1{"243"};

    Mod7 modder{};

    if (modder.remainder("243") == 5) {
        cout << "Correct" << endl;
    }

    if (modder.remainder("11111111111111111111111111111") == 2) {
        cout << "Correct" << endl;
    }

    // more test cases here
}

