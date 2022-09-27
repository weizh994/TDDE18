#include <iostream>

class List
{
private:
  struct ListNode
  {
    int value;
    List *next;
    ListNode(int const &tmp)
    {
      value = tmp;
      next = nullptr;
    };
  };
  ListNode *FirstNode;

public:
  List(int const &a);        // constructor
  List(List const &theList); // copy constructor
  ~List();                   // destructor
  void remove(ListNode &node);
  void inseret(ListNode &node);
  void print() const;
  int getValue(int const &n);
};

List::List(int const &tmp)
{
  FirstNode = new ListNode(tmp);
}

List::~List()
{
  delete FirstNode;
}

void List::print() const
{
  std::cout << FirstNode->value << std::endl;
}

int main()
{
  List l(123);
  l.print();
}