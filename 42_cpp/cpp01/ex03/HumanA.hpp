/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 14:19:39 by bkaramol          #+#    #+#             */
/*   Updated: 2023/08/20 23:37:10 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <iostream>
#include "Weapon.hpp"

class HumanA
{
private:
	Weapon &weapon; // reference
	std::string name;

public:
	/* you create an instance of HumanA, you pass a
	reference to a Weapon object as a parameter to
	the constructor. The reference weapon in HumanA
	will now refer to the same Weapon object that
	was passed to the constructor. This allows HumanA
	to use the referenced Weapon object without
	creating a new copy of it. */
	HumanA(std::string name, Weapon &weapon);
	// deconstructor
	~HumanA();
	void attack();
};

#endif
