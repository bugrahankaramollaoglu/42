/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 16:12:06 by bkaramol          #+#    #+#             */
/*   Updated: 2023/09/12 16:12:21 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "use it like: ./convert yourValue" << std::endl;
	}
	else
	{
		ScalarConverter::checkValue(av[1]);
		ScalarConverter::convert(av[1]);
	}
	return (0);
}
