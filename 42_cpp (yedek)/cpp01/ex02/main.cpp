/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 14:04:44 by bkaramol          #+#    #+#             */
/*   Updated: 2023/09/21 14:35:38 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{
	std::string string = "HI THIS IS BRAIN";
	std::string *stringPtr = &string;
	std::string &stringRef = string;

	std::cout << &string << std::endl;
	std::cout << stringPtr << std::endl;
	std::cout << &stringRef << std::endl;

	std::cout << string << std::endl;
	std::cout << *stringPtr << std::endl;
	std::cout << stringRef << std::endl;
}
