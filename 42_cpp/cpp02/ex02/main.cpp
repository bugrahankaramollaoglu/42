/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 13:52:14 by bkaramol          #+#    #+#             */
/*   Updated: 2023/09/04 18:08:14 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/* int main()
{
	Fixed fixed(4.0f);
	fixed--;
	std::cout << fixed << std::endl; // 3.99609
	fixed--;
	std::cout << fixed << std::endl; // 3.99219
	fixed++;
	std::cout << fixed << std::endl; // 3.99609'a geri döndü

	// sebebi: fractionalBits'e 8 verdiğimiz için sayı
	// fixedPointNumber aritmetik işlemlerine tabi tutulurken
	// 1/256 üzerinden işlem yapiyor. ilk olarak 4.00000000 şeklinde
	// saklaniyor. fixedPoint-- dediğimiz zaman bu sayıdan 1/256 yani
	// 0.00390625 çıkarıyor her seferinde
} */

int main(void)
{
	Fixed a;
	Fixed const b(Fixed(5.05f) * Fixed(2));

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << Fixed::max(a, b) << std::endl;
	return 0;
} 
