/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: bkaramol <42istanbul.com.tr>               +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2022/02/10 21:36:12 by bkaramol          #+#    #+#             */
/*   Updated: 2022/02/14 13:19:38 by bkaramol         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>


void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_is_negative(int n)
{
	if (n < 0)
		// ft_putchar('N');
		write(1, &"N", 1);
	else
		ft_putchar('P');
	// write(1, &"P", 1);
}

int	main(void)
{
	ft_is_negative(-1);
	ft_is_negative(42);
	return (0);
}
