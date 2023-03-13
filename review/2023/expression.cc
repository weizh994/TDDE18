#include <iostream>
class Node
{
public:
	virtual ~Node()=default;
	virtual int eval()const=0;
};
class Number : public Node
{
	private:
		int value;
	public:
		Number(int a):value{a}{};
		int eval()const override{return value;}
};
class Binary : public Node
{
protected:
	Node& left;
	Node& right;
public:
	Binary(Node& left,Node& right):left{left},right{right}{}
};
class Addition : public Binary
{
	public:
	using Binary::Binary;
	int eval()const override
	{
		return left.eval()+right.eval();
	}
};
class Multiplication : public Binary
{
	public:
		using Binary::Binary;
		int eval()const override
		{
			return left.eval()*right.eval();
		}
};
int main()
{
    Number five{5};
    Number three{3};
    Number two{2};
    Multiplication multiplication{five, two};
    Addition addition{three, multiplication};
    std::cout << addition.eval() << std::endl;
}
