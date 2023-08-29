/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 11:57:45 by bkaramol          #+#    #+#             */
/*   Updated: 2023/08/20 12:05:37 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
{
	std::string Name = "";
}

void Zombie::announce()
{
	std::cout << Name << " : BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::SetName(std::string str)
{
	Name = str;
}

std::string Zombie::GetName()
{
	return (Name);
}

Zombie::~Zombie()
{
	std::cout << Name << " : has been destroyed..." << std::endl;
}
