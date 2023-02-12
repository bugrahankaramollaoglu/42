/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools0.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 22:23:57 by bkaramol          #+#    #+#             */
/*   Updated: 2023/02/12 16:04:43 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int checker(int c, va_list ap);

int ft_printf(const char *s, ...)
{
	va_list arg;
	int i;
	int j;

	va_start(arg, s);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != '%')
		{
			ft_printf_putchar(s[i]);
			j++;
		}
		if (s[i] == '%')
		{
			i++;
			j += checker(s[i], arg);
		}
		i++;
	}
	va_end(arg);
	return (j);
}

int checker(int c, va_list ap)
{
	int ret;

	ret = 0;
	if (c == 's')
		ret += ft_printf_putstr(va_arg(ap, char *));
	else if (c == 'c')
		ret += ft_printf_putchar(va_arg(ap, int));
	else if (c == 'p')
		ret += ft_printf_print_ptr(va_arg(ap, unsigned long));
	else if (c == 'd' || c == 'i')
		ret += ft_printf_putnbr(va_arg(ap, int));
	else if (c == 'u')
		ret += ft_printf_unsigned(va_arg(ap, int));
	else if (c == 'x' || c == 'X')
	{
		if (c == 'x')
			ret += ft_printf_lowerx(va_arg(ap, int));
		if (c == 'X')
			ret += ft_printf_upperx(va_arg(ap, int));
	}
	else if (c == '%')
		ret += ft_printf_putchar('%');
	else
		return (ft_printf_putchar(c));
	return (ret);
}
