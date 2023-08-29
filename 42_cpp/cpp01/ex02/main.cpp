/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 12:22:50 by bkaramol          #+#    #+#             */
/*   Updated: 2023/08/20 13:44:40 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{
	std::string str = "HI THIS IS BRAIN";
	std::string *strPtr = &str;
	std::string &strRef = str;

	std::cout << &str << std::endl;
	std::cout << strPtr << std::endl;
	std::cout << &strRef << std::endl;

	std::cout << str << std::endl;
	std::cout << *strPtr << std::endl;
	std::cout << strRef << std::endl;
}
