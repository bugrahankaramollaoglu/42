/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 21:38:31 by bkaramol          #+#    #+#             */
/*   Updated: 2023/09/22 01:10:30 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "animal.hpp"

Animal::Animal() : type("just animal")
{
	std::cout << "animal constructor called" << std::endl;
}

Animal::~Animal()
{
	std::cout << "animal destructor called" << std::endl;
}

Animal::Animal(const Animal &other)
{
	std::cout << "animal copy constructor called" << std::endl;
	*this = other;
}

Animal &Animal::operator=(const Animal &other)
{
	std::cout << "animal assignment operator called" << std::endl;
	if (this != &other)
		this->type = other.type;
	return (*this);
}

void Animal::makeSound() const
{
	std::cout << "animal sound" << std::endl;
}

std::string Animal::getType() const
{
	return (this->type);
}
