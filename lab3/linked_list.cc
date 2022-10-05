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
  int ListLength;

public:
  List();                                // normal constructor
  List(std::initializer_list<int> list); // constructor with initializer_list
  List(List const &theList);             // copy constructor
  ~List();                               // destructor
  void remove(int const &insValue);      // Done
  void insert(int const &delValue);      // Done
  void print() const;
  List &operator=(List const &rightList);
  int findIndex(int const &n) const; // find Index according value:n
  int getValue(int const &n) const;  // get Value according index:n
};

List::List()
{
  FirstNode = nullptr;
  ListLength = 0;
}

List::List(std::initializer_list<int> list)
{
  FirstNode = nullptr;
  ListLength = 0;
  for (int i : list)
  {
    insert(i);
  }
}

List::List(List const &theList)
{
  FirstNode = nullptr;
  ListLength = 0;
  ListNode *tmp = theList.FirstNode;
  while (tmp != nullptr)
  {
    insert(tmp->value);
    tmp = tmp->next;
  }
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

List &List::operator=(List const &rightList)
{
  List::~List();
  ListNode *tmp = rightList.FirstNode;
  while (tmp != nullptr)
  {
    insert(tmp->value);
    tmp = tmp->next;
  }
  return *this;
}

void List::insert(int const &insValue)
{
  if (FirstNode == nullptr)
  {
    FirstNode = new ListNode(insValue);
    ++ListLength;
  }
  else
  {
    ListNode *tmp = new ListNode(insValue);
    if (tmp->value <= FirstNode->value)
    {
      tmp->next = FirstNode;
      FirstNode = tmp;
      ++ListLength;
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
          ++ListLength;
        }
        else // insert node is the biggest
        {
          CurrentNode->next = tmp;
          ++ListLength;
        }
      }
      else // at the internial of the list
      {
        tmp->next = CurrentNode;
        PreviousNode->next = tmp;
        ++ListLength;
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
    if (delValue == FirstNode->value)
    {
      FirstNode = FirstNode->next;
      delete tmp;
    }
    else
    {
      while (tmp->value != delValue && tmp->next != nullptr)
      {
        PreviousNode = tmp;
        tmp = tmp->next;
      }
      if (tmp->next == nullptr)
      {
        if (tmp->value != delValue)
        {
          std::cout << "Not exist" << std::endl;
        }
        else
        {
          PreviousNode->next = nullptr;
          delete tmp;
        }
      }
      else
      {
        PreviousNode->next = tmp->next;
        delete tmp;
      }
    }
  }
}

void List::print() const
{
  ListNode *CurrentNode = FirstNode;
  if (CurrentNode == nullptr)
  {
    std::cerr << "List is Empty";
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

int List::getValue(int const &n) const
{
  if (n > ListLength)
  {
    return -1;
  }
  else
  {
    ListNode *tmp = FirstNode;
    for (int i = 0; i < n; ++i)
    {
      tmp = tmp->next;
    }
    return tmp->value;
  }
}

int main()
{
  List l1{3, 4, 5, 6, 7};
  l1.print();
}