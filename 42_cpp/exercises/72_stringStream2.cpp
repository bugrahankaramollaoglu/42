#include <iostream>
#include <sstream>

int main()
{
	std::stringstream ss; // we created a stringStream object

	ss << "selamlar";
	std::cout << ss.str() << std::endl; // selamlar
	ss.str("herkese");
	std::cout << ss.str() << std::endl; // selamlar herkese
}
