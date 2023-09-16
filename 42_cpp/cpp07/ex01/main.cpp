/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 13:37:47 by bkaramol          #+#    #+#             */
/*   Updated: 2023/09/14 16:35:12 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

/* Your iter function template must work with any type of array. The third parameter
can be an instantiated function template. what does it mean?
it means that when you define and use the iter function template,
the third parameter can be a callable object that is either a regular
function, a function object (a class with an overloaded operator()),
or even an instantiated function template. In other words, the iter function
should be flexible enough to accept different types of functions or function
objects as its third parameter. This allows you to use various methods to process
the elements of the array, including regular functions, functors (classes with
operator() overloaded), and even function templates. */

/* int main()
{
	int tab[] = {0, 1, 2, 3, 4}; // <--- I never understood why you can 't write int[] tab. Wouldn' t that make more sense ?
	Awesome tab2[5];
	iter(tab, 5, print);
	std::cout << "\n";
	iter(tab2, 5, print);
	return 0;
}
 */

/* --------------------------------------- */

/* template <typename T>
void doubleInt(T &i)
{
	i = i * i;
}

template <typename T>
void kapitalize(T &i)
{
	i = i - 32;
}

template <typename T>
void halve(T &i)
{
	i = i / 2;
}

int main()
{
	// int ar[] = {1,2,3,4,5};
	// iter(ar, 5, doubleInt);
	// iter(ar, 5, print);

	// char ar[] = {'a', 'b', 'c'};
	// iter(ar, 3, kapitalize);
	// iter(ar, 3, print);

	// float ar[] = {10.51f, 23.66f, 42.20f};
	// iter(ar, 3, halve);
	// iter(ar, 3, print);
}
 */
