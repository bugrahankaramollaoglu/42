#include <iostream>

/* virtual anahtar kelimesi sayesinde polymorphism yapiyoruz.
mesela member fonksiyonlara override yapabiliyoruz.  */

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

