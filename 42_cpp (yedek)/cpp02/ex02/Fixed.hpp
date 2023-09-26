/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 13:52:19 by bkaramol          #+#    #+#             */
/*   Updated: 2023/09/21 23:38:26 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>
#include <cmath>

class Fixed
{

private:
	int nbr;
	static const int fractionalBits = 8;

public:
	Fixed();
	Fixed(const Fixed &fixed);
	Fixed &operator=(const Fixed &fixed);
	~Fixed();

public:
	Fixed(const int i);
	Fixed(const float f);

	int getRawBits(void) const;
	void setRawBits(int const raw);

	float toFloat(void) const;
	int toInt(void) const;

public:
	bool operator>(const Fixed &fixed) const;
	bool operator<(const Fixed &fixed) const;
	bool operator>=(const Fixed &fixed) const;
	bool operator<=(const Fixed &fixed) const;
	bool operator==(const Fixed &fixed) const;
	bool operator!=(const Fixed &fixed) const;

	Fixed operator+(const Fixed &fixed) const;
	Fixed operator-(const Fixed &fixed) const;
	Fixed operator*(const Fixed &fixed) const;
	Fixed operator/(const Fixed &fixed) const;

	Fixed operator++(int);
	Fixed &operator++(void);

	Fixed operator--(int);
	Fixed &operator--(void);

public:
	// min and max
	// they are static bc they do not need to access the attributes
	// of Fixed class, they just return the greatest/smallest number
	static Fixed &min(Fixed &fixed1, Fixed &fixed2);
	const static Fixed &min(const Fixed &fixed1, const Fixed &fixed2);

	static Fixed &max(Fixed &fixed1, Fixed &fixed2);
	const static Fixed &max(const Fixed &fixed1, const Fixed &fixed2);
};

std::ostream &operator<<(std::ostream &o, const Fixed &fixed);

#endif
