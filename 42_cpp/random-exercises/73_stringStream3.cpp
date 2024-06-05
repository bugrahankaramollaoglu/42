#include <iostream>
#include <sstream>

int main()
{
	std::stringstream ss;
	ss << "merhaba";
	std::string extractedWord;
	ss >> extractedWord;
	std::cout << extractedWord << std::endl; // merhaba
}
