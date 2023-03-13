#include <iostream>

using namespace std;

class Node
{
public:
    const int element;
    Node *next;
};

class List
{
public:
    List(initializer_list<int> l);
    int size() { return size_; }
    void sort();
    void print();

private:
    Node *head{};
    int size_{};
};

List::List(initializer_list<int> l)
{
    for (auto ele : l)
    {
        head = new Node{ele, head};
        size_++;
    }
}

void List::print()
{
    Node *curr = head;
    Node *prev = curr;
    while (curr != nullptr)
    {
        prev = curr;
        curr = curr->next;
    }
}

void List::sort()
{
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->element << " ";
        temp = temp->next;
    }
}

int main()
{
    List l{8, 2, 4, 1, 5};
    cout << "Before sort ";
    l.print();
    cout << endl;

    l.sort();
    cout << "After sort ";
    l.print();
    cout << endl;
}
