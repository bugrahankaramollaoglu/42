/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 21:43:59 by bkaramol          #+#    #+#             */
/*   Updated: 2023/09/03 00:00:36 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "animal.hpp"
#include "dog.hpp"
#include "cat.hpp"
#include "wrongAnimal.hpp"
#include "wrongCat.hpp"

/* int main() {
	Animal animal;

	Animal* a = new Animal();
	delete a;

	Dog dog;
	Dog* d = new Dog();
	delete d;

	Cat cat;
	Cat* c = new Cat();
	delete c;
} */

/* int main()
{
	const Animal* meta = new Animal();
	std::cout << "\n";
	const Animal* j = new Dog();
	std::cout << "\n";
	const Animal* i = new Cat();
	std::cout << "\n";
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << "\n";
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	std::cout << "\n";

	delete meta;
	delete i;
	delete j;

	return 0;
} */

/* int main() {
	const WrongAnimal* wa = new WrongAnimal();
	const WrongAnimal* wc = new WrongCat();
	wc->makeSound(); // wrongcat's miyav miyav demeliydi ama animal dedi
	// sebebi ise bu sınıflarda makeSound() virtual olmaması
	delete wa;
	delete wc;
} */

/* int main() {
	WrongCat* wrongcat = new WrongCat();
	wrongcat->makeSound();
} */

/* int main() {
	const Animal *animal = new Animal();
	const Animal *cat = new Cat();
	animal->makeSound();
	delete animal;
	delete cat;
} */

/* int main() {
	const Animal* animal[10];
	for (int i = 0; i < 10; i++) {
		if (i % 2 == 0)
		{
			animal[i] = new Cat();
			animal[i]->makeSound();
		}
		else
		{
			animal[i] = new Dog();
			animal[i]->makeSound();
		}
	}
	for (int i = 0; i < 10; i++) {
		delete animal[i];
	}

	// ./animal | grep "miyav" | wc -l
	// ./animal | grep "hav hav" | wc -l
	// ./animal | grep "destructor called" | wc -l
}
 */
