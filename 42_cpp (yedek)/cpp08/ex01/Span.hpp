/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 20:07:21 by bkaramol          #+#    #+#             */
/*   Updated: 2023/09/16 10:53:14 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _Span_HPP_
#define _Span_HPP_

#include <iostream>
#include <list>
#include <climits>
#include <set>
#include <vector>
#include <algorithm>

class Span
{
private:
	unsigned int _size;
	std::list<int> myList;

public:
	Span();
	Span(Span const &obj);
	~Span();
	Span &operator=(const Span &obj);

public:
	Span(unsigned int N);
	void addNumber(int val);
	void addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end);
	unsigned int shortestSpan();
	unsigned int longestSpan();

public:
	void printList();
};

#endif
