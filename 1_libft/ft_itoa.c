/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 03:11:40 by bkaramol          #+#    #+#             */
/*   Updated: 2023/02/03 03:11:48 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	digit(int nb)
{
	int	i;

	i = 0;
	if (nb == 0 || nb == 1)
		return (1);
	if (nb < 0)
	{
		i++;
		nb = -nb;
	}
	while (nb)
	{
		++i;
		nb /= 10;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*mystr;
	int		a;
	long	nb;

	nb = n;
	a = digit(nb);
	mystr = (char *)malloc(a + 1);
	if (!mystr)
		return (NULL);
	if (n < 0)
	{
		nb *= -1;
		mystr[0] = '-';
	}
	mystr[a] = '\0';
	a--;
	while ((n < 0) <= a)
	{
		mystr[a] = (nb % 10) + 48;
		nb /= 10;
		a--;
	}
	return (mystr);
}
