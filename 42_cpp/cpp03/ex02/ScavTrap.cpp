/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 15:06:00 by bkaramol          #+#    #+#             */
/*   Updated: 2023/08/27 16:20:27 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << "scavtrap default constructor called" << std::endl;
	this->HitPoint = 100;
	this->EnergyPoint = 50;
	this->AttackDamage = 20;
}

ScavTrap::~ScavTrap()
{
	// std::cout << this->Name << " destructor called" << std::endl;
	// burada yazdirmiyoruz ( cünkü yazdirirsak hem derived hem base
	// class destructoru cagiriyor )
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->HitPoint = 100;
	this->EnergyPoint = 50;
	this->AttackDamage = 20;
}

void ScavTrap::guardGate()
{
	std::cout << "scavtrap is now in gatekeeper mode." << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
	if (EnergyPoint > 0)
	{
		std::cout << "ScavTrap " << this->Name << " attacks " << target << ", causing [" << this->AttackDamage << "] points of damage!" << std::endl;
		this->EnergyPoint--;
	}
	else
		std::cout << "you've run out of energy" << std::endl;
}
