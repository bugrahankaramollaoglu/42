#include <iostream>
#include <stack>

int main()
{

	// initialize
	std::stack<int> myStack;
	std::stack<int> myStack2({10, 20, 30, 40});

	myStack.push(50);
	myStack.push(60);

	// removes the last item
	myStack.pop();

	// returns the last item
	myStack.top();

	myStack.size();

	myStack.empty();

	std::stack<char> charStack;
	std::string msg = "hello";

	for (char c : msg)
		charStack.push(c);

	while (!charStack.empty())
	{
		std::cout << charStack.top();
		charStack.pop();
	} // olleh
	std::cout << "\n";
}
