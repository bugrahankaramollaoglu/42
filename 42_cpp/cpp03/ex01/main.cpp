/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 11:46:55 by bkaramol          #+#    #+#             */
/*   Updated: 2023/09/22 00:47:11 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

/* bir derived classi çağırdığında
base classin constructor destructor fonksiyonlari
da çağrılır. bunu engellemenin yolu yoktur, en fazla
override edebilirsin bu çağrıları. */

int main(void)
{
	// ClapTrap ct;
	// ScavTrap st;

	// ClapTrap ct("ahmet");
	// ScavTrap st("mehmet");

	// ct.attack("Dusman");
	// ct.takeDamage(20);
	// st.attack("Dusman");

	// ScavTrap scavTrap("Rick");
	// scavTrap.attack("rickDusman");
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
