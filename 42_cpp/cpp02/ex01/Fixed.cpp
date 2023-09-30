/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 15:34:57 by bkaramol          #+#    #+#             */
/*   Updated: 2023/09/28 09:49:00 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : fixedPointNumber(0)
{
	std::cout << "Default constructor called" << std::endl;
}

/* integeri fixedPointNumber'a çevirmek için integeri fixedPointte
olmasını istediğin fractionalBit sayısı kadar sola leftShift yapiyoruz. yani çarpıyoruz.
mesela Fixed(36) verilmiş olsun. yani 36 integerini 8bitli fixed-point-number'a çeviricez.
1) 36 bit karsılıgı: 00100100
2) 00100100 << 8 (sağdan 8 sıfır eklemek demek)
3) 0010010000000000
4) 00100100.00000000 (8 bit oldugundan son 8 bitten öncesi int sonrası fractional)
5) bu da eşittir 36.0
böylelikle 36 intini 36.0 fpn'ına çevirmiş olduk. yani kısaca özeti
bir integerin fractional kısmı olmadıgı icin (0 oldugu icin) bit sayımız kadar
0 koyuyoruz ve çevrilmiş oluyor. */
Fixed::Fixed(const int nbr)
{
	std::cout << "Int constructor called" << std::endl;
	fixedPointNumber = nbr << fractionalBits;
}

/* float bir sayıyı fpn'a çevirmek için de bit sayısı ile çarpıyoruz,
fixed'den geri floata çevirirken ise 256ya geri bölecegiz */
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
	// 256ya bölmekle aynı şey
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
