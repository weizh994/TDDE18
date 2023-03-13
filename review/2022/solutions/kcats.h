#ifndef KCATS_H_
#define KCATS_H_

class KCats
{
public:

    KCats() = default;
    KCats(KCats&&);
    ~KCats();

    KCats& operator=(KCats&&);

    bool empty() const;
    void push(int data);
    int pop();

private:

    KCats(KCats const&)
    {
    }

    KCats& operator=(KCats const&)
    {
	return *this;
    }
    
    struct Node
    {
        int value;
        Node* next;
    };

    Node* bottom{nullptr};
};

#endif//KCATS_H_
