/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 11:46:55 by bkaramol          #+#    #+#             */
/*   Updated: 2023/09/02 17:50:09 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
	ClapTrap ct("ahmet");
	ScavTrap st("mehmet");

	std::cout << "\n";
	// ct.attack("Dusman");
	// st.attack("Dusman");
	std::cout << "\n";

	// ScavTrap scavTrap("Rick");

	// scavTrap.attack("ahmetDusman");
	// scavTrap.takeDamage(30);
	// scavTrap.beRepaired(30);

	// ScavTrap otherScavTrap("Negan");

	// ScavTrap test(otherScavTrap);

	// scavTrap.attack("zombie");
	// otherScavTrap.takeDamage(2);
	// test.beRepaired(10);

	// scavTrap = otherScavTrap;
	// scavTrap.attack("zombie");
	// otherScavTrap.guardGate();
}
