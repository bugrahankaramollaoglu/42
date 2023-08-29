/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 11:46:55 by bkaramol          #+#    #+#             */
/*   Updated: 2023/08/27 16:30:28 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	ScavTrap st("ahmet");
	ScavTrap st2("ahmetDusman");

	for (int i = 0; i < 10; i++)
	{
		st.attack(st2.getName());
		st2.takeDamage(10);
	}

	st2.beRepaired(30);

	st2.guardGate();
}
