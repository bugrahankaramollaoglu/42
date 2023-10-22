#include <iostream>

// yet another example about virtuals

/* A base class destructor should be either public and virtual,
or protected and nonvirtual." */

class Base
{
public:
	Base()
	{
		std::cout << "base constructor called" << std::endl;
	}

	/* eğer base pointer + derived() kullanıyorsan
	base class destructorını virtual yapmazsan derived class destructorı
	çalışmaz. çalışsın istiyosan base-class destr virtual yapmalısın.  */
	virtual ~Base()
	{
		std::cout << "base destructor called" << std::endl;
	}
};

class Derived : public Base
{
public:
	Derived()
	{
		std::cout << "derived constructor called" << std::endl;
	}
	~Derived()
	{
		std::cout << "derived destructor called" << std::endl;
	}
};

int main()
{
	Base *x = new Derived();
	delete x;
}
