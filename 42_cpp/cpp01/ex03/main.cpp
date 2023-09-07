/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 13:45:50 by bkaramol          #+#    #+#             */
/*   Updated: 2023/09/02 12:32:22 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
	// farklı scopelarda olsun diye {} içlerinde ayırıyoruz
	{
		Weapon club = Weapon("crude spiked club");

		HumanA bob("Bob", club);
		bob.attack(); // Bob attacks with their crude spiked club
		club.setType("some other type of club");
		bob.attack(); // Bob attacks with their crude spiked club
	}
	{
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack(); // Jim attacks with their crude spiked club
		club.setType("some other type of club");
		jim.attack(); // Jim attacks with their some other type of club
	}
}
