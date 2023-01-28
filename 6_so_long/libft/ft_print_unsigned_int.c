/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned_int.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42.istanbul.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 21:22:19 by bkaramol          #+#    #+#             */
/*   Updated: 2022/11/14 21:39:16 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_unsigned_int(unsigned int n)
{
	int	len;

	len = 1;
	if (n > 9)
		len += ft_print_unsigned_int(n / 10);
	ft_print_char(n % 10 + '0');
	return (len);
}
