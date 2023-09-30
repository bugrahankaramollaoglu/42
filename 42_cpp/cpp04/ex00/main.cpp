/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 21:43:59 by bkaramol          #+#    #+#             */
/*   Updated: 2023/09/28 10:25:51 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "animal.hpp"
#include "dog.hpp"
#include "cat.hpp"
#include "wrongAnimal.hpp"
#include "wrongCat.hpp"

/* int main()
{
	// Animal animal;
	// std::cout << animal.getType() << std::endl;
	// makeSound() ise direkt kendisi fonksiyon
	// animal.makeSound();

	// Animal* a = new Animal();
	// delete a;

	// Dog dog;
	// std::cout << dog.getType() << std::endl;
	// dog.makeSound();

	// Cat cat;
	// std::cout << cat.getType() << std::endl;
	// cat.makeSound();

	// Dog* d = new Dog();
	// delete d;

	// Cat* c = new Cat();
	// delete c;
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

// WRONG_ANIMAL KULLANIM ÖRNEĞİ
/* int main()
{
	// cat'i Animal'dan da çağırsak Cat'ten de çağırsak miyav diyor
	// const Animal *cat = new Cat();
	// const Cat *cat2 = new Cat();
	// std::cout << "\n";
	// cat->makeSound();
	// cat2->makeSound();
	// std::cout << "\n";
	// delete cat;
	// delete cat2;

	// ama wrong animal subjectte dedigi gibi sadece Catten cagrılınca diyor (bc virtual degil)
	// const WrongAnimal *w_cat = new WrongCat();
	// const WrongCat *w_cat2 = new WrongCat();
	// std::cout << "\n";
	// w_cat->makeSound();
	// w_cat2->makeSound();
	// std::cout << "\n";
	// delete w_cat;
	// delete w_cat2;
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
