/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 20:07:13 by bkaramol          #+#    #+#             */
/*   Updated: 2023/09/16 10:56:01 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

/* int main() {
	Span sp = Span(3);

	sp.addNumber(1);
	sp.addNumber(2);
	sp.addNumber(3);
	sp.addNumber(4);
}
 */


/*  int main()
{
	Span sp = Span(6);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << "shortest: " << sp.shortestSpan() << "\n";
	std::cout << "longest: " << sp.longestSpan() << "\n";
} */


/* int main()
{
	try
	{
		Span sp = Span(10000);
		std::vector<int> v3;
		for (int i = 0; i < 10000; i++)
			v3.push_back(i);
		sp.addRange(v3.begin(), v3.end());
		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
} */

