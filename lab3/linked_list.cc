#include <iostream>

class List
{
private:
  struct ListNode
  {
    int value;
    ListNode *next;
    ListNode(int const &newValue) // Node constructor
    {
      value = newValue;
      next = nullptr;
    };
  };
  ListNode *FirstNode;

public:
  List(int const &a);        // constructor
  List(List const &theList); // copy constructor
  ~List();                   // destructor
  void remove(ListNode &node);
  void inseret(int const &inValue);
  void print() const;
  int getValue(int const &n);
};

List::List(int const &tmp)
{
  FirstNode = new ListNode(tmp);
}

List::~List()
{
  while (FirstNode != nullptr)
  {
    ListNode *temp = FirstNode;
    FirstNode = FirstNode->next;
    delete temp;
  }
}

void List::inseret(int const &inValue)
{
  if (FirstNode == nullptr)
  {
    FirstNode = new ListNode(inValue);
  }
  else
  {
    ListNode *tmp = new ListNode(inValue);
    if (tmp->value <= FirstNode->value)
    {
      tmp->next = FirstNode;
      FirstNode = tmp;
    }
    else
    {
      ListNode *OriginFirstNode = FirstNode;
      ListNode *PreviousNode = FirstNode;
      while (tmp->value > FirstNode->value && FirstNode->next != nullptr)
      {
        PreviousNode = FirstNode;
        FirstNode = FirstNode->next;
      }
      if (FirstNode->next == nullptr)
      {
        FirstNode->next = tmp;
      }
      else
      {
        tmp->next = FirstNode;
        PreviousNode->next = tmp;
      }
      FirstNode = OriginFirstNode;
    }
  }
}

void List::print() const
{
  ListNode *CurrentNode = FirstNode;
  if (CurrentNode == nullptr)
  {
    std::cerr << "List is Empty" << std::endl;
  }
  else
  {
    while (CurrentNode != nullptr)
    {
      std::cout << CurrentNode->value << " ";
      CurrentNode = CurrentNode->next;
    }
  }
  std::cout << std::endl;
}
int main()
{
  List l(3);
  l.print();
}