/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 10:55:48 by bkaramol          #+#    #+#             */
/*   Updated: 2022/02/28 11:00:20 by bkaramol         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		ft_putchar('-');
		nb *= -1;
	}
	if (nb > 9)
		ft_putnbr(nb / 10);
	/* +48 sebebi ascii'de inti chara çevirmek. mesela
	9 sayısı, 10 ile modu 9. sayı olan 9'u yazdıracagız fakat şuan
	9 putchar ile yazdırılamıyor. çünkü 9 ascii'de \t denk geliyor
	o da non-printable. buna 48 ('0') eklediğimizde 57 oluyor. o da sayı olan
	9'un karşılığı. */
	ft_putchar(nb % 10 + '0');
}
/*

int	main(void)
{
	ft_putnbr(-234234);
	return (0);
}

*/
