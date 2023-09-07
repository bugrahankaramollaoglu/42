/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 13:52:19 by bkaramol          #+#    #+#             */
/*   Updated: 2023/09/04 15:56:08 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>
#include <cmath>

class Fixed
{
public:
	// kanon
	Fixed();
	Fixed(const Fixed &fixed);
	Fixed &operator=(const Fixed &fixed);
	~Fixed();

	// parametred constructors
	Fixed(const int i);
	Fixed(const float f);

	// accessor functions
	int getRawBits(void) const;
	float toFloat(void) const;
	int toInt(void) const;
	void setRawBits(int const raw);

	// comparison operators
	bool operator>(const Fixed &fixed) const;
	bool operator<(const Fixed &fixed) const;
	bool operator>=(const Fixed &fixed) const;
	bool operator<=(const Fixed &fixed) const;
	bool operator==(const Fixed &fixed) const;
	bool operator!=(const Fixed &fixed) const;

	// arithmetic operators
	Fixed operator+(const Fixed &fixed) const;
	Fixed operator-(const Fixed &fixed) const;
	Fixed operator*(const Fixed &fixed) const;
	Fixed operator/(const Fixed &fixed) const;

	// ++ and --
	Fixed &operator++(void);
	Fixed &operator--(void);
	Fixed operator++(int);
	Fixed operator--(int);

	// min and max
	// they are static bc they do not need to access the attributes
	// of Fixed class, they just return the greatest/smallest number
	static Fixed &min(Fixed &fixed1, Fixed &fixed2);
	const static Fixed &min(const Fixed &fixed1, const Fixed &fixed2);
	static Fixed &max(Fixed &fixed1, Fixed &fixed2);
	const static Fixed &max(const Fixed &fixed1, const Fixed &fixed2);

private:
	int nbr;
	static const int fractionalBits = 8;
};

std::ostream &operator<<(std::ostream &o, const Fixed &fixed);

#endif
