#include <iostream>
#include <fstream>

int main()
{
	std::ifstream inputFile;
	inputFile.open("numbers.txt");

	if (!inputFile)
	{
		std::cerr << "Error opening file!" << std::endl;
		return 1;
	}

	int number;
	while (inputFile >> number)
	{
		std::cout << "Read number: " << number << std::endl;
	}

	inputFile.close();
	return 0;
}
