/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 16:36:19 by bkaramol          #+#    #+#             */
/*   Updated: 2023/09/14 19:22:03 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <stdexcept>
#include <cmath>

template <typename T>
class Array
{
private:
	size_t len;
	T *ar;

public:
	Array() : len(0)
	{
		ar = new T[];
	}

	~Array()
	{
		if (ar != NULL)
			delete[] ar;
	}

	Array(unsigned int n)
	{
		ar = new T[n];
		len = n;
	}

	Array(const Array &copy)
	{
		// ar = NULL;
		*this = copy;
	}

	Array &operator=(const Array &copy)
	{
		len = copy.len;
		ar = new T[len];
		for (size_t i = 0; i < len; i++)
		{
			ar[i] = copy.ar[i];
		}
		return *this;
	}

	T &operator[](size_t i)
	{
		if (i >= len)
			throw std::out_of_range("out of bounds");
		else
			return ar[i];
	}

	size_t size()
	{
		return len;
	}
};

#endif
