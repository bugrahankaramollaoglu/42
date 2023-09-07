#include <iostream>

/* You can use const references to prevent modification of the original data: */

// Function having parameters as
// references
void swap(int &first, int &second)
{
	int temp = first;
	first = second;
	second = temp;
}

// Driver function
int main()
{
	// Variables declared
	int a = 2, b = 3;

	// function called
	swap(a, b);

	// changes can be seen
	// printing both variables
	std::cout << a << " " << b << "\n";
}
