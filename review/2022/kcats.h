#ifndef KCATS_H
#define KCATS_H

class KCats
{
public:
    KCats()=default;
    KCats(KCats &&otherCats);
    ~KCats();

    KCats &operator=(KCats &&otherCats);

    bool empty() const;
    void push(int data);
    int pop();

private:
    // KCats(KCats const &);
    // KCats &operator=(KCats const &);
    struct Cat
    {
        int value;
        Cat *tail;
    };
    Cat *head;
};
#endif