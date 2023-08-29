/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 13:36:27 by bkaramol          #+#    #+#             */
/*   Updated: 2023/08/29 22:05:01 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "animal.hpp"
#include "brain.hpp"

class Cat : public Animal
{
private:
	Brain *brain;

public:
	Cat();
	virtual ~Cat();
	Cat(const Cat &copy);
	Cat &operator=(const Cat &copy);
	void makeSound(void) const;
};

#endif
