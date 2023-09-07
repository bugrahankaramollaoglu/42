/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 13:45:45 by bkaramol          #+#    #+#             */
/*   Updated: 2023/09/02 11:33:12 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

// referanslar direkt ilklendirilmek zorunda oldukları icin
// member list initialization şart, ama name için normalde değil
HumanA::HumanA(std::string name, Weapon &weapon) : weapon(weapon), name(name)
{
	std::cout << "[human_a constructor called]" << std::endl;
	return;
}

HumanA::~HumanA()
{
	std::cout << "[human_a destructor called]" << std::endl;
	return;
}

void HumanA::attack()
{
	std::cout << this->name << " attacks with their " << this->weapon.getType() << "\n";
}
