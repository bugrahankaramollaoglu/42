#include <iostream>

// farklı tip parametreleri oldugu sürece aynı ismi farklı fonksiyonlara verebiliriz

class Deneme
{
public:
	Deneme();
	~Deneme();

	void fun(int a) { std::cout << "fun(int a) called" << std::endl; }
	void fun(char b) { std::cout << "fun(char b) called" << std::endl; }
	void fun(double c) { std::cout << "fun(float c) called" << std::endl; }
};

Deneme::Deneme()
{
	std::cout << "Constructor called" << std::endl;
	return;
}

Deneme::~Deneme()
{
	std::cout << "Destructor called" << std::endl;
	return;
}

int main()
{
	Deneme deneme;
	deneme.fun(5);
	deneme.fun('a');
	deneme.fun(6.23);
}
