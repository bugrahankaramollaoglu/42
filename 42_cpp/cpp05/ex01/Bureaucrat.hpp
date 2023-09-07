/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 19:05:00 by bkaramol          #+#    #+#             */
/*   Updated: 2023/09/06 16:09:58 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>

#include "Form.hpp"

class Form;

class Bureaucrat
{
private:
	const std::string _name;
	int _grade;

public:
	Bureaucrat();
	~Bureaucrat();
	Bureaucrat(const Bureaucrat &other);
	Bureaucrat &operator=(const Bureaucrat &other);

public:
	Bureaucrat(const std::string name, int grade);
	void signForm(Form &form) const;

public:
	std::string getName() const;
	int getGrade() const;

public:
	void incrementGrade();
	void decrementGrade();

public:
	class GradeTooHighException : public std::exception
	{
	public:
		const char *what() const throw() { return "grade too high"; }
	};
	class GradeTooLowException : public std::exception
	{
	public:
		const char *what() const throw() { return "grade too low"; }
	};
};

std::ostream &operator<<(std::ostream &o, const Bureaucrat &rhs);

#endif
