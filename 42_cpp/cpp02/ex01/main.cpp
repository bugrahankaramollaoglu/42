/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 15:35:07 by bkaramol          #+#    #+#             */
/*   Updated: 2023/09/25 22:19:43 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/* int main()
{
	Fixed f(2.5f);
	std::cout << f.getRawBits() << "\n"; // 640
	// bu kod neden 640 verdi? sebebi şu: 2.5f
	// Fixed classında fixedPointNumber değişkeninde saklanıyor
	// 2.5 sayısı 2^8 ile çarpılarak fixed-pointe çevriliyor,
	// 2.5 x 256 = 640 ediyor, yani 2.5 sayısının fixed-point tipinde
	// rawBit karşılığı 640. 2^6 7 değil de 8 olma sebebi fractional
	// bits olarak 8'i	almamız, fixed-point sayısında fractional yani
	// virgülden sonraki kısma 8 basamak ayrılmış demek. mesela toInt()
	// fonksiyonunda 8 ile çarpiyodu sayiyi, her çarpışta bir
	// sağa kaydiriyodu böylece fractiondan (ondalık) kurtulup asıl integer
	// kısmı alabiliyoduk.
} */

/* int main()
{
	Fixed f(2.5f);
	float myFloat = f.toFloat();

	std::cout << "fixed point num: " << f.getRawBits() << "\n";		  // 640
	std::cout << "its convertion to float: " << myFloat << std::endl; // 2.5
																	  // burada 640 fixed point numberin kendisi değildir,
																	  // fractional bit sayısı  ile çarpılmış halidir.
} */

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
	std::cout << "b2 is " << b.toInt() << " as integer" << std::endl; // 10
	std::cout << "c is " << c.toInt() << " as integer" << std::endl; // 42
	std::cout << "d is " << d.toInt() << " as integer" << std::endl; // 10
}

