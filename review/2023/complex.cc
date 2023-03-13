#include <iostream>

// Implement your classes here
class Complex
{
	private:
		double real;
		double imag;
	public:
		Complex(double a=0,double b=0):real{a},imag{b}{}
		double Re()const{return real;}
		double Im()const{return imag;}
	friend std::ostream &operator<<(std::ostream &os, Complex const &x)
	{
		return os<<x.real<<' '<<'+'<<' '<<x.imag<<'i';
	}
	Complex operator+(Complex const &rhs) const
	{
		Complex result{};
		result.real=real+rhs.Re();
		result.imag = imag+rhs.Im();
		return result;
	}
	Complex operator*(Complex const &rhs) const
	{
		Complex result{};
		result.real=real*rhs.Re()-imag*rhs.Im();
		result.imag=real*rhs.Im()+imag*rhs.Re();
		return result;
	}
};


// You may *NOT* modify the main function
int main()
{
    Complex a{1.0, 2.0};
    Complex const b{3.0, 4.0};

    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;
    std::cout << "a + b = " << a + b << std::endl;
    std::cout << "a * b = " << a * b << std::endl;

    return 0;
}
