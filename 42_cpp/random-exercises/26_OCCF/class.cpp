#include "class.hpp"

Deneme::Deneme()
{
	std::cout << "Default constructor called" << std::endl;
}

Deneme::~Deneme()
{
	std::cout << "Destructor called" << std::endl;
}

Deneme::Deneme(const Deneme &other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Deneme &Deneme::operator=(const Deneme &other)
{
	std::cout << "Assignation operator called" << std::endl;
	if (this != &other)
	{
		this->name = other.name;
	}
	return (*this);
}
