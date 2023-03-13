#include "kcats.h"


//KCats::KCats() : head{nullptr} {}
KCats::KCats(KCats &&otherCats)
{
  head = otherCats.head;
  otherCats.head = nullptr;
}
KCats::~KCats()
{
  while (!empty())
  {
    pop();
  }
}

/* KCats &KCats::operator=(KCats const &otherCats)
{
  this->~KCats();
  KCats temp{};
  Cat *curr = otherCats.head;
  while (curr)
  {
    temp.push(curr->value);
  }
  while (temp.head)
  {
    this->push(temp.pop());
  }
  return *this;
} */
KCats &KCats::operator=(KCats &&otherCats)
{
  this->~KCats();
  head = otherCats.head;
  otherCats.head = nullptr;
  return *this;
}

bool KCats::empty() const
{
  return head == nullptr;
}
void KCats::push(int data)
{
  head = new Cat{data, head};
}
int KCats::pop()
{
  int temp = head->value;
  Cat *headTemp = head;
  head = head->tail;
  delete headTemp;
  return temp;
}