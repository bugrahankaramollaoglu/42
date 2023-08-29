/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 11:46:55 by bkaramol          #+#    #+#             */
/*   Updated: 2023/08/27 15:03:51 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	ClapTrap ct("ahmet");
	ClapTrap ct2("ahmetDusman");

	ct.attack(ct2.getName());
	ct2.takeDamage(5);

	ct.attack(ct2.getName());
	ct2.takeDamage(5);

	ClapTrap ct3(ct2); // copy constructor called

	ct.attack(ct2.getName());
	ct2.takeDamage(5);

	ct2.beRepaired(5);

	ct.attack(ct2.getName());
	ct2.takeDamage(5);

	ct.attack(ct2.getName());
	ct2.takeDamage(5);

	return (0);
}
