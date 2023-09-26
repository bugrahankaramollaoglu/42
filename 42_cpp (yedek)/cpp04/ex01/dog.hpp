/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 21:40:15 by bkaramol          #+#    #+#             */
/*   Updated: 2023/09/02 23:58:15 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "animal.hpp"
#include "brain.hpp"

class Dog : public Animal
{
private:
	Brain *brain;

public:
	Dog();
	Dog(const Dog& other);
	Dog& operator=(const Dog& other);
	virtual ~Dog();

public:
	void makeSound() const;
};
