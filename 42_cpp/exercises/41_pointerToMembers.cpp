#include <iostream>

// To have pointer to data member and member functions, you need to make them public

class Deneme
{
public:
	int x;

	Deneme(void);
	~Deneme(void);

	void fun(void) const;
};

Deneme::Deneme(void) : x(0)
{
	std::cout << "constructor called" << std::endl;
	return;
}

Deneme::~Deneme(void)
{
	std::cout << "destructor called" << std::endl;
	return;
}

void Deneme::fun(void) const
{
	std::cout << "member function fun called" << std::endl;
	return;
}

int main(void)
{
	// stackte yer ayrildi
	Deneme deneme;

	// pointer to the instance of class
	Deneme *denemeP = &deneme;

	// declaring a pointer on an integer attribute of Deneme class
	int Deneme::*p = &Deneme::x;

	// declaring a pointer on a const member function of Deneme class
	void (Deneme::*f)(void) const;

	std::cout << deneme.x << std::endl; // 0
	deneme.*p = 21;
	std::cout << denemeP->x << std::endl; // 21
	denemeP->x = 50;
	std::cout << denemeP->x << std::endl; // 50
}
