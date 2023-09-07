/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 15:35:07 by bkaramol          #+#    #+#             */
/*   Updated: 2023/09/04 13:43:12 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/* int main() {
	Fixed fix(10.53f);
	std::cout << fix << std::endl; // functional
	std::cout << fix.toInt() << std::endl; // functinal
	Fixed fix2(35);
	std::cout << fix2 << std::endl; // functional
} */

/* int main() {
	Fixed fixed(17.56f);
	std::cout << fixed.fixedPointNumber << std::endl; // 4495
} */

int main()
{
	Fixed a;
	Fixed const b(10);
	Fixed const c(42.42f);
	Fixed const d(b);
	a = Fixed(1234.4321f);
	std::cout << "a is " << a << std::endl;							 // 6.5
	std::cout << "b is " << b << std::endl;							 // 10
	std::cout << "c is " << c << std::endl;							 // 42.4219
	std::cout << "d is " << d << std::endl;							 // 10
	std::cout << "a is " << a.toInt() << " as integer" << std::endl; // 1234
	std::cout << "b is " << b.toInt() << " as integer" << std::endl; // 10
	std::cout << "c is " << c.toInt() << " as integer" << std::endl; // 42
	std::cout << "d is " << d.toInt() << " as integer" << std::endl; // 10
}
