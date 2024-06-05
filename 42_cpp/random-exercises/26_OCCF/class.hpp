#ifndef CLASS_HPP
#define CLASS_HPP

#include <iostream>

class Deneme
{
public:
	const char *name = "bugra";

public:
	Deneme();
	~Deneme();
	Deneme(const Deneme &other);
	Deneme &operator=(const Deneme &other);
};

#endif
