/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 18:04:33 by bkaramol          #+#    #+#             */
/*   Updated: 2023/09/22 00:50:51 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	std::cout << "fragtrap default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->Name = name;
	this->HitPoint = 100;
	this->EnergyPoint = 100;
	this->AttackDamage = 30;
	std::cout << "fragtrap named constructor called with " << Name << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
	std::cout << "fragtrap copy construtor called" << std::endl;
	*this = other;
}

FragTrap::~FragTrap()
{
	std::cout << "fragtrap default destructor called" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other)
{
	std::cout << "fragtrap copy assignement operator "
			  << " called\n";
	ClapTrap::operator=(other);
	return (*this);
}

void FragTrap::attack(std::string target)
{
	std::cout << "this is fragtrap attacking: " << target << std::endl;
	return;
}

void FragTrap::highFiveGuys(void)
{
	std::cout << "hi 5" << std::endl;
}
