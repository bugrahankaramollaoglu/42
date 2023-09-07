/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 16:40:54 by bkaramol          #+#    #+#             */
/*   Updated: 2023/09/06 16:41:48 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
	const std::string _name;
	bool _isSigned;
	const int _gradeOfSign;
	const int _gradeOfExecution;

public:
	Form();
	~Form();
	Form(const Form &other);
	Form &operator=(const Form &other);

public:
	Form(const std::string name, int gradeOfSign, int gradeOfExecution);
	void beSigned(const Bureaucrat &bureaucrat);

public:
	const std::string &getName() const;
	bool getIsSigned() const;
	int getGradeOfSign() const;
	int getGradeOfExecution() const;

public:
	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char *what() const throw()
		{
			return ("Grade too high");
		}
	};
	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char *what() const throw()
		{
			return ("Grade too low");
		}
	};
	/* we can't declare this function inside the class bc it must be either
	global or friend function, it cannot be a member function:
	std::ostream &operator<<(std::ostream &out, const Form &form);
	bu you can use it if you put a <friend> at the beginning, which 42 permits
	peki nası oluyor da = operatörü class içinde oluyor ama << yasak?
	= operator can be overloaded as a member function bc it operates
	on the current object, modifying its state. When you use the = operator on
	an object of the class, it's applied to that object:

	Form form1;
	Form form2;
	form1 = form2; // Calls the overloaded operator=

	When you use << to output an object, it's applied to the
	stream and the object separately. In C++, you can overload binary
	operators like +, -, *, =, etc., as member functions of a class when
	the operation directly affects the state of the object. On the other
	hand, operators like << and >>, which are used for input and output
	operations and don't directly modify the object's state, are typically
	overloaded as free functions or friend functions to provide more
	flexibility and maintain a separation of concerns. */
};

std::ostream &operator<<(std::ostream &out, const Form &form);

#endif
