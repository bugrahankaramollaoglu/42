/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 13:25:56 by bkaramol          #+#    #+#             */
/*   Updated: 2023/08/14 01:50:14 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// küçük hex
int	print_x(unsigned int nb)
{
	int	ret;

	ret = 0;
	if (nb >= 16)
		ret += print_x(nb / 16);
	if ((nb % 16) < 10)
		ret += print_c((nb % 16) + 48); // chardan inte dönüştürmek için
	else
		ret += print_c((nb % 16) + 87); // chardan a-f karşılığı chara dönüştürmek
	return (ret);
}

// büyük hex
int	print_capx(unsigned int nb)
{
	int	ret;

	ret = 0;
	if (nb >= 16)
		ret += print_x(nb / 16);
	if ((nb % 16) < 10)
		ret += print_c((nb % 16) + 48); // chardan inte dönüştürmek için
	else
		ret += print_c((nb % 16) + 55); // chardan A-F karşılığı inte dönüştürmek
	return (ret);
}

int	print_p(unsigned long p)
{
	int	i;

	i = 0;
	if (p >= 16)
		i += print_p(p / 16);
	if ((p % 16) < 10)
		i += print_c((p % 16) + '0');
	else
		i += print_c((p % 16) + 87);
	return (i);
}
