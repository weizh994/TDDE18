#include "kcats.h"

#include <utility>

KCats::KCats(KCats&& other)
    : bottom{other.bottom}
{
    other.bottom = nullptr;
}

KCats::~KCats()
{
    while (!empty())
    {
        pop();
    }
}

KCats& KCats::operator=(KCats&& other)
{
    std::swap(bottom, other.bottom);
    return *this;
}

bool KCats::empty() const
{
    return bottom == nullptr;
}

void KCats::push(int data)
{
    bottom = new Node{data, bottom};
}

int KCats::pop()
{
    int value {bottom->value};
    Node* next {bottom->next};
    delete bottom;
    bottom = next;
    return value;
}
