/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 21:39:46 by bkaramol          #+#    #+#             */
/*   Updated: 2023/09/03 00:34:59 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cat.hpp"

Cat::Cat()
{
	std::cout << "cat constructor called" << std::endl;
	this->type = "Cat";
	this->brain = new Brain();
}

Cat::~Cat()
{
	std::cout << "cat destructor called" << std::endl;
	delete this->brain;
}

Cat::Cat(const Cat &other) : Animal(other)
{
	*this = other;
	std::cout << "Cat Copy Constructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &other)
{
	this->type = other.type;
	this->brain = new Brain();
	*(this->brain) = *(other.brain);
	std::cout << "Cat Assigment Operator called" << std::endl;
	return *this;
}

void Cat::makeSound() const
{
	std::cout << "miyav" << std::endl;
}
