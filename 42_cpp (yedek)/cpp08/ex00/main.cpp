/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 18:59:28 by bkaramol          #+#    #+#             */
/*   Updated: 2023/09/15 20:03:24 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <string>

/* int main()
{
	// c++98'de bu şekil ilklendirme (brace initialization) yasak
	// std::vector<int> myVec = {10, 20, 30, 40, 50, 60};
	int ar[] = {10, 20, 30, 40, 50, 60};
	// @2'de ar'i başından sonuna kadar (öteleyerek
	// buluyoruz sonunu) vec'e kopyaliyoruz
	std::vector<int> myVec(ar, ar + (sizeof(ar) / sizeof(ar[0])));
	printVec(myVec);
	easyfind(myVec, 42); // not found
	easyfind(myVec, 50); // found
} */

/*
int main()
{
	int ar[100000];
	for (int i = 0; i < 100000; i++)
	{
		ar[i] = i;
	}
	std::vector<int> myVec(ar, ar + (sizeof(ar) / sizeof(ar[0])));
	// printVec(ar);
	easyfind(myVec, 88888);
}
 */
