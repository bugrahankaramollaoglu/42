/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 13:58:00 by bkaramol          #+#    #+#             */
/*   Updated: 2023/09/02 11:38:41 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>

class Weapon
{
private:
	std::string type;

public:
	Weapon(std::string type);
	Weapon();
	~Weapon();

public:
	// 1. const: func will not modify data members of the class
	// 2. const: func will not modify the object it is called on
	const std::string &getType() const;
	void setType(std::string type);
};

#endif
