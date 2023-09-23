/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 22:14:41 by bkaramol          #+#    #+#             */
/*   Updated: 2023/09/22 01:12:33 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wrongCat.hpp"
#include "wrongAnimal.hpp"

WrongCat::WrongCat()
{
	std::cout << "wrongcat constructor called" << std::endl;
	this->type = "just wrong cat";
}

WrongCat::~WrongCat()
{
	std::cout << "wrongcat destructor called" << std::endl;
}

WrongCat::WrongCat(WrongCat const &other) : WrongAnimal(other)
{
	std::cout << "wrongcat copy constructor called" << std::endl;
	*this = other;
}

WrongCat &WrongCat::operator=(WrongCat const &other)
{
	std::cout << "wrongcat copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->type = other.type;
	}
	return (*this);
}

void WrongCat::makeSound() const
{
	std::cout << "wrongcat's miyav miyav" << std::endl;
}
