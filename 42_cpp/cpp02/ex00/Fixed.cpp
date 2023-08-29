/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 15:48:02 by bkaramol          #+#    #+#             */
/*   Updated: 2023/08/26 16:17:37 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// fixedPointNumber static oldugu icin hemen ilklendirilmesi gerekiyor,
// altta kod blogu icinde ilklendirilemiyor
Fixed::Fixed() : fixedPointNumber(0)
{
	std::cout << "Default constructor called" << std::endl;
}

// copy constructor parametre olarak obje alir
Fixed::Fixed(Fixed const &fixed)
{
	std::cout << "Copy constructor called" << std::endl;
	// parametre olarak gelen fixed objesinin degerini this objesine atiyoruz
	// böylece o anki objeye parametre olarak gelen obje kopyalanmis oluyor
	*this = fixed;
}

// copy assignment operator overloadlarla & kullanılır
Fixed &Fixed::operator=(Fixed const &fixed)
{
	std::cout << "Copy assignment operator called" << std::endl;

	// getRawBits() değeri 0 olan fixedPointNumber döndürür,
	// onu da o anki objenin fixedPointNumber'ına atar, = sayesinde kopyalamış olur
	this->fixedPointNumber = fixed.getRawBits();

	// o anki objeyi return ediyoruz
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->fixedPointNumber);
}

void Fixed::setRawBits(int const raw)
{
	this->fixedPointNumber = raw;
}
