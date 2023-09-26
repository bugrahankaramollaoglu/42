/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 11:46:51 by bkaramol          #+#    #+#             */
/*   Updated: 2023/09/26 10:23:50 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : Name(""), HitPoint(10), EnergyPoint(10), AttackDamage(0)
{
	std::cout << "claptrap default constructor called" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "claptrap default destructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
	std::cout << "copy constructor called" << std::endl;
	*this = other;
}

ClapTrap::ClapTrap(std::string Name) : Name(Name), HitPoint(10), EnergyPoint(10), AttackDamage(0)
{
	std::cout << "claptrap named constructor called with: " << Name << std::endl;
	this->Name = Name;
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
		std::cout << "ClapTrap " << this->Name << " attacks " << target << " with " << this->AttackDamage << " points of damage !" << std::endl;
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
		std::cout << this->Name << " took damage, losing " << amount << " points of health!" << std::endl;
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
		std::cout << this->Name << " gets repaired, gaining " << amount << " points of health!" << std::endl;
		this->HitPoint += amount;
		this->EnergyPoint--;
	}
	else
	{
		std::cout << "ClapTrap " << this->Name << " has no energy to repair itself" << std::endl;
		return;
	}
}

std::string ClapTrap::getName() const
{
	return this->Name;
}

int ClapTrap::getHit() const
{
	return this->HitPoint;
}

int ClapTrap::getEnergy() const
{
	return this->EnergyPoint;
}

int ClapTrap::getDamage() const
{
	return this->AttackDamage;
}
