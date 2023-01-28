/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_point.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42.istanbul.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 21:21:38 by bkaramol          #+#    #+#             */
/*   Updated: 2022/11/14 21:39:18 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// pointer yazdıran fonksiyon
int	process_point(unsigned long long n)
{
	char	*base;
	int		len;

	len = 1;
	base = "0123456789abcdef";
	if (n > 15)
		len += process_point(n / 16);
	ft_print_char(base[n % 16]);
	return (len);
}

int	ft_print_point(unsigned long long n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (ft_print_string("0x0"));
	else
		len += ft_print_string("0x");
	len += process_point(n);
	return (len);
}
