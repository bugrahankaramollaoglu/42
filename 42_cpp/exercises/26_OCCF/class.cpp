/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   class.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 14:39:20 by bkaramol          #+#    #+#             */
/*   Updated: 2023/08/27 19:36:50 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "class.hpp"

Deneme::Deneme()
{
	std::cout << "Default constructor called" << std::endl;
}

Deneme::~Deneme()
{
	std::cout << "Destructor called" << std::endl;
}

Deneme::Deneme(const Deneme &other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Deneme &Deneme::operator=(const Deneme &other)
{
	std::cout << "Assignation operator called" << std::endl;
	if (this != &other)
	{
		// do stuff
	}
	return (*this);
}
