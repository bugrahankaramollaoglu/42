#include <iostream>

// shallow copy örneği

class Deneme
{
private:
	int *_value;

public:
	Deneme(int val) : _value(new int(val)) {}

	// Shallow copy constructor
	Deneme(const Deneme &other) : _value(other._value) {}
	// deep copy olsaydı:
	// Deep(const Deep &other) : _value(new int(*other._value)) {}

	void setVal(int val)
	{
		*_value = val;
	}

	int getVal() const
	{
		return *_value;
	}
};

int main()
{
	Deneme deneme(12);
	Deneme deneme2(deneme);
	std::cout << deneme.getVal() << std::endl;
	std::cout << deneme2.getVal() << std::endl;
	deneme.setVal(23);
	std::cout << deneme.getVal() << std::endl;
	std::cout << deneme2.getVal() << std::endl;
}
