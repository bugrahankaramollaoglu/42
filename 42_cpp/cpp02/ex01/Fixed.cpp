/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 16:32:25 by bkaramol          #+#    #+#             */
/*   Updated: 2023/08/27 20:06:29 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// a ilk buna giriyor ve 0 oluyor
Fixed::Fixed() : fixedPointNumber()
{
	std::cout << "Default constructor called" << std::endl;
}

// b buna giriyor
Fixed::Fixed(int nbr) : fixedPointNumber(nbr << fractionalBits)
{
	std::cout << "Int constructor called" << std::endl;
}

// c buna giriyor
Fixed::Fixed(float nbr)
{
	std::cout << "Float constructor called" << std::endl;
	// roundf() bir floati en yakin integer'a yuvarlar
	fixedPointNumber = roundf(nbr * (1 << fractionalBits));
}

// d buna giriyor
Fixed::Fixed(Fixed const &fixed)
{
	std::cout << "Copy constructor called" << std::endl;
	this->fixedPointNumber = fixed.getRawBits();
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(Fixed const &fixed)
{
	this->fixedPointNumber = fixed.getRawBits();
	return (*this);
}

int Fixed::getRawBits() const
{
	return (this->fixedPointNumber);
}

int Fixed::toInt() const
{
	return (fixedPointNumber >> fractionalBits);
}

float Fixed::toFloat() const
{
	return ((float)fixedPointNumber / 256);
}

std::ostream &operator<<(std::ostream &os, Fixed const &fixed)
{
	// önce fixed.toFloat() ile 2. parametreyi float'a çeviriyoruz
	// sonra os'a float'ı << operatörü yardimiyla yazıyoruz
	os << fixed.toFloat();
	// chain yapabilmek için os'u return ediyoruz
	return os;
}
