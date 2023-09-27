#include <iostream>
#include <fstream>

int main()
{
	std::ifstream myf;
	myf.open("file1");

	if (!myf)
	{
		std::cerr << "Error opening file!" << std::endl;
		return 1;
	}

	std::string line;
	while (!myf.eof())
	{
		std::getline(myf, line);
		std::cout << line << std::endl;
	}
	myf.close();
}
