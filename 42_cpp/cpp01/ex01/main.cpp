/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 11:57:18 by bkaramol          #+#    #+#             */
/*   Updated: 2023/08/20 12:22:31 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	int i = -1;
	int N;

	N = 3;
	Zombie *z;
	z = zombieHorde(N, "cranberries");
	while (++i < N)
	{
		z[i].announce();
	}
	delete[] z;
}
