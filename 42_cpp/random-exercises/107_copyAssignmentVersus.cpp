#include <iostream>

class Deneme
{
	int x;
	int y;

public:
	Deneme(int num1, int num2)
	{
		x = num1;
		y = num2;
	}

	// copy constructor
	Deneme(const Deneme &old)
	{
		x = old.x;
		y = old.y;
	}

	// assignment operator
	const Deneme &operator=(const Deneme &old)
	{
		std::cout << "called = operator\n";
		this->x = old.x;
		this->y = old.y;
		return *this;
	}

	void displayNums()
	{
		std::cout << x << " " << y << "\n";
	}
};

int main()
{
	Deneme a(10, 24);

	// bunda copy constructor çağrıldı
	Deneme b(a);

	Deneme c(0, 0);

	// bunda assignment operator çağrıldı
	c = a;

	a.displayNums(); // 10 24
	b.displayNums(); // 10 24
	c.displayNums(); // 10 24
}
