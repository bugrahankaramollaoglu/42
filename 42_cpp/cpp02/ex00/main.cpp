/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 15:47:59 by bkaramol          #+#    #+#             */
/*   Updated: 2023/09/21 21:45:28 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/* int main()
{
	Fixed fixed;
	std::cout << fixed.getRawBits() << std::endl; // 0
	fixed.setRawBits(23);
	std::cout << fixed.getRawBits() << std::endl; // 23
} */

/* int main()
{
	Fixed fixed;
	fixed.setRawBits(23);
	Fixed fixed2 = fixed;
	std::cout << fixed2.getRawBits() << std::endl;
} */

/* int main(void)
{
	Fixed a; // what calls default constr
	Fixed b(a); // what calls copy constr // same as Fixed b = a;
	Fixed c;

	c = b; // what calls copy constr + assignment operator

	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;

	return 0;
} */
