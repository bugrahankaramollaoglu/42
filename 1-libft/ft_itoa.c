/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 13:20:09 by bkaramol          #+#    #+#             */
/*   Updated: 2023/01/21 00:23:40 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	digit(int nb)
{
	int	counter;

	counter = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
	{
		counter++;
		nb *= -1;
	}
	while (nb)
	{
		++counter;
		nb /= 10;
	}
	return (counter);
}

char	*ft_itoa(int nb)
{
	char	*string;
	int		dig;
	int		nb2;

	dig = digit(nb);
	nb2 = nb;
	string = malloc(dig + 1);
	if (!string)
		return (0);
	if (nb < 0)
	{
		string[0] = '-';
		nb = -nb;
	}
	string[dig] = '\0';
	dig--;
	while ((nb < 0) <= dig)
	{
		string[dig] = (nb2 % 10) + '0';
		dig--;
		nb2 /= 10;
	}
	return (string);
}
