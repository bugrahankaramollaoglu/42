/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 20:24:14 by bkaramol          #+#    #+#             */
/*   Updated: 2023/09/15 20:00:56 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <list>

template <typename T>
bool easyfind(T &kontainer, int key)
{
	// burasi genelde std::set<int> mySet::iterator şeklinde kullanılır
	for (typename T::iterator it = kontainer.begin(); it != kontainer.end(); ++it)
	{
		if (*it == key)
		{
			std::cout << "found\n";
			return true;
		}
	}
	std::cout << "not found\n";
	return false;
}

template <typename T>
void printVec(const T &vec)
{
	for (const int &element : vec)
	{
		std::cout << element << " ";
	}
	std::cout << "\n";
}

#endif
