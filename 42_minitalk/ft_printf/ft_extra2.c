/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extra2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 18:30:45 by bkaramol          #+#    #+#             */
/*   Updated: 2022/07/29 22:02:15 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_u(unsigned int u)
{
	int	i;

	i = 0;
	if (u <= 9)
		i += ft_putchar(u + '0');
	else
	{
		i += ft_u(u / 10);
		i += ft_u(u % 10);
	}
	return (i);
}

int	ft_p(unsigned long p)
{
	int	i;

	i = 0;
	if (p >= 16)
		i += ft_p(p / 16);
	if ((p % 16) < 10)
		i += ft_putchar((p % 16) + '0');
	else
		i += ft_putchar((p % 16) + 87);
	return (i);
}

int	ft_x(unsigned int x, int b)
{
	int	i;

	i = 0;
	if (x >= 16)
		i += ft_x(x / 16, b);
	if ((x % 16) < 10)
		i += ft_putchar((x % 16) + '0');
	else
	{
		if (b == 0)
			i += ft_putchar((x % 16) + 87);
		else
			i += ft_putchar((x % 16) + 55);
	}
	return (i);
}
