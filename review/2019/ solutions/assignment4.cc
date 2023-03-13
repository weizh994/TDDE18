#include <iostream>
#include <limits>

using namespace std;

class Node {
    public:
        const int element;
        Node* next;
};

class List {
    public:
        List(initializer_list<int> l);
        int size() { return size_; }
        void sort();
        void print();
    private:
        Node * head{};
        int size_{};
};

List::List(initializer_list<int> l) {
    for (auto ele : l) {
        head = new Node{ele, head};
        size_++;
    }
}

void List::print() {
    Node * temp = head;
    cout << "( ";
    while (temp != nullptr) {
        cout << temp -> element << " ";
        temp = temp -> next;
    }
    cout << ")";
}

void List::sort() {
    if (head == nullptr)
        return;
    Node* frontier = nullptr;

    while (head != nullptr)
    {
        Node* max_prev = nullptr;
        Node* max = head;

        Node* prev = nullptr;
        Node* current = head;
        while (current != nullptr) {
            if (current->element > max->element) {
                max_prev = prev;
                max = current;
            }
            prev = current;
            current = current->next;
        }

        if (max_prev == nullptr) {
            head = head->next;
        }
        else {
            max_prev->next = max->next;
        }

        max->next = frontier;
        frontier = max;
    }

    head = frontier;
}

int main() {
    List l{8, 2, 4, 1, 5};
    cout << "Before sort ";
    l.print();
    cout << endl;

    l.sort();
    cout << "After sort ";
    l.print();
    cout << endl;
}
