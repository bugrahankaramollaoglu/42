#include <iostream>

class Deneme
{
private:
	int _val;

public:
	Deneme();
	~Deneme();
	int getVal();
	void setVal(int v);
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

int Deneme::getVal()
{
	return this->_val;
}

void Deneme::setVal(int v)
{
	this->_val = v;
	return;
}

int main()
{
	Deneme deneme;
	deneme.setVal(5);
	std::cout << "what is got: " << deneme.getVal() << std::endl;
}
