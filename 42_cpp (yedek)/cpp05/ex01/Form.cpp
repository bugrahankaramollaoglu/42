/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 14:42:08 by bkaramol          #+#    #+#             */
/*   Updated: 2023/09/06 16:40:57 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

// ################## CANONICAL ##################

Form::Form() : _name("default-name"), _isSigned(false), _gradeOfSign(0), _gradeOfExecution(0)
{
	std::cout << "Form default constructor called" << std::endl;
}

Form::~Form()
{
	std::cout << "Form destructor called" << std::endl;
}

Form::Form(const Form &other) : _name(other._name), _isSigned(other._isSigned), _gradeOfSign(other._gradeOfSign), _gradeOfExecution(other._gradeOfExecution)
{
	std::cout << "Form copy constructor called" << std::endl;
}

Form &Form::operator=(const Form &other)
{
	std::cout << "Form assignation operator called" << std::endl;
	if (this == &other)
		return (*this);
	this->_isSigned = other._isSigned;
	return (*this);
}

// ################## GETTERS ##################

const std::string &Form::getName() const
{
	return (this->_name);
}

bool Form::getIsSigned() const
{
	return (this->_isSigned);
}

int Form::getGradeOfSign() const
{
	return (this->_gradeOfSign);
}

int Form::getGradeOfExecution() const
{
	return (this->_gradeOfExecution);
}

// ################## OTHER CONSTRUCTORS ##################

Form::Form(const std::string name, int gradeOfSign, int gradeOfExecution) : _name(name), _gradeOfSign(gradeOfSign), _gradeOfExecution(gradeOfExecution)
{
	if (gradeOfSign < 1 || gradeOfExecution < 1)
		throw Form::GradeTooHighException();
	if (gradeOfSign > 150 || gradeOfExecution > 150)
		throw Form::GradeTooLowException();
	this->_isSigned = 1;
	std::cout << "Form constructor called" << std::endl;
}

void Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->_gradeOfSign)
	{
		throw Form::GradeTooLowException();
		return;
	}
	else
	{
		this->_isSigned = true;
		std::cout << "Form is signed" << std::endl;
	}
}

// ################## OPERATOR<< ##################

std::ostream &operator<<(std::ostream &out, const Form &form)
{
	out << "\nForm name: " << form.getName() << std::endl;
	out << "Form isSigned: " << form.getIsSigned() << std::endl;
	out << "Form gradeOfSign: " << form.getGradeOfSign() << std::endl;
	out << "Form gradeOfExecution: " << form.getGradeOfExecution() << std::endl;
	return (out);
}
