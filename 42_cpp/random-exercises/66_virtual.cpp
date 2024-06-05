#include <string>
#include <iostream>

class Character
{
public:
	void sayHello(std::string const &target);
};

// function overriding
class Warrior : public Character
{
public:
	void sayHello(std::string const &target);
};

void Character::sayHello(const std::string &target)
{
	std::cout << "Hello " << target << "! im just a character" << std::endl;
}

void Warrior::sayHello(const std::string &target)
{
	std::cout << "Hello " << target << ", i am a warrior!" << std::endl;
}

int main(void)
{
	Warrior *a = new Warrior();

	Character *b = new Warrior();

	a->sayHello("ahmet"); // Hello ahmet, i am a warrior!
	b->sayHello("ahmet"); // Hello ahmet! im just a character

	delete a;
	delete b;

	return 0;
}

// ama eğer virtual kullanırsak -> 67.cpp
