#include <iostream>

/* there are 2 kinds of equalities in c++
1) structural: birebir denk ama aynı değil
2) physical: aynı ve tek objeyi gösteriyorlar, dolayısıyla denk */

class Sample
{
public:
	Sample(int v);
	~Sample(void);

	int getFoo(void) const;
	// taking as a parameter (the address of a sample instance). Making a
	// comparison between the current instance and the passed parameter instance
	int compare(Sample *other) const;

private:
	int _foo;
};

Sample::Sample(int v) : _foo(v)
{
	std::cout << "Constructor called" << std::endl;
	return;
}

Sample::~Sample(void)
{
	std::cout << "Destructor called" << std::endl;
	return;
}

int Sample::getFoo(void) const
{
	return this->_foo;
}

int Sample::compare(Sample *other) const
{
	if (this->_foo < other->getFoo())
		return (-1);
	else if (this->_foo > other->getFoo())
		return (1);
	return (0);
}
