/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 21:00:39 by bkaramol          #+#    #+#             */
/*   Updated: 2023/09/02 13:58:23 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::complain(std::string level)
{
	// creates a string array to do the checking
	const std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	// array of pointers to each member function of Harl class.
	// function pointers to member functions are defined like that
	// returnType (className::*funcName)(parameters)
	void (Harl::*options[4])();

	// arraydeki her pointer sirasiyla fonksiyonları tutuyor
	options[0] = &Harl::debug;
	options[1] = &Harl::info;
	options[2] = &Harl::warning;
	options[3] = &Harl::error;

	for (int i = 0; i < 4; i++)
	{
		if (level == levels[i])
			// calls the corresponding function using pointer
			(this->*options[i])();
	}
}

void Harl::debug()
{
	std::cout << "This is debug message" << std::endl;
}

void Harl::info()
{
	std::cout << "This is info message" << std::endl;
}

void Harl::warning()
{
	std::cout << "This is warning message" << std::endl;
}

void Harl::error()
{
	std::cout << "This is error message" << std::endl;
}
