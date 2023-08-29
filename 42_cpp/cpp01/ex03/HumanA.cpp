/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 13:45:45 by bkaramol          #+#    #+#             */
/*   Updated: 2023/08/20 23:40:02 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

// referanslar direkt ilklendirilmek zorunda oldukları icin
// member list initialization şart, ama name için normalde değil
HumanA::HumanA(std::string name, Weapon &weapon): weapon(weapon), name(name)
{
}

HumanA::~HumanA()
{
}

void HumanA::attack() {
    std::cout << this->name << " attacks with their " << this->weapon.getType() << "\n";
}
