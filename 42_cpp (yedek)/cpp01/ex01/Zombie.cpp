/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 11:57:45 by bkaramol          #+#    #+#             */
/*   Updated: 2023/09/21 14:21:55 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
{
}

void Zombie::announce()
{
	std::cout << Name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::SetName(std::string str)
{
	this->Name = str;
}

std::string Zombie::GetName()
{
	return (Name);
}

Zombie::~Zombie()
{
	std::cout << Name << ": has been destroyed..." << std::endl;
}
