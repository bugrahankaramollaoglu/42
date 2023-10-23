#include <iostream>

// imagine we have such a base class
class Base
{
public:
	virtual void announce()
	{
		std::cout << "hello from base" << std::endl;
	}
};

// and such a derived class publicly inheriting
class Derived : public Base
{
public:
	void announce()
	{
		std::cout << "hello from derived" << std::endl;
	}
};

int main()
{
	// Base base;
	// base.announce(); // hello from base

	// Derived derived;
	// derived.announce(); // hello from derived

	// it is okay so far for we kept it simple
	// but what if one would want to say

	/* 	we create an object with Base pointer but from Derived()
		class. it must say "hello from derived" since it is instantiated
		as Derived. and actually it does, but only if we use the "virtual"
		keyword and give the same name for the function in both classes. if we were to
		remove the virtual keyword from the function in the base class,
		obj->announce() would print <hello from base> because OS wouldn't know
		it is supposed to implicitly override the function according to the derived
		class. Or, another scenario - if we kept the virtual but assigned different
		names for the functions, it'd still use Base's function. */
	Base *obj = new Derived();
	obj->announce();
}
