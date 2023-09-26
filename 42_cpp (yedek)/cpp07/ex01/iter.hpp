/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 13:37:54 by bkaramol          #+#    #+#             */
/*   Updated: 2023/09/14 16:03:54 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T>
void iter(T *myAr, int len, void (*f)(T &))
{
	for (int i = 0; i < len; i++)
	{
		f(myAr[i]);
	}
}

class Awesome
{
public:
	Awesome() : _n(42)
	{
		return;
	}
	int get(void) const
	{
		return this->_n;
	}

private:
	int _n;
};

std::ostream &operator<<(std::ostream &o, Awesome const &rhs)
{
	o << rhs.get();
	return o;
}

template <typename T>
void print(T &i)
{
	std::cout << i << std::endl;
}

#endif
