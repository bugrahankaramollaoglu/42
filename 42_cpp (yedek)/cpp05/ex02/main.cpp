/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 18:33:16 by bkaramol          #+#    #+#             */
/*   Updated: 2023/09/10 14:19:46 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int main()
{
	try
	{
		// Bureaucrat bureaucrat("deneme", 0); // error
		// Bureaucrat bureaucrat("deneme", 151); // error

		std::cout << "\n--------------- Class 1 (Shrubbery) (145-137) ---------------" << "\n" << "\n";
		// Bureaucrat bureaucrat("shrub", 100);
		// Bureaucrat bureaucrat("shrub", 140);
		// Bureaucrat bureaucrat("shrub", 150);
		// ShrubberyCreationForm ss("home");
		// bureaucrat.signForm(ss);
		// bureaucrat.executeForm(ss);

		std::cout << "\n--------------- Class 2 (Robotomy) (72-45) ------------------ " << std::endl;
		// Bureaucrat bureaucrat("robo", 80);
		// Bureaucrat bureaucrat("robo", 70);
		// Bureaucrat bureaucrat("robo", 30);
		// RobotomyRequestForm rr("Robotomy");
		// bureaucrat.signForm(rr);
		// bureaucrat.executeForm(rr);

		std::cout << "\n\n--------------- Class 3 (President) (25-5) ------------------" << "\n\n";
		// Bureaucrat bureaucrat("president", 50);
		// Bureaucrat bureaucrat("president", 20);
		// Bureaucrat bureaucrat("president", 3);
		// PresidentialPardonForm pp("President");
		// bureaucrat.signForm(pp);
		// bureaucrat.executeForm(pp);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "\n";
}
