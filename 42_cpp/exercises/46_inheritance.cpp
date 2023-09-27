#include <iostream>

class Animal
{
private:
	int _numberOfLegs;

public:
	Animal() : _numberOfLegs(4)
	{
		std::cout << "Animal constructor called" << std::endl;
		return;
	}
	~Animal() // destructor
	{
		std::cout << "Animal destructor called" << std::endl;
		return;
	}
	Animal(Animal const &other) // copy constructor
	{
		std::cout << "Animal copy constructor called" << std::endl;
		*this = other;
		return;
	}
	Animal &operator=(Animal const &rhs) // assignment operator overload
	{
		std::cout << "Animal assignment operator overload called" << std::endl;
		this->_numberOfLegs = rhs.getNumberOfLegs();
		return *this;
	}

	int getNumberOfLegs() const
	{
		return this->_numberOfLegs;
	}

	void run(int distance) const { std::cout << "Animal runs " << distance << " meters" << std::endl; }
	void walk(int distance) const { std::cout << "Animal walks " << distance << " meters" << std::endl; }
	void eat(std::string const &eatWhat) const { std::cout << "Animal eats " << eatWhat << std::endl; }
};

class Cat : public Animal
{
public:
	Cat() : Animal()
	{
		std::cout << "Cat constructor called" << std::endl;
		return;
	}
	~Cat() // destructor
	{
		std::cout << "Cat destructor called" << std::endl;
		return;
	}
	Cat(Cat const &other)
	{
		std::cout << "Cat copy constructor called" << std::endl;
		*this = other;
		return;
	}
	Cat &operator=(Cat const &other)
	{
		std::cout << "Cat assignment operator overload called" << std::endl;
		this->Animal::operator=(other);
		return *this;
	}

	void meow(void) const { std::cout << "Cat meows" << std::endl; }
};

int main()
{
	Cat cat;
	cat.meow();
	cat.run(10);
	cat.walk(10);
	cat.eat("fish");
}
