/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 15:34:57 by bkaramol          #+#    #+#             */
/*   Updated: 2023/09/21 22:45:16 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : fixedPointNumber(0)
{
	std::cout << "Default constructor called" << std::endl;
}

/* integeri fixedPointNumber'a çevirmek için integeri fixedPointte
olmasını istediğin fractionalBit sayısı kadar sola leftShift yap. why?
123.456 şeklindeki bir fixed point'i integer'a çevirmek istiyoruz
yani 123'ü almak istiyoruz. bir sayıya n ile leftShift uygulamak
o sayıyı kendi tabanı^n ile çarpmakla aynı şeydir. mesela
bir binary'yi << 3 yapmak demek o sayıyı 2^3 yani 8 ile çarpmaktır.
mesela (15 << 3) demek (15x8) demektir. bu işlemi bir integera yaptığında
da o sayının fixed karşılığını buluyosun. mesela 17.56 sayısını fixed'a çevirelim:
17.56 << fractionalBits (yani 8)
17.56 * 256 = 4495.36 */
Fixed::Fixed(const int nbr) : fixedPointNumber(nbr << fractionalBits)
{
	std::cout << "Int constructor called" << std::endl;
}

// Converting from a float to a fixed point number,
// (number * (float)(1 << fractionalBits))
Fixed::Fixed(const float nbr)
{
	std::cout << "Float constructor called" << std::endl;
	fixedPointNumber = roundf(nbr * (float)(1 << fractionalBits));
}

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
	std::cout << "Copy assignment operator called" << std::endl;
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
	return ((float)fixedPointNumber / (1 << fractionalBits));
}

std::ostream &operator<<(std::ostream &os, Fixed const &fixed)
{
	os << fixed.toFloat();
	return os;
}
