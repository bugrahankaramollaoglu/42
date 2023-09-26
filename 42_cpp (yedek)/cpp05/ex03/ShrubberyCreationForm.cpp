/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 18:35:15 by bkaramol          #+#    #+#             */
/*   Updated: 2023/09/10 13:17:57 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

/* shrubbery: ağaçlık, bahçe */

ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("ShrubberyCreationForm", 145, 137)
{
	return;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
	: AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
	return;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src)
	: AForm("ShrubberyCreationForm", 145, 137), _target(src._target)
{
	return;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	return;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &obj)
{
	(void)obj;
	return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	this->AForm::executeCheck(executor);

	std::string file_name = _target + "_shrubbery";
	const char *cString = file_name.c_str();
	std::ofstream file(cString);

	if (file.is_open())
	{
		file << "        ^        \n";
		file << "       ^^^       \n";
		file << "      ^^^^^      \n";
		file << "     ^^^^^^^     \n";
		file << "    ^^^^^^^^^    \n";
		file << "   ^^^^^^^^^^^   \n";
		file << "  ^^^^^^^^^^^^^  \n";
		file << "        ||       \n";

		file.close();
		std::cout << "File " << _target << "_shrubbery has been created" << std::endl;
	}
	else
	{
		throw FileOpeningFail();
	}
}
