#include <iostream>

class Deep
{
private:
	int *_value;

public:
	Deep(int val) : _value(new int(val)) {}

	// Deep copy constructor
	Deep(const Deep &other) : _value(new int(*other._value)) {}
	// shallow copy olsaydı:
	// Shallow(const Shallow &other) : _value(other._value) {}

	void set_value(int val)
	{
		*_value = val;
	}

	int get_value() const
	{
		return *_value;
	}

	~Deep()
	{
		delete _value;
	}
};

int main()
{
	Deep original(10);
	Deep copy = original; // Deep copy

	original.set_value(20);
	std::cout << "Original _value: " << original.get_value() << std::endl;
	std::cout << "Copied _value: " << copy.get_value() << std::endl;

	return 0;
}
