/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42.istanbul.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 21:22:07 by bkaramol          #+#    #+#             */
/*   Updated: 2022/11/14 21:39:21 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_int(int n)
{
	int	len;

	len = 1;
	if (n == -2147483648)
		return (ft_print_string("-2147483648"));
	if (n < 0)
	{
		ft_print_char('-');
		len++;
		n = -n;
	}
	if (n > 9)
		len += ft_print_int(n / 10);
	ft_print_char(n % 10 + '0');
	return (len);
}
