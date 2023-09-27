#include <iostream>
#include <fstream>
#include <string>

int main(int ac, char **av)
{
	std::ifstream inputFile(av[1]);
	if (!inputFile.is_open() || ac != 2)
	{
		std::cout << "could not open file\n";
		return 1;
	}
	else
	{
		std::string line;
		while (std::getline(inputFile, line))
			std::cout << line << std::endl;
	}
}
