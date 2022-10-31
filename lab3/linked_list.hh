//
// Created by 郑伟雄 on 2022/10/31.
//

#ifndef TDDE18_LINKED_LIST_H
#define TDDE18_LINKED_LIST_H
#include <initializer_list>
class List
{
private:
  // friend class ListNode;
  struct ListNode
  {
    // private:
    int value;
    ListNode *next;

    // public:
    ListNode(int const &newValue) // Node constructor
    {
      value = newValue;
      next = nullptr;
    };
  };
  int ListLength;
  ListNode *FirstNode;
  ListNode *getNode(int const &index) const
  {
    ListNode *tmp = FirstNode;
    for (int i = 1; i < index; ++i)
    {
      tmp = tmp->next;
    }
    return tmp;
  };

public:
  List();                                // normal constructor
  List(std::initializer_list<int> list); // constructor with initializer_list
  List(List const &otherList);           // copy constructor
  List(List &&otherList);                // move constructor;
  ~List();                               // destructor
  void remove(int const &insValue);      // Done
  void insert(int const &delValue);      // Done
  void print() const;
  List &operator=(List const &rightList); // Done   copy assignment operator
  List &operator=(List &&rightList);      // Done   move assignment operator
  int findIndex(int const &n) const;      // Done   find Index according value:n
  int getValue(int const &n) const;       // Done   get Value according index:n
};
#endif // TDDE18_LINKED_LIST_H