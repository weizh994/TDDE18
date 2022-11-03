#include <iostream>
#include <initializer_list>
#include "linked_list.hh"

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

List::List(List const &otherList)
{
  FirstNode = nullptr;
  ListLength = 0;
  ListNode *tmp = otherList.FirstNode;
  while (tmp != nullptr)
  {
    insert(tmp->value);
    tmp = tmp->next;
  }
}

List::List(List &&otherList)
{
  FirstNode = otherList.FirstNode;
  ListLength = otherList.ListLength;
  otherList.FirstNode = nullptr;
  otherList.ListLength = 0;
}

List::~List()
{
  if (FirstNode != nullptr)
  {
    ListNode *temp = FirstNode;
    FirstNode = FirstNode->next;
    delete temp;
    this->~List();
  }
}

List &List::operator=(List const &rightList)
{
  this->~List();
  ListNode *tmp = rightList.FirstNode;
  while (tmp != nullptr)
  {
    insert(tmp->value);
    tmp = tmp->next;
  }
  return *this;
}

List &List::operator=(List &&rightList)
{
  this->~List();
  ListLength = rightList.ListLength;
  FirstNode = rightList.FirstNode;
  rightList.FirstNode = nullptr;
  rightList.ListLength = 0;
  return *this;
}

void List::insert(int const &insValue)
{
  if (FirstNode == nullptr) // empty list
  {
    FirstNode = new ListNode(insValue);
    ++ListLength;
  }
  else // not empty
  {
    ListNode *tmp = new ListNode(insValue);
    if (tmp->value <= FirstNode->value) // smallest Node
    {
      tmp->next = FirstNode;
      FirstNode = tmp;
      ++ListLength;
    }
    else // in the List OR at the end
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
      --ListLength;
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
          --ListLength;
        }
      }
      else
      {
        PreviousNode->next = tmp->next;
        delete tmp;
        --ListLength;
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

int List::findIndex(int const &n) const
{
  ListNode *tmp = FirstNode;
  int index = 1;
  while (tmp->value != n)
  {
    index++;
    if (index > ListLength) // get the end of the List, value does not exist
    {
      return -1;
    }
    else
    {
      tmp = tmp->next;
    }
  }
  return index;
}

int List::getValue(int const &n) const
{
  if (n > ListLength) // illigal search
  {
    return -1;
  }
  else
  {
    ListNode *tmp = FirstNode;
    for (int i = 1; i < n; ++i)
    {
      tmp = tmp->next;
    }
    return tmp->value;
  }
}

bool List::is_empty() const
{
  return FirstNode == nullptr;
}
int List::size() const
{
  return ListLength;
}
