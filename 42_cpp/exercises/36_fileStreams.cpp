#include <iostream>
#include <fstream>
#include <string>

// file streams use 3 types of objects generally: ifstream, ofstream, fstream

// ifstream: input file stream

int main()
{
	std::ifstream inpFile("deneme.txt");
	std::string linee;
	while (std::getline(inpFile, linee))
	{
		std::cout << linee << std::endl;
	}
	inpFile.close();
}

// ofstream: output file stream

int main()
{
	std::ofstream outFile("deneme.txt");
	outFile << "hello world" << std::endl;
	outFile << "these will be written to deneme.txt" << std::endl;
	outFile.close();
}

// fstream: file stream (both input and output)

int main()
{
	std::fstream fileStream("deneme.txt", std::ios::in | std::ios::out);
	// write
	fileStream << "hello world" << std::endl;
	// read
	std::string line;
	while (std::getline(fileStream, line))
	{
		std::cout << line << std::endl;
	}
	fileStream.close();
}
