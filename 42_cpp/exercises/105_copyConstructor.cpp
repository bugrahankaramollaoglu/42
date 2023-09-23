#include <iostream>

/* copy constructor bir class objesini içindekilerle
beraber bir başka obje yaratip ona kopyalamakta kullanılır. */

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

	void displayNums()
	{
		std::cout << x << " " << y << "\n";
	}
};

int main()
{
	Deneme a(10, 24);
	Deneme b = a;
	a.displayNums(); // 10 24
	b.displayNums(); // 10 24
}
