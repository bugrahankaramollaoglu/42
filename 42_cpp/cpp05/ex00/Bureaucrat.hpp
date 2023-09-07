/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 19:05:00 by bkaramol          #+#    #+#             */
/*   Updated: 2023/09/04 21:10:29 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>

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
