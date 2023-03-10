/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 22:23:57 by bkaramol          #+#    #+#             */
/*   Updated: 2023/02/12 16:08:20 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printf_putstr(char *str)
{
	int ret;
	int i;

	ret = 0;
	i = 0;
	if (!str)
		return (ft_printf_putstr("(null)"));
	else
	{
		while (str[i])
		{
			ret += ft_printf_putchar(str[i]);
			i++;
		}
		return (ret);
	}
}

int ft_printf_print_ptr(unsigned long ptr)
{
	int ret;

	ret = 0;
	ret += ft_printf_putstr("0x");
	if (ptr >= 16)
		ret += ft_printf_print_ptr(ptr / 16);
	if ((ptr % 16) < 10)
		ret += ft_printf_putchar((ptr % 16) + 48);
	else
		ret += ft_printf_putchar((ptr % 16) + 87);
	return ret;
}

int ft_printf_putnbr(int nb)
{
	int ret;

	ret = 0;
	if (nb < 10)
		ret += ft_printf_putchar(nb + 48);
	else if (nb == -2147483648)
		return (1, "-2147483648", 11);
	else if (nb < 0)
	{
		ret += ft_printf_putchar('-');
		ret += ft_printf_putnbr(nb * (-1));
	}
	else
	{
		ret += ft_printf_putnbr(nb / 10);
		ret += ft_printf_putnbr(nb % 10);
	}
	return (ret);
}

int ft_printf_unsigned(unsigned int u)
{
	int i;

	i = 0;
	if (u <= 9)
		i += ft_printf_putchar(u + '0');
	else
	{
		i += ft_printf_unsigned(u / 10);
		i += ft_printf_unsigned(u % 10);
	}
	return (i);
}
