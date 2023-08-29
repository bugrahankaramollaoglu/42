/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 13:36:25 by bkaramol          #+#    #+#             */
/*   Updated: 2023/08/29 19:47:48 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "animal.hpp"
#include "cat.hpp"
#include "dog.hpp"
#include "wrongAnimal.hpp"
#include "wrongCat.hpp"

int main()
{
	const Animal *animal = new Animal();
	const Animal *dog = new Dog();
	const Animal *cat = new Cat();
	const WrongAnimal *wrong = new WrongCat();

	std::cout << "type: " << dog->getType() << " " << std::endl;
	std::cout << "type: " << cat->getType() << " " << std::endl;

	dog->makeSound();
	cat->makeSound();
	animal->makeSound();
	wrong->makeSound();

	delete animal;
	delete cat;
	delete dog;
	delete wrong;

	return 0;
}
