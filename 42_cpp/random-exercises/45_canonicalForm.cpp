#include <iostream>

/* orthodox canonical form includes

	1) a default constructor
	2) a default destructor
	3) a copy constructor
	4) an assignment operator */

class Deneme
{
public:
	Deneme();							  // 1
	~Deneme();							  // 2
	Deneme(Deneme const &src);			  // 3
	Deneme &operator=(Deneme const &rhs); // 4

	int getVal() const;

private:
	int _val;
};

Deneme::Deneme() : _val(0)
{
	std::cout << "Constructor called" << std::endl;
	return;
}

Deneme::~Deneme()
{
	std::cout << "Destructor called" << std::endl;
	return;
}

Deneme::Deneme(Deneme const &src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
	return;
}

Deneme &Deneme::operator=(Deneme const &rhs)
{
	std::cout << "Assignment operator called" << std::endl;
	this->_val = rhs.getVal();
	return *this;
}

int Deneme::getVal() const
{
	return this->_val;
}

int main()
{
	Deneme deneme;
	Deneme deneme2(deneme);
	Deneme deneme3 = deneme;
	Deneme deneme4;
	deneme4 = deneme;
}
