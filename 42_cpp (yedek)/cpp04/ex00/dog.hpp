/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 21:40:15 by bkaramol          #+#    #+#             */
/*   Updated: 2023/09/22 14:15:53 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "animal.hpp"

class Dog : public Animal
{
public:
	Dog();
	Dog(const Dog &other);
	Dog &operator=(const Dog &other);
	virtual ~Dog();

public:
	void makeSound() const;
};
