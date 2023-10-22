#include <iostream>
using namespace std;

class Deneme
{
public:
	int *val;

	Deneme(int s)
	{
		val = new int;
		*val = s;
	}

	Deneme(const Deneme &other)
	{
		val = new int;
		(*val) = *other.val;
	}

	~Deneme()
	{
		delete val;
	}
};

int main()
{
	Deneme original(5);

	Deneme original2(original);

	cout << *original.val << endl;
	cout << *original2.val << endl;

	return 0;
}
