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
    ListNode(int newValue) // Node constructor
    {
      value = newValue;
      next = nullptr;
    };
  };
  int ListLength;
  ListNode *FirstNode;
  ListNode *getNode(int index) const
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
  void remove(int insValue);             // Done
  void insert(int delValue);             // Done
  //void search(ListNode *PreviousNode,ListNode *CurrentNode, int Value);
  void print() const;
  List &operator=(List const &rightList); // Done   copy assignment operator
  List &operator=(List &&rightList);      // Done   move assignment operator
  int findIndex(int n) const;             // Done   find Index according value:n
  int getValue(int n) const;              // Done   get Value according index:n
  bool is_empty() const;
  int size() const;
};
#endif // TDDE18_LINKED_LIST_H
