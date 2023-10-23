#include <string>
#include <iostream>

class Character
{
public:
	void sayHello(std::string const &target)
	{
		std::cout << "Hello " << target << "! im just a character" << std::endl;
	}
};

// function overriding
class Warrior : public Character
{
public:
	void sayHello(std::string const &target)
	{
		std::cout << "Hello " << target << ", i am a warrior!" << std::endl;
	}
};

int main(void)
{
	Character *a = new Warrior();
	Warrior *b = new Warrior();

	a->sayHello("ahmet"); // Hello ahmet! im just a character
	b->sayHello("ahmet"); // Hello ahmet, i am a warrior!

	delete a;
	delete b;

	return 0;
}

// ama eğer virtual kullanırsak -> 67.cpp
