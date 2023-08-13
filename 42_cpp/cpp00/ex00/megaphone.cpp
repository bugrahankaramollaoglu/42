/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 18:16:44 by bkaramol          #+#    #+#             */
/*   Updated: 2023/08/13 18:23:03 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

char ft_toUpper(char c)
{
	if (c >= 'a' && c <= 'z')
	{
		c -= 32;
	}
	return c;
}

int main(int ac, char **av)
{
	if (ac == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	}
	else
	{
		int i(1);
		int i2(0);
		char tmp;
		while (i < ac)
		{
			while (av[i][i2])
			{
				tmp = ft_toUpper(av[i][i2]);
				std::cout << tmp;
				i2++;
			}
			i2 = 0;
			i++;
		}
	}
	std::cout << std::endl;
}
