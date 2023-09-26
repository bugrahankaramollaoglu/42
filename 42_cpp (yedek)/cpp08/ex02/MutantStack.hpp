#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <list>

template <typename T>

class MutantStack : public std::stack<T, std::deque<T>>
{
public:
	MutantStack();
	MutantStack(MutantStack &lhs);
	MutantStack &operator=(const MutantStack &lhs);
	~MutantStack();

public:
	typedef typename std::deque<T>::iterator iterator;
	iterator begin();
	iterator end();

private:
};

#include "MutantStack.tpp"
#endif
