#include <iostream>

// shallow copy örneği

class Shallow
{
private:
	int *_value;

public:
	Shallow(int val) : _value(new int(val)) {}

	// Shallow copy constructor
	Shallow(const Shallow &other) : _value(other._value) {}
	// deep copy olsaydı:
	// Deep(const Deep &other) : _value(new int(*other._value)) {}

	void set_value(int val)
	{
		*_value = val;
	}

	int get_value() const
	{
		return *_value;
	}
};

int main()
{
	Shallow original(10);
	Shallow copy = original; // Shallow copy

	original.set_value(20);
	std::cout << "Original _value: " << original.get_value() << std::endl;
	std::cout << "Copied _value: " << copy.get_value() << std::endl;

	return 0;
}
