/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 11:57:18 by bkaramol          #+#    #+#             */
/*   Updated: 2023/09/01 21:39:28 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	int i = 0;
	int num = 10;
	Zombie *horde;
	horde = zombieHorde(num, "cranberries");
	while (i < num)
	{
		horde[i].announce();
		i++;
	}
	delete[] horde;
}

// ./zombies | grep "Brai" | wc -l
// ./zombies | grep "destr" | wc -l

// valgrind ./zombies
