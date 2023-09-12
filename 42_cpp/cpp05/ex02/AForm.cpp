/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 18:32:44 by bkaramol          #+#    #+#             */
/*   Updated: 2023/09/09 20:24:01 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : _name("default-name"), _gradeToSign(150), _gradeToExecute(150), _signed(false)
{
}

AForm::AForm(const std::string &name, int gradeToSign, int gradeToExecute)
	: _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute), _signed(false)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw AForm::GradeTooHighException();
	if (gradeToExecute > 150 || gradeToSign > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm &Aform) : _name(Aform._name), _gradeToSign(Aform._gradeToSign), _gradeToExecute(Aform._gradeToExecute) {
	*this = Aform;
}

AForm::~AForm() {
}

AForm &AForm::operator=(const AForm &Aform) {
	if (this != &Aform)
		_signed = Aform._signed;
	return (*this);
}

std::ostream &operator<<(std::ostream &o, const AForm &rhs) {
	o << rhs.getName() << ", Aform sign is " << std::boolalpha << rhs.getSigned() << ", grade to sign is " << rhs.getGradeToSign() << ", grade to execute is " << rhs.getGradeToExecute();
	return o;
}

const std::string AForm::getName() const {
	return (_name);
}

bool AForm::getSigned() const {
	return _signed;
}

int AForm::getGradeToSign() const {
	return _gradeToSign;
}

int AForm::getGradeToExecute() const {
	return (this->_gradeToExecute);
}

// Aform sadece bureaucrat'ın grade'i yeterliyse sign edilebilir.
void AForm::beSigned(const Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() <= this->_gradeToSign)
		this->_signed = true;
	else
		throw AForm::GradeTooLowException();
}

// Aform sadece bureaucrat'ın grade'i yeterliyse execute edilebilir.
// bir Aform objesi sign edilmemişse execute edilemez, ilk if onun için
void AForm::executeCheck(const Bureaucrat &bureaucrat) const {
	if (!this->getSigned())
		throw AForm::ExecuteNotSigned();
	if (this->getGradeToExecute() < bureaucrat.getGrade())
		throw AForm::GradeTooLowException();
}

const char *AForm::GradeTooHighException::what() const throw() {
	return "Error: Grade is too high";
}

const char *AForm::GradeTooLowException::what() const throw() {
	return "Error: Grade is too low";
}

const char *AForm::ExecuteNotSigned::what() const throw() {
	return "Error: Form is not signed";
}

const char *AForm::FileOpeningFail::what() const throw() {
	return "Error: Cannot open file";
}
