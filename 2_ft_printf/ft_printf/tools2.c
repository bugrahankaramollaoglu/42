/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 22:23:57 by bkaramol          #+#    #+#             */
/*   Updated: 2023/02/08 15:10:29 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (*s)
	{
		i++;
		s++;
	}
	return (i);
}

int	ft_printf_lowerx(unsigned long x)
{
	int	ret;

	ret = 0;
	if (x >= 16)
		ret += ft_printf_lowerx(x / 16);
	if ((x % 16) < 10)
		ret += ft_printf_putchar((x % 16) + 48);
	else
		ret += ft_printf_putchar((x % 16) + 87);
	return (ret);
}

int	ft_printf_upperx(unsigned long x)
{
	int	ret;

	ret = 0;
	if (x >= 16)
		ret += ft_printf_upperx(x / 16);
	if ((x % 16) < 10)
		ret += ft_printf_putchar((x % 16) + 48);
	else
		ret += ft_printf_putchar((x % 16) + 55);
	return (ret);
}
