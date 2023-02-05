/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools0.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 22:23:57 by bkaramol          #+#    #+#             */
/*   Updated: 2023/02/05 14:53:48 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	checker(int c, va_list ap);

int	ft_printf(const char *param, ...)
{
	va_list	my_arg;
	int		ret;

	ret = 0;
	va_start(my_arg, param);
	while (*param)
	{
		if (*param != '%')
			ret += ft_printf_putchar(*param);
		else
			ret += checker(*(param + 1), my_arg);
		param++;
	}
	va_end(my_arg);
	return (ret);
}

int	checker(int c, va_list ap)
{
	int	ret;

	ret = 0;
	if (c == 's')
		ret += ft_printf_putstr(va_arg(ap, char *));
	else if (c == 'c')
		ret += ft_printf_putchar(va_arg(ap, char));
	else if (c == 'p')
		ret += ft_printf_printPtr(va_arg(ap, unsigned long));
	else if (c == 'd' || c == 'i')
		ret += ft_printf_putnbr(va_arg(ap, int));
	else if (c == 'u')
		ret += ft_printf_unsigned(va_arg(ap, int));
	else if (c == 'x' || c == 'X')
	{
		if (c == 'x')
			ret += ft_printf_x(va_arg(ap, int));
		if (c == 'X')
			ret += ft_printf_X(va_arg(ap, int));
	}
	else if (c == '%')
		ret += ft_printf_putchar('%');
	else
		return (ft_printf_putchar(c));
	return (ret);
}

/* int	ft_printf(const char *param, ...)
{
	va_list	ap;
	int		a;
	int		ret;

	va_start(ap, param);
	a = 0;
	ret = 0;
	while (param[a] != NULL)
	{
		if (param[a] == '%')
		{
			a++;
			while ((param[a] == ' ' || param[a] == '\t') && param[a] != NULL)
				a++;
			ret += checker(param[a], ap);
		}
		else
			ret += write(1, &param[a], 1);
		a++;
	}
	va_end(ap);
	return (ret);
}
 */
