/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 14:19:50 by bkaramol          #+#    #+#             */
/*   Updated: 2023/09/02 12:35:38 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <iostream>
#include "Weapon.hpp"

class HumanB
{
private:
	// humanB'de ise pointer tanımlamak zorundayız
	// çünkü weapon objesi humanB'nin constructor'ında
	// ilklendirilmiyor yani ilk başta NULL olmak zorunda.
	Weapon *weapon;
	std::string name;

public:
	HumanB(std::string name);
	~HumanB();

public:
	void attack();
	void setWeapon(Weapon &weapon);
};

#endif
