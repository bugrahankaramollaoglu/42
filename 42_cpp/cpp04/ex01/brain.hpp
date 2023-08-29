#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include "animal.hpp"

class Brain
{
private:
	std::string _ideas[100];

public:
	Brain();
	~Brain();
	Brain(const Brain &other);
	Brain &operator=(const Brain &brain);
	std::string *getIdeas();
	std::string getIdea(int i) const;
};

#endif
