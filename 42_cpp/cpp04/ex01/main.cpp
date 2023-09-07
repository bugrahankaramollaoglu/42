/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 21:43:59 by bkaramol          #+#    #+#             */
/*   Updated: 2023/09/03 02:08:40 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "animal.hpp"
#include "dog.hpp"
#include "cat.hpp"
#include "wrongAnimal.hpp"
#include "wrongCat.hpp"

/* int main()
{
	const Animal *j = new Dog();
	const Animal *i = new Cat();
	delete j; // should not create a leak
	delete i;
} */

/* int main(void)
{
	Animal *animals[100];
	for (int i = 0; i < 100; i++)
	{
		if (i % 2 == 0)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}
	for (int i = 0; i < 100; i++)
	{
		delete animals[i];
	}

	// ./animals | grep "cat const" | wc -l
	// ./animals | grep "dog const" | wc -l
} */

/* int main() {
	Dog *dog = new Dog();
	Dog *dog2(dog);
	dog2->makeSound();
} */

/* int main()
{

	const Animal *animals[4] = {new Cat, new Dog, new Cat, new Dog};

	for (long unsigned int i = 0; i < sizeof(animals) / sizeof(Animal *); ++i)
	{
		animals[i]->makeSound();
		delete animals[i];
	}

	Dog basic;
	{
		Dog tmp = basic;
	}

	return 0;
}
 */
