#include <string>
#include <iostream>

/* In C++, when you have a base class with a virtual
function and you create a derived class that overrides
that function, using virtual changes how function calls
are resolved at runtime */

/* bu koddaki her şey 66.cpp ile birebir aynı tek
fark sayHello() virtual olması. dolayısıyla outputları
da farklı oluyor. sebebi şu:

1) without virtual keyword:

Character *b = new Warrior();
b->sayHello("ahmet"); // Calls Character::sayHello()
it decides which type of sayHello() will be called at compileTime

2) with virtual keyword:

Character *b = new Warrior();
b->sayHello("ahmet"); // Calls Warrior::sayHello()
it decides which type of sayHello() will be called at runTime */

/* in cpp, polymorphism is generally divided into 2
	1) Compile time polymorphism (early binding / static polymorphism) - static in nature
	2) Runtime polymorphism (late binding / dynamic polymorphism) */

class Character
{
public:
	virtual void sayHello(std::string const &target);
};

// function overriding
class Warrior : public Character
{
public:
	virtual void sayHello(std::string const &target);
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
	b->sayHello("ahmet"); // Hello ahmet, i am a warrior!

	return 0;
}
