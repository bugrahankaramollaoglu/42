/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 18:32:52 by bkaramol          #+#    #+#             */
/*   Updated: 2023/09/10 13:12:09 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("default-name"), _grade(150)
{
	this->_grade = _grade;
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat::Bureaucrat(const std::string &name, int grade)
	: _name(name)
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
	else
		this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &bb) : _name(bb._name)
{
	*this = bb;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &bureaucrat)
{
	if (this != &bureaucrat)
		this->_grade = bureaucrat._grade;
	return (*this);
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat)
{
	os << bureaucrat.getName() << ", grade " << bureaucrat.getGrade();
	return (os);
}

void Bureaucrat::increaseGrade()
{
	if (_grade <=  1)
		throw GradeTooHighException();
	_grade--;
}

void Bureaucrat::decreaseGrade()
{
	if (_grade >= 150)
		throw GradeTooLowException();
	_grade++;
}

const std::string Bureaucrat::getName() const
{
	return (_name);
}

int Bureaucrat::getGrade() const
{
	return (_grade);
}

void Bureaucrat::signForm(AForm &Aform)
{
	try	{
		// exceptiona girmezse Aform'daki beSigned()
		// ile *this'i imzalayacak, yoksa sebebiyle hata verecek
		Aform.beSigned(*this);
		std::cout << this->_name << " signed " << Aform.getName() << std::endl;
	}
	catch (const std::exception &e) {
		std::cout << _name << " couldn't sign " << Aform.getName() << " because " << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(const AForm &Aform) const
{
	try	{
		Aform.execute(*this);
		std::cout << _name << " executed " << Aform.getName() << std::endl;
	}
	catch (const std::exception &e)	{
		std::cout << _name << " cannot execute " << Aform.getName()
				  << " because " << e.what() << std::endl;
	}
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return "Error: Grade is too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return "Error: Grade is too low";
}
