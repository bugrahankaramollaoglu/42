/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 11:57:18 by bkaramol          #+#    #+#             */
/*   Updated: 2023/09/25 10:03:33 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	Zombie *horde;
	horde = zombieHorde(10, "cranberries");
	for (int i = 0; i < 10; i++)
	{
		horde[i].announce();
	}
	delete[] horde;
}

// ./zombies | grep "Brai" | wc -l
// ./zombies | grep "destr" | wc -l
