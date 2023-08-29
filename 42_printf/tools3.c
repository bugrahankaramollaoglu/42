/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 13:25:53 by bkaramol          #+#    #+#             */
/*   Updated: 2023/08/14 23:28:08 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_c(char c)
{
	write(1, &c, 1);
	return (1);
}

int	print_s(char *str)
{
	int	i;

	if (!str)
		str = "(null)";
	i = -1;
	while (str[++i])
		write(1, &str[i], 1);
	return (i);
}

int	digit(int nb)
{
	int	dig;

	if (nb == 0 || nb == 1)
		return (1);
	dig = 0;
	if (nb < 0)
	{
		dig++;
		nb = -nb;
	}
	while (nb)
	{
		dig++;
		nb = nb / 10;
	}
	return (dig);
}

// %i ve %d yazdırma
int	print_di(int nb)
{
	int		ret;
	char	t;

	ret = digit(nb);
	if (nb >= 0 && nb <= 9)
	{
		t = nb + '0';
		print_c(t);
	}
	else if (nb == -2147483648)
		print_s("-2147483648");
	else if (nb < 0)
	{
		print_c('-');
		print_di(-nb);
	}
	else
	{
		print_di(nb / 10);
		print_di(nb % 10);
	}
	return (ret);
}

// unsigned yazdırma
int	print_u(unsigned int nb)
{
	int	ret;

	ret = 0;
	if (nb <= 9)
		ret += print_c(nb + '0');
	else
	{
		ret += print_u(nb / 10);
		ret += print_u(nb % 10);
	}
	return (ret);
}
