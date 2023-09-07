/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 15:35:03 by bkaramol          #+#    #+#             */
/*   Updated: 2023/09/04 13:37:38 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
private:
	int fixedPointNumber;
	static const int fractionalBits = 8;

public:
	Fixed();

	Fixed(const int nbr);
	Fixed(const float nbr);

	// fixedPoint to floatinPoint
	float toFloat(void) const;
	// fixedPoint to integer
	int toInt(void) const;

	int getRawBits(void) const;

	Fixed(Fixed const &fixed);

	Fixed &operator=(Fixed const &fixed);

	~Fixed();
};

std::ostream &operator<<(std::ostream &os, Fixed const &fixed);

#endif
