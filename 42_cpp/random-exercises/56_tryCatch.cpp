#include <iostream>
#include <stdexcept>

/* şeması şöyledir:

TRY + CATCH:

try: You enclose the code that might raise an exception
within a try block. This is where you write the code
that you want to monitor for exceptions.

catch: After the try block, you can have one or more catch
blocks to handle specific types of exceptions that might
occur. Each catch block is associated with a particular
exception type, and it will be executed if an exception
of that type is thrown within the try block.

try {
	// Code that might raise an exception
}

catch (ExceptionType1 &e) {
	// Handle ExceptionType1
}

catch (ExceptionType2 &e) {
	// Handle ExceptionType2
}

*/

int main()
{
	try
	{
		int numerator = 10;
		int denominator = 0;
		if (denominator == 0) {
			throw std::runtime_error("Division by zero is not allowed.");
		}
		int result = numerator / denominator;
		std::cout << "Result: " << result << std::endl;
	}
	catch (std::runtime_error &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
}
