/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 13:36:25 by bkaramol          #+#    #+#             */
/*   Updated: 2023/08/29 22:43:20 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "animal.hpp"
#include "cat.hpp"
#include "dog.hpp"
#include "wrongAnimal.hpp"
#include "wrongCat.hpp"

/* int main()
{
	Animal *animals[10];

	for (int i = 0; i < 5; ++i)
	{
		std::cout << "dog: " << i << std::endl;
		animals[i] = new Dog();
	}

	for (int i = 5; i < 10; ++i)
	{
		std::cout << "cat: " << i << std::endl;
		animals[i] = new Cat();
	}

	for (int i = 0; i < 10; ++i)
	{
		std::cout << "destruct: " << i << std::endl;
		delete animals[i];
	}

	return (0);
}
 */

int main()
{
	const Animal *j = new Dog();
	const Animal *i = new Cat();

	delete j;
	delete i; // no leaks

	return 0;
}
