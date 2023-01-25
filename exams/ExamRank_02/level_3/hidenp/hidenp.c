/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hidenp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 17:46:45 by bkaramol          #+#    #+#             */
/*   Updated: 2022/12/08 17:46:46 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int main(int ac, char **av)
{
	if (ac == 3)
	{
		if (ft_strlen(av[1]) == 0)
		{
			write(1, "1\n", 2);
			return (0);
		}
		int i = 0;
		int j = 0;
		int counter = 0;
		while (av[1][i])
		{
			while (av[2][j])
			{
				if (av[2][j] == av[1][i])
				{
					counter++;
					break;
				}
				j++;
			}
			i++;
		}
		if (ft_strlen(av[1]) == counter)
			write(1, "1", 1);
		else
			write(1, "0", 1);
	}
	write(1, "\n", 1);
	return (0);
}