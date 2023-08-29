
#include <iostream>
#include <fstream>

int main()
{
	std::ifstream myf;
	myf.open("file1");
	std::string line;
	std::getline(myf, line);
	std::cout << line << std::endl; // bugra
	std::getline(myf, line);
	std::cout << line << std::endl; // kara
}
