/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 21:00:39 by bkaramol          #+#    #+#             */
/*   Updated: 2023/09/25 17:02:59 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::complain(std::string level)
{
	const std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	void (Harl::*options[4])();

	options[0] = &Harl::debug;
	options[1] = &Harl::info;
	options[2] = &Harl::warning;
	options[3] = &Harl::error;

	for (int i = 0; i < 4; i++)
	{
		if (level == levels[i])
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
