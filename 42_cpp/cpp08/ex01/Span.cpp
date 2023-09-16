/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 20:07:10 by bkaramol          #+#    #+#             */
/*   Updated: 2023/09/16 10:56:57 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span()
{
}

Span::~Span()
{
}

Span::Span(const Span &obj)
{
	*this = obj;
}

Span &Span::operator=(const Span &obj)
{
	if (this != &obj)
	{
		this->_size = obj._size;
	}
	return (*this);
}

/* --------------------------------- */

Span::Span(unsigned int N)
{
	this->_size = N;
}

void Span::addNumber(int val)
{
	if (myList.size() < _size)
		myList.push_back(val);
	else
		throw std::out_of_range("list is full");
}

void Span::printList()
{
	std::cout << "[ ";
	for (std::list<int>::iterator it = myList.begin(); it != myList.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << "]\n";
}

unsigned int Span::shortestSpan()
{
	if (myList.size() <= 1 || myList.empty())
		throw std::out_of_range("list is adequate");
	else
	{
		// sıralamak için önce vec'e atiyoruz sonra geri liste atiyoruz

		// Copy the elements of the list to a vector
		std::vector<int> myVector(myList.begin(), myList.end());

		// Sort the vector
		std::sort(myVector.begin(), myVector.end());

		// Update the list with the sorted elements
		myList.assign(myVector.begin(), myVector.end());

		std::list<int>::iterator it = myList.begin();
		std::list<int>::iterator it2 = myList.begin();
		unsigned int shortestSpan = UINT_MAX;
		unsigned int fark = 0;
		for (size_t i = 0; i < myList.size() - 1; ++i)
		{
			for (size_t j = i + 1; j < myList.size(); ++j, i++)
			{
				std::advance(it, j);
				std::advance(it2, i);
				fark = *it - *it2;
				if (fark < shortestSpan)
					shortestSpan = fark;
			}
		}
		return shortestSpan;
	}
}

unsigned int Span::longestSpan()
{
	if (myList.size() <= 1 || myList.empty())
		throw std::out_of_range("list is not adequate");
	else
	{
		// Copy the elements of the list to a vector
		std::vector<int> myVector(myList.begin(), myList.end());

		// Sort the vector
		std::sort(myVector.begin(), myVector.end());

		// Update the list with the sorted elements
		myList.assign(myVector.begin(), myVector.end());

		unsigned int longestSpan = abs(myList.front() - myList.back());

		return longestSpan;
	}
}

void Span::addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	while (begin != end)
		addNumber(*begin++);
}
