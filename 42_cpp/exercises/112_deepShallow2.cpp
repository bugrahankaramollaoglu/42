#include <iostream>
#include <string>

// let's see shallow copy

class Deneme
{
public:
	int *x;

public:
	Deneme(int val)
	{
		x = new int(val);
	}

	Deneme(const Deneme &obj)
	{
		x = obj.x; // shallow copied
	}

	~Deneme()
	{
		delete x;
	}
};

int main()
{
	Deneme deneme(10);
	Deneme deneme2 = deneme;
	std::cout << *(deneme.x) << std::endl;	// 10
	std::cout << *(deneme2.x) << std::endl; // 10

	*(deneme.x) = 20;

	std::cout << *(deneme.x) << std::endl;	// 20
	std::cout << *(deneme2.x) << std::endl; // 20.
	// sığ kopyaladığımız için birindeki değişiklik diğerinde de etki etti
}
