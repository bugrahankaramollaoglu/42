/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 11:37:20 by bkaramol          #+#    #+#             */
/*   Updated: 2023/08/27 11:37:55 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	_num = 0;
}

Fixed::~Fixed()
{
}

Fixed::Fixed(const Fixed &copy)
{
	*this = copy;
}

Fixed::Fixed(const int intVal)
{
	_num = intVal * pow(2, fractionalBits);
}

Fixed::Fixed(const float floatVal)
{
	_num = roundf(floatVal * pow(2, fractionalBits));
}

Fixed &Fixed::operator=(const Fixed &number)
{
	this->_num = number._num;
	return (*this);
}

int Fixed::toInt() const
{
	return (_num / pow(2, fractionalBits));
}

float Fixed::toFloat() const
{
	return (float(_num) / pow(2, fractionalBits));
}

std::ostream &operator<<(std::ostream &output, const Fixed &fixed)
{
	output << fixed.toFloat();
	return (output);
}

int Fixed::getRawBits(void) const
{
	return _num;
}

void Fixed::setRawBits(int const raw)
{
	_num = raw;
}

bool Fixed::operator>(const Fixed &number)
{
	return (this->_num > number._num);
}

bool Fixed::operator<(const Fixed &number)
{
	return (this->_num < number._num);
}

bool Fixed::operator>=(const Fixed &number)
{
	return (this->_num >= number._num);
}

bool Fixed::operator<=(const Fixed &number)
{
	return (this->_num <= number._num);
}

bool Fixed::operator==(const Fixed &number)
{
	return (this->_num == number._num);
}

bool Fixed::operator!=(const Fixed &number)
{
	return (this->_num != number._num);
}

Fixed Fixed::operator+(const Fixed &number)
{
	Fixed rtn(this->toFloat() + number.toFloat());
	return (rtn);
}

Fixed Fixed::operator-(const Fixed &number)
{
	Fixed rtn(this->toFloat() - number.toFloat());
	return (rtn);
}

Fixed Fixed::operator*(const Fixed &number)
{
	Fixed rtn(this->toFloat() * number.toFloat());
	return (rtn);
}

Fixed Fixed::operator/(const Fixed &number)
{
	Fixed rtn(this->toFloat() / number.toFloat());
	return (rtn);
}

Fixed Fixed::operator++(int)
{
	Fixed result = *this;
	this->_num++;
	return (result);
}

Fixed &Fixed::operator++()
{
	this->_num++;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed result = *this;
	this->_num--;
	return (result);
}

Fixed &Fixed::operator--()
{
	this->_num--;
	return (*this);
}

Fixed &Fixed::min(Fixed &f1, Fixed &f2)
{
	if (f1 < f2)
		return (f1);
	return (f2);
}

const Fixed &Fixed::min(const Fixed &f1, const Fixed &f2)
{
	if (f1._num < f2._num)
		return (f1);
	return (f2);
}

Fixed &Fixed::max(Fixed &f1, Fixed &f2)
{
	if (f1 > f2)
		return (f1);
	return (f2);
}

const Fixed &Fixed::max(const Fixed &f1, const Fixed &f2)
{
	if (f1._num > f2._num)
		return (f1);
	return (f2);
}
