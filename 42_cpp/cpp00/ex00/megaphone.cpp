/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 18:16:44 by bkaramol          #+#    #+#             */
/*   Updated: 2023/08/28 15:17:32 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int ac, char **av)
{
	if (ac >= 2)
	{
		int i(1);
		int i2(0);
		char tmp;
		while (i < ac)
		{
			while (av[i][i2])
			{
				if (av[i][i2] >= 'a' && av[i][i2] <= 'z')
					tmp = av[i][i2] - 32;
				else
					tmp = av[i][i2];
				std::cout << tmp;
				i2++;
			}
			i2 = 0;
			i++;
		}
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	std::cout << "\n";
	return (0);
}
