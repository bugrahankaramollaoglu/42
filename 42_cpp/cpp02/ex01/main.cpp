/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 16:32:32 by bkaramol          #+#    #+#             */
/*   Updated: 2023/08/26 18:19:12 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main()
{
	Fixed a; // a'ya default constructor uygulanır ve 0 olur
	Fixed const b(10); // b'ye int constructor uygulanır
	Fixed const c(42.42f); // c'ye float constructor uygulanır
	Fixed const d(b); // d'ye copy constructor uygulanır
	a = Fixed(1234.4321f); // a'ya float constructor uygulanır ve a'ya atama yapılır
	std::cout << "a is " << a << std::endl; // 1234.43
	std::cout << "b is " << b << std::endl; // 10
	std::cout << "c is " << c << std::endl; // 42.4219
	std::cout << "d is " << d << std::endl; // 10
	std::cout << "---------------" << std::endl;
	std::cout << "a is " << a.toInt() << " as integer" << std::endl; // 1234
	std::cout << "b is " << b.toInt() << " as integer" << std::endl; // 10
	std::cout << "c is " << c.toInt() << " as integer" << std::endl; // 42
	std::cout << "d is " << d.toInt() << " as integer" << std::endl; // 10
}
