/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 15:22:27 by bkaramol          #+#    #+#             */
/*   Updated: 2023/09/10 15:48:18 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern &intern)
{
	*this = intern;
}

Intern::~Intern() {}

Intern	&Intern::operator=(const Intern &intern)
{
	(void)intern; // Intern'ün attribtue olmadıgı icin kopyalayamıyoruz
	return (*this);
}

// bu fonksiyonlarda dinamik objeler olusturup döndürüyoruz
// Static data members in a class are shared by all the class
// objects as there is only one copy of them in the memory,
// regardless of the number of objects of the class.
static AForm *newShrubbery(const std::string target)
{
	return (new ShrubberyCreationForm(target));
}

static AForm	*newRobotomy(const std::string target)
{
	return (new RobotomyRequestForm(target));
}

static AForm	*newPresidential(const std::string target)
{
	return (new PresidentialPardonForm(target));
}

AForm *Intern::makeForm(const std::string formName, const std::string target) const
{
	ConstructorPtr constructorPtr[3] = {&newShrubbery, &newPresidential, &newRobotomy};
	std::string		formNames[3] = {"shrubbery creation", "presidential pardon", "robotomy request"};
	AForm *formPtr = NULL;
	int i = 0;

	while (i < 3)
	{
		if (formName == formNames[i])
		{
			formPtr = constructorPtr[i](target);
			std::cout << "Intern creates " << formPtr->getName() << " form." << std::endl;
			return (formPtr);
			break ;
		}
		i++;
	}
	throw MakeFormErrorException();
}

const char *Intern::MakeFormErrorException::what() const throw() {
	return "Error: Intern could not create form.";
}
