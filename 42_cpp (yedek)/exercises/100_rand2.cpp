#include <iostream>
#include <random>

int main()
{
	// Seed the random number generator
	std::random_device rd;

	// Define the range for the random integers
	int minRange = -100000;
	int maxRange = 100000;

	// Create a uniform distribution and generate a random integer
	std::uniform_int_distribution<int> distribution(minRange, maxRange);

	// Generate a random integer
	int randomInteger = distribution(rd);

	std::cout << "Random integer: " << randomInteger << std::endl;

	return 0;
}
