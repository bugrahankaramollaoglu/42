/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 12:22:50 by bkaramol          #+#    #+#             */
/*   Updated: 2023/09/02 12:31:16 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

/* reference ile pointer arasındaki fark nedir

1) pointer adres tutan değişkenlerdir, referans ise birer aliastır
2) pointerlar null olabilir referanslar olamaz
3) pointerlar başka objeye atanabilir referanslar değişmez
4) aritmetik işlemleri pointerla yaparsin referansla yapamazsin

Use pointers when you need dynamic memory management, nullable
objects, or need to reassign the pointer to different objects

Use references when you want to avoid null references, have a
simpler syntax for function parameters, or want to provide
an alias for an existing object

Always prefer references over pointers for function parameters
when you don't need to modify the parameter, as they provide
safety and cleaner syntax. */

int main()
{
	std::string str = "HI THIS IS BRAIN";
	std::string *strPtr = &str;
	std::string &strRef = str;

	std::cout << &str << std::endl;	   // adres
	std::cout << strPtr << std::endl;  // adres
	std::cout << &strRef << std::endl; // adres

	std::cout << str << std::endl;	   // hi this is brain
	std::cout << *strPtr << std::endl; // hi this is brain
	std::cout << strRef << std::endl;  // hi this is brain
}
