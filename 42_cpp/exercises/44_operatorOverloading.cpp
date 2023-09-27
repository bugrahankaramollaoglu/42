#include <iostream>

// you can overload operators like +, -, *, /, =, <, >, ==, &=, |=,
// <<, >>, %, ^, !, ~, ++, --, &&, ||, +=, -=, *=, /=, %=, ^=, >>=, <<=, [] ........

class Integer
{
public:
	Integer(int const i);
	~Integer();

	int getValue() const;

	Integer &operator=(Integer const &rightHandSide);
	Integer operator+(Integer const &rightHandSide) const;

private:
	int _val;
};

std::ostream &operator<<(std::ostream &other, Integer const &rightHandSide);

Integer::Integer(const int n) : _val(n)
{
	std::cout << "Constructor called with value " << n << std::endl;
}

Integer::~Integer()
{
	std::cout << "Destructor called with value " << this->_val << std::endl;
}

int Integer::getValue() const
{
	return this->_val;
}

Integer &Integer::operator=(const Integer &rhs)
{
	std::cout << "Assignment operator called from " << this->_val;
	std::cout << " to " << rhs.getValue() << std::endl;

	this->_val = rhs.getValue();

	return *this;
}

Integer Integer::operator+(const Integer &rhs) const
{
	std::cout << "Addition operator called with " << this->_val;
	std::cout << " and " << rhs.getValue() << std::endl;

	return Integer(this->_val + rhs.getValue());
}

std::ostream &operator<<(std::ostream &o, Integer const &rhs)
{
	o << rhs.getValue();
	return o;
}

int main()
{
	Integer x(30);
	Integer y(10);
	Integer z(0);

	std::cout << "Value of x : " << x << std::endl; // 30
	std::cout << "Value of y : " << y << std::endl; // 10
	y = Integer(12);								// = is the overloaded operator, not default one
	std::cout << "Value of y : " << y << std::endl; // 12

	std::cout << "Value of z : " << z << std::endl; // 0
	z = x + y;										// + is the overloaded operator, not default one
	std::cout << "Value of z : " << z << std::endl; // 42 (30+12)

	return 0;
}
