/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 14:19:39 by bkaramol          #+#    #+#             */
/*   Updated: 2023/09/28 09:44:17 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <iostream>
#include "Weapon.hpp"

class HumanA
{
private:
	// humanA'da Weapon'a pointer da tanımlayabilirdin
	// ama bir başka weapon kopyası yaratmamak için referans kullandık
	// ayrıca weapon ilk başta ilklendiriliyor o yüzden referansa daha uygun
	Weapon &weapon;
	std::string name;

public:
	HumanA(std::string name, Weapon &weapon);
	~HumanA();
	void attack();
};

#endif
