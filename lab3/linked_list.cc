#include <iostream>
#include <initializer_list>

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
  List(int const &a); // constructor
  List(std::initializer_list<int> list)
  {
    for (int i : list)
    {
      insert(i);
    }
  };       // copy constructor
  ~List(); // destructor
  void remove(int const &insValue);
  void insert(int const &delValue); // Done
  void print() const;
  int getValue(int const &n);
};

// List(std::initializer_list<int> list)

List::~List()
{
  while (FirstNode != nullptr)
  {
    ListNode *temp = FirstNode;
    FirstNode = FirstNode->next;
    delete temp;
  }
}

void List::insert(int const &insValue)
{
  if (FirstNode == nullptr)
  {
    FirstNode = new ListNode(insValue);
  }
  else
  {
    ListNode *tmp = new ListNode(insValue);
    if (tmp->value <= FirstNode->value)
    {
      tmp->next = FirstNode;
      FirstNode = tmp;
    }
    else
    {
      ListNode *CurrentNode = FirstNode;
      ListNode *PreviousNode = FirstNode;
      while (tmp->value > CurrentNode->value && CurrentNode->next != nullptr)
      {
        PreviousNode = CurrentNode;
        CurrentNode = CurrentNode->next;
      }
      if (CurrentNode->next == nullptr) // at the end of the list
      {
        if (tmp->value <= CurrentNode->value) // last node larger than insert node
        {
          tmp->next = CurrentNode;
          PreviousNode->next = tmp;
        }
        else // insert node is the biggest
        {
          CurrentNode->next = tmp;
        }
      }
      else // at the internial of the list
      {
        tmp->next = CurrentNode;
        PreviousNode->next = tmp;
      }
    }
  }
}

void List::remove(int const &delValue)
{
  if (FirstNode == nullptr)
  {
    std::cout << "Not exist" << std::endl;
  }
  else
  {
    ListNode *tmp = FirstNode;
    ListNode *PreviousNode = tmp;
    while (tmp->value != delValue && tmp->next != nullptr)
    {
      PreviousNode = tmp;
      tmp = tmp->next;
    }
    if (tmp->next == nullptr)
    {
      std::cout << "Not exist" << std::endl;
    }
    else
    {
      PreviousNode->next = tmp->next;
      delete tmp;
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
  List l{1, 2, 3};
  l.insert(1);
  l.insert(4);
  l.insert(6);
  l.insert(2);
  l.insert(5);
  l.print();
}