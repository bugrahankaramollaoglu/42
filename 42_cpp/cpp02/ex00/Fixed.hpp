/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 15:47:50 by bkaramol          #+#    #+#             */
/*   Updated: 2023/09/25 17:20:24 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Fixed
{
private:
	int fixedPointNumber;
	static const int bits;

public:
	Fixed();
	~Fixed();
	Fixed(Fixed const &fixed);
	Fixed &operator=(Fixed const &fixed);

public:
	int getRawBits(void) const;
	void setRawBits(int const raw);
};
