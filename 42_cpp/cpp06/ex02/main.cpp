/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 22:11:29 by bkaramol          #+#    #+#             */
/*   Updated: 2023/09/12 22:24:57 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cmath>

Base *generate(void)
{
	int randomValue = rand() % 3 + 1;
	switch (randomValue)
	{
	case 1:
		return new A();
	case 2:
		return new B();
	default:
		return new C();
	}
}

void identify(Base *p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "C" << std::endl;
	else
		std::cerr << "dynamic_cast<> failed!" << std::endl;
}

void identify(Base &p)
{
	try
	{
		if (dynamic_cast<A *>(&p))
			std::cout << "A" << std::endl;
		else if (dynamic_cast<B *>(&p))
			std::cout << "B" << std::endl;
		else if (dynamic_cast<C *>(&p))
			std::cout << "C" << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}

int main()
{
	srand(time(NULL));
	Base *ptr = generate();

	std::cout << ptr << std::endl;

	std::cout << "identify that take pointer" << std::endl;
	identify(ptr);
	std::cout << "identify that take reference" << std::endl;
	identify(*ptr);

	delete ptr;
	return (0);
}
