#include <iostream>

/* virtual anahtar kelimesi sayesinde polymorphism yapiyoruz.
mesela member fonksiyonlara override yapabiliyoruz.  */

/* though not used here, In C++, when a class has virtual functions and is meant to be
used as a base class in a hierarchy, it is a good practice to declare its destructor as virtual.  */

class Shape
{
public:
	virtual void draw()
	{
		std::cout << "drawing a shape" << std::endl;
	}
};

class Square : public Shape
{
public:
	void draw() override
	{
		std::cout << "no, it is square" << std::endl;
	}
};

int main()
{
	Square square;
	square.draw();
}

