/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 16:44:35 by bkaramol          #+#    #+#             */
/*   Updated: 2022/02/28 13:43:37 by bkaramol         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int ft_is_prime(int nb)
{
	int i;

	i = 2;
	if (nb < 2)
		return (0);
	/* /2 diyoruz çünkü bir sayının yarısından kendisine kadar olan yarımda bir tam sayı
	çarpanı olamaz. */
	while (i <= nb / 2)
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}

/*
int	main(void)
{
	printf("%d", ft_is_prime(0));
	printf("%d", ft_is_prime(2));
	printf("%d", ft_is_prime(-1));
}
*/
