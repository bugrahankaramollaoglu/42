/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 11:57:48 by bkaramol          #+#    #+#             */
/*   Updated: 2023/09/02 12:20:56 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <iostream>

class Zombie
{
private:
	std::string Name;

public:
	Zombie();
	~Zombie();

public:
	void SetName(std::string str);
	std::string GetName();
	void announce(void);
};

Zombie *zombieHorde(int N, std::string name);

#endif
