/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 22:13:31 by bkaramol          #+#    #+#             */
/*   Updated: 2023/09/02 22:24:59 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "wrong animal constructor called" << std::endl;
	this->type = "just wrong animal";
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "wrong animal destructor called" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const& other)
{
	std::cout << "wrong animal copy constructor called" << std::endl;
	*this = other;
}

WrongAnimal& WrongAnimal::operator=(WrongAnimal const& other)
{
	std::cout << "wrong animal assignment operator called" << std::endl;
	if (this != &other)
	{
		this->type = other.type;
	}
	return (*this);
}

void WrongAnimal::makeSound() const
{
	std::cout << "wrong animal sound" << std::endl;
}
