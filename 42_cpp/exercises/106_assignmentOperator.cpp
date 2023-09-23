#include <iostream>

/* assignment operator ise benzer işe yarar
ama ilklendirilmiş objeye kopyalamada yarar ve hafıza vs. yönünden farklıdır.
copy constructor kullanırsan iki farklı hafıza alanı yaratılır ama = operatörü
kullanırsan aynı memory blogunu kullanırlar.
copy constructor yeni bir obje yaratırken direkt halihazırda var olan, daha evvel
ilklendirdiğimiz bir başka objenin içeriklerini kopyalar.
copy assignment operator sayesinde ise halihazirda var olan iki farklı obje var,
birinden birine kopyalama yaparken kullaniyoruz. */

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
	Deneme b(0, 0);
	b = a;
	a.displayNums(); // 10 24
	b.displayNums(); // 10 24
}
