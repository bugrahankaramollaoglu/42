#include <iostream>
#include <vector>

template <typename T>
class Stack
{
public:
	// Constructor to initialize an empty stack
	Stack() {}

	// Push an element onto the stack
	void Push(const T &element)
	{
		stack.push_back(element);
	}

	// Pop and return the top element from the stack
	T Pop()
	{
		if (IsEmpty())
		{
			throw std::out_of_range("Stack is empty");
		}
		T topElement = stack.back();
		stack.pop_back();
		return topElement;
	}

	// Check if the stack is empty
	bool IsEmpty() const
	{
		return stack.empty();
	}

private:
	std::vector<T> stack;
};

int main()
{
	// Create a stack of integers
	Stack<int> intStack;

	// Push elements onto the stack
	intStack.Push(10);
	intStack.Push(20);
	intStack.Push(30);

	// Pop and print elements from the stack
	while (!intStack.IsEmpty())
	{
		std::cout << "Popped: " << intStack.Pop() << std::endl;
	}

	// Create a stack of strings
	Stack<std::string> stringStack;

	// Push elements onto the stack
	stringStack.Push("Hello");
	stringStack.Push("World");

	// Pop and print elements from the stack
	while (!stringStack.IsEmpty())
	{
		std::cout << "Popped: " << stringStack.Pop() << std::endl;
	}

	return 0;
}
