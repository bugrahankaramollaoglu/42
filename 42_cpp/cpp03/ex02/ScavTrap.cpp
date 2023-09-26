/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 17:01:40 by bkaramol          #+#    #+#             */
/*   Updated: 2023/09/26 10:15:26 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << "scavtrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string Name) : ClapTrap(Name)
{
	this->HitPoint = 100;
	this->EnergyPoint = 50;
	this->AttackDamage = 20;
	std::cout << "scavtrap named constructor called with: " << Name << std::endl;
}

void ScavTrap::attack(std::string const &target)
{
	if (this->EnergyPoint <= 0)
	{
		std::cout << "ScavTrap " << this->Name << " is out of energy." << std::endl;
		return;
	}
	std::cout << "ScavTrap " << this->Name << " attacks " << target << " with " << this->AttackDamage << " points of damage !" << std::endl;
	this->EnergyPoint--;
}

void ScavTrap::guardGate(void)
{
	std::cout << "scavtrap is now in gatekeeper mode." << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "scavtrap default destructor called with: " << Name << std::endl;
}
