#include <iostream>

// Function having parameters as references
void swap(int &first, int &second)
{
	int temp = first;
	first = second;
	second = temp;
}

// Driver function
int main()
{
	int a = 2, b = 3;

	swap(a, b);

	std::cout << a << " " << b << "\n";
} 
