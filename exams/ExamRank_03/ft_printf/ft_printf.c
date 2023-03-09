/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 05:55:01 by bkaramol          #+#    #+#             */
/*   Updated: 2023/03/09 16:41:45 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		str = "(null)";
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}

int	ft_putnbr(unsigned int nb, int base)
{
	int		i;
	char	*base_set;
	int		count;

	i = nb % base;
	base_set = "0123456789abcdef";
	count = 0;
	if (nb / base > 0)
		count += ft_putnbr(nb / base, base);
	count += ft_putchar(base_set[i]);
	return (count);
}

int	print_d(int nb)
{
	int	count;

	count = 0;
	if (nb < 0)
	{
		count += ft_putchar('-');
		if (nb == -2147483648)
		{
			count += ft_putstr("2147483648");
			return (count);
		}
		nb = -nb;
	}
	count += ft_putnbr((unsigned int)nb, 10);
	return (count);
}

int	ft_printf(char *str, ...)
{
	va_list	ap;
	int		count;
	int		i;

	count = 0;
	i = 0;
	va_start(ap, str);
	if (str == NULL)
		return (0);
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (str[i + 1] == 'd')
				count += print_d(va_arg(ap, int));
			else if (str[i + 1] == 'x')
				count += ft_putnbr(va_arg(ap, unsigned int), 16);
			else if (str[i + 1] == 's')
				count += ft_putstr(va_arg(ap, char *));
			i++;
		}
		else
			count += ft_putchar(str[i]);
		i++;
	}
	va_end(ap);
	return (count);
}

#include <stdio.h>

int	main(void)
{
	ft_printf("%x\n", 123);
	ft_printf("%d\n", -23423);
	ft_printf("%d\n", -5000);
	ft_printf("%s\n", "auhsjhagkjhsdkjvxk-lpşorpkter0kpg243*05349+");
	ft_printf("%%");
}
