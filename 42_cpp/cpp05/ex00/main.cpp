/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 11:30:02 by bkaramol          #+#    #+#             */
/*   Updated: 2023/09/04 21:05:50 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

/* int main() {
	Bureaucrat b1;
	std::cout << b1.getGrade() << std::endl;
	std::cout << b1.getName() << std::endl;
} */

/* int main()
{
	Bureaucrat b1("bugra", 50);
	std::cout << b1.getName() << std::endl;
	std::cout << b1.getGrade() << std::endl;
	Bureaucrat b2 = b1;
	std::cout << b2.getName() << std::endl;
	std::cout << b2.getGrade() << std::endl;
} */

/* int main()
{
	// Bureaucrat b1("bugra", 150);
	// b1.decrementGrade();

	// Bureaucrat b1("bugra", 1);
	// b1.incrementGrade();

	std::cout << b1.getGrade() << std::endl;
	std::cout << b1.getName() << std::endl;
} */

/* int main() {
	Bureaucrat b1("bugra", 52);
	std::cout << b1 << std::endl;
} */

/* int main()
{
	Bureaucrat b1("bugra", 50);
	std::cout << b1.getName() << std::endl;
	std::cout << b1.getGrade() << std::endl;
	Bureaucrat b2;
	b2 = b1;
	std::cout << b2.getName() << std::endl;
	std::cout << b2.getGrade() << std::endl;
} */

/* int main()
{
	// eğer böyle çağırırsan =operator() çalışıyor ama
	Bureaucrat b1;
	Bureaucrat b2;
	b2 = b1;
} */

/* int main()
{
	// böyle çağırırsan sadece copy constructor() çağrılıyor
	Bureaucrat b1;
	Bureaucrat b2 = b1;
}  */

/*

int main()
{
	try
	{
		Bureaucrat bureaucrat("Daryl", 50);
		std::cout << bureaucrat << std::endl;

		bureaucrat.incrementGrade();
		std::cout << bureaucrat << std::endl;

		bureaucrat.decrementGrade();
		std::cout << bureaucrat << std::endl;

		Bureaucrat invalidBureaucrat("Rick", 0);
	}
	catch (exception &e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	return (0);
} */
