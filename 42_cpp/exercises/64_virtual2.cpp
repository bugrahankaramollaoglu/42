#include <iostream>

/* apart from that if you use virtual keyword with
destructors, it causes the proper-destruct-chain
this allows the correct way of calling destructor
functions, hence the memory-freeings, from derived
to base class, allowing no leaks whatsoever */

/* When to set destructors virtual in base class?
When someone will delete a derived-class object via
a base-class pointer. altın kural: make your destructor
virtual if your class has any virtual functions*/

class Base
{
public:
	Base()
	{
		std::cout << "Base constructor" << std::endl;
	}
	virtual ~Base()
	{
		std::cout << "Base destructor" << std::endl;
	}
};

int main()
{
	Base *base = new Base();
	delete base;
}
