
class List
{
private:
  struct ListNode
  {
    int value;
    List *next;
  };
  ListNode *FirstNode;

public:
  List(int a); // constructor
  ~List();     // destructor
  void remove(ListNode &node);
  void inseret(ListNode &node);
  void print(List const &l);
  int getValue(int const &n);
};

List::List(int a)
{
  ListNode NewNode{a, nullptr};
  FirstNode = &NewNode;
}

List::~List()
{
}
