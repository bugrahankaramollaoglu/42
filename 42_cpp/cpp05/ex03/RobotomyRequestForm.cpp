/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 18:34:22 by bkaramol          #+#    #+#             */
/*   Updated: 2023/09/10 13:22:09 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

/* robotomy: when a person has very few emotions or vocal inflections and
behaves like a robot as if they have had a lobotomy. */

/* lobotomy: iki beyin lobunu bağlayan sinir bağlarının kesilmesi.
şizofreni tedavisinde kullanılır. */

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45)
{
 return ;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)\
 : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src)\
 : AForm("RobotomyRequestForm", 72, 45), _target(src._target)
{
	return ;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	return ;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &obj)
{
	(void)obj;
    return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	this->AForm::executeCheck(executor);
	std::srand(std::time(0));
	double chance = (double)((std::rand()) / (RAND_MAX + (double)1));
	double probability = 0.5;

	if (chance > probability) {
		std::cout << "drilling noises..." << std::endl;
		std::cout << "We inform that " << _target << " has been robotomized." << std::endl;
	} else {
		std::cout << "We inform that unfortunately robotomy failed." << std::endl;
	}
}
