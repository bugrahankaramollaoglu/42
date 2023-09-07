/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 14:14:37 by bkaramol          #+#    #+#             */
/*   Updated: 2023/09/04 18:07:40 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : nbr(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int i) : nbr(i << fractionalBits)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float f) : nbr(roundf(f * (1 << fractionalBits)))
{
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fixed)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}

Fixed &Fixed::operator=(const Fixed &fixed)
{
	std::cout << "Assignation operator called" << std::endl;
	if (this != &fixed)
		this->nbr = fixed.getRawBits();
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Default destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
	return this->nbr;
}

float Fixed::toFloat(void) const
{
	return ((float)getRawBits() / (1 << fractionalBits));
}

int Fixed::toInt(void) const
{
	return (getRawBits() >> fractionalBits);
}

void Fixed::setRawBits(int const raw)
{
	this->nbr = raw;
}

bool Fixed::operator>(const Fixed &fixed) const
{
	return (this->nbr > fixed.getRawBits());
}

bool Fixed::operator<(const Fixed &fixed) const
{
	return (this->nbr < fixed.getRawBits());
}

bool Fixed::operator>=(const Fixed &fixed) const
{
	return (this->nbr >= fixed.getRawBits());
}

bool Fixed::operator<=(const Fixed &fixed) const
{
	return (this->nbr <= fixed.getRawBits());
}

bool Fixed::operator==(const Fixed &fixed) const
{
	return (this->nbr == fixed.getRawBits());
}

bool Fixed::operator!=(const Fixed &fixed) const
{
	return (this->nbr != fixed.getRawBits());
}

Fixed Fixed::operator+(const Fixed &fixed) const
{
	return (Fixed(this->toFloat() + fixed.toFloat()));
}

Fixed Fixed::operator-(const Fixed &fixed) const
{
	return (Fixed(this->toFloat() - fixed.toFloat()));
}

Fixed Fixed::operator*(const Fixed &fixed) const
{
	return (Fixed(this->toFloat() * fixed.toFloat()));
}

Fixed Fixed::operator/(const Fixed &fixed) const
{
	return (Fixed(this->toFloat() / fixed.toFloat()));
}

// ++fixed (pre)
Fixed &Fixed::operator++()
{
	// direkt o anki örneği arttırıp gönderiyoruz
	this->nbr++;
	return *this;
}

// fixed++ (post)
// takes a dummy int parameter (often unused)
Fixed Fixed::operator++(int)
{
	// burda ise arttırma işlemi yapiyor ama
	// işlem yapılmamış objeyi döndürüyor (o an için)
	// daha sonra ++ işlemi devreye girecek
	Fixed returnvalue = *this;
	this->nbr++;
	return (returnvalue);
}

Fixed &Fixed::operator--()
{
	this->nbr--;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed returnvalue = *this;
	this->nbr--;
	return (returnvalue);
}

Fixed &Fixed::min(Fixed &fixed1, Fixed &fixed2)
{
	return (fixed1 < fixed2 ? fixed1 : fixed2);
}

const Fixed &Fixed::min(const Fixed &fixed1, const Fixed &fixed2)
{
	return (fixed1 < fixed2 ? fixed1 : fixed2);
}

Fixed &Fixed::max(Fixed &fixed1, Fixed &fixed2)
{
	return (fixed1 > fixed2 ? fixed1 : fixed2);
}

const Fixed &Fixed::max(const Fixed &fixed1, const Fixed &fixed2)
{
	return (fixed1 > fixed2 ? fixed1 : fixed2);
}

std::ostream &operator<<(std::ostream &o, const Fixed &fixed)
{
	o << fixed.toFloat();
	return o;
}
