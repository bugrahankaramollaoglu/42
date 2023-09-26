/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 13:12:41 by bkaramol          #+#    #+#             */
/*   Updated: 2023/09/21 13:23:44 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie
{
private:
	std::string name;

public:
	Zombie();
	Zombie(std::string name);
	~Zombie();

public:
	void announce(void);
};

/* two different ways of creating functions  */
Zombie *newZombie(std::string name); // heap
void randomChump(std::string name);	 // stack
/* what is the advantage of each over the other?
allocating on stack makes this automatic. thus it works faster to (de)allocate
it is also safer compared to heap allocation, but - it is limited in size (2gb).
stack is generally smaller than heap. objects on stack are local, thus cannot
be shared between scopes and functions.

allocating on heap gives you more possible-storage.
objects on heap can be accessed from multiple locations.
it is slower and riskier.

and also, why did we define those functions outside class?
	* By defining these functions as standalone functions,
	you can use them without having to create an
	instance of the Zombie class.
	* they have nothing really to do with class member and attributes */

#endif
