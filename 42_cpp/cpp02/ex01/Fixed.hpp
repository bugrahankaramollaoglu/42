/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 15:35:03 by bkaramol          #+#    #+#             */
/*   Updated: 2023/09/21 22:44:47 by bkaramol         ###   ########.fr       */
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
	/* bunu burada static yapmamizin iki sebebi var
	birincisi fractionalBit her zaman 8 olsun ve 8 ile başlasın
	istiyoruz, c++98'de ise bir attribute'u yalnızca constructorlarda
	ilklendirebilirsin, direkt böyle değer veremezsin.
	ikincisi fractionalBits değişkeni objelere değil sınıfa ait olsun istiyoruz
	yani tüm objeler aynı değişkeni kullansın. */
	static const int fractionalBits = 8;

public:
	Fixed();
	Fixed(Fixed const &fixed);
	Fixed &operator=(Fixed const &fixed);
	~Fixed();

public:
	Fixed(const int nbr);
	Fixed(const float nbr);

	float toFloat(void) const;
	int toInt(void) const;

	int getRawBits(void) const;
};

// bunu içeride değil de dışarıda tanımlama sebebimiz convention
std::ostream &operator<<(std::ostream &os, Fixed const &fixed);

#endif
