/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 16:10:47 by bkaramol          #+#    #+#             */
/*   Updated: 2023/09/02 12:46:00 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replace.hpp"

int main(int ac, char **av)
{
	Replace replace;

	// parametreler hatalı girilmişse
	if (ac != 4 || replace.ft_strlen(av[1]) == 0 || replace.ft_strlen(av[2]) == 0 || replace.ft_strlen(av[3]) == 0)
	{
		std::cerr << "erroneous params" << std::endl;
		exit(-1);
	}
	else
		replace.fun(av[1], av[2], av[3]);
	return 0;
}
