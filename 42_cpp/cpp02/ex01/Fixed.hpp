/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 16:32:29 by bkaramol          #+#    #+#             */
/*   Updated: 2023/08/26 18:20:08 by bkaramol         ###   ########.fr       */
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
	// default constructor
	Fixed(); // a ilk buna giriyor

	Fixed(const int nbr);	// b buna giriyor
	Fixed(const float nbr); // c buna giriyor

	float toFloat(void) const;
	int toInt(void) const;

	int getRawBits(void) const;

	// copy constructor
	Fixed(Fixed const &fixed); // d buna giriyor

	// copy assignment operator overload
	Fixed &operator=(Fixed const &fixed); // a = Fixed()'da buraya giriyor

	// destructor
	~Fixed();
};

// output stream operator overload
std::ostream &operator<<(std::ostream &os, Fixed const &fixed);

#endif
