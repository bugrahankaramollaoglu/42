/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 11:46:51 by bkaramol          #+#    #+#             */
/*   Updated: 2023/08/27 14:48:50 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	std::cout << "default constructor called" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << this->Name << " has been destructed" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
	std::cout << "copy constructor called" << std::endl;
	*this = other;
}

ClapTrap::ClapTrap(std::string Name) : HitPoint(10), EnergyPoint(10), AttackDamage(0)
{
	this->Name = Name;
	std::cout << this->Name << " has been born" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &copy)
{
	std::cout << "Copy Assignment operator Called" << std::endl;
	if (this != &copy)
	{
		this->Name = copy.Name;
		this->HitPoint = copy.HitPoint;
		this->EnergyPoint = copy.EnergyPoint;
		this->AttackDamage = copy.AttackDamage;
	}
	return *this;
}

void ClapTrap::attack(const std::string &target)
{
	if (this->EnergyPoint >= 1)
	{
		std::cout << "ClapTrap " << this->Name << " attacks " << target << " with [" << this->AttackDamage << "] damage power." << std::endl;
		this->EnergyPoint--;
	}
	else
	{
		std::cout << "ClapTrap " << this->Name << " has no energy to attack." << std::endl;
		return;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->HitPoint >= 1)
	{
		std::cout << "ClapTrap " << this->Name << " took damage, losing [" << amount << "] points of health!" << std::endl;
		this->HitPoint -= amount;
	}
	else
	{
		std::cout << "ClapTrap " << this->Name << " is already dead!" << std::endl;
		return;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->EnergyPoint >= 1)
	{
		std::cout << "ClapTrap gets repaired, gaining [" << amount << "] points of health!" << std::endl;
		this->HitPoint += amount;
		this->EnergyPoint--;
	}
	else
	{
		std::cout << "ClapTrap " << this->Name << " has no energy to repair itself" << std::endl;
		return;
	}
}
