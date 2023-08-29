#include "brain.hpp"

Brain::Brain()
{
	std::cout << "Brain default constructor called" << std::endl;
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}

Brain::Brain(const Brain &other)
{
	std::cout << "Brain copy constructor called" << std::endl;
	*this = other;
}

Brain &Brain::operator=(const Brain &other)
{
	std::cout << "brain assignment operator overload called" << std::endl;

	for (int i = 0; i < 100; i++)
		this->_ideas[i] = other._ideas[i];

	return (*this);
}

std::string *Brain::getIdeas()
{
	return (this->_ideas);
}

std::string Brain::getIdea(int i) const
{
	return (this->_ideas[i]);
}
