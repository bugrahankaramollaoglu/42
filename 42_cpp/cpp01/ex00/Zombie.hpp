/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 04:25:08 by bkaramol          #+#    #+#             */
/*   Updated: 2023/08/20 11:09:03 by bkaramol         ###   ########.fr       */
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
	void announce(void);	  // member function
	Zombie(std::string name); // parametred constructor
	Zombie();				  // default constructor
	~Zombie();				  // deconstructor
};

/* two different ways of creating objects of Zombie class */
Zombie *newZombie(std::string name); // heap
void randomChump(std::string name);	 // stack
/* what is the advantage of each over the other?
allocating on stack makes this automatic. thus it works faster to (de)allocate
it is also safer compared to heap allocation, but - it is limited in size.
stack is generally smaller than heap. objects on stack are local, thus cannot
be shared between scopes and functions.

allocating on heap gives you more possible-storage.
objects on heap can be accessed from multiple locations.
it is slower and riskier.  */

#endif
