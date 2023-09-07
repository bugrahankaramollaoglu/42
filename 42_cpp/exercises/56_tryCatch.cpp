#include <iostream>
#include <stdexcept>

int main()
{
	try
	{
		int numerator = 10;
		int denominator = 0;
		if (denominator == 0)
		{
			throw std::runtime_error("Division by zero is not allowed.");
		}
		int result = numerator / denominator;
		std::cout << "Result: " << result << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
}
