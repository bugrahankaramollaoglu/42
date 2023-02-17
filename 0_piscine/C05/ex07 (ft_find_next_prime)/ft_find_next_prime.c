/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 13:44:30 by bkaramol          #+#    #+#             */
/*   Updated: 2022/02/28 13:44:59 by bkaramol         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

/* verilen bir sayıdan sonraki ilk asal sayıyı bulmak için öncelikle asal kontrolü
yapan bir fonksiyon yazmamız gerekiyor. */

int	ft_is_prime(int nb)
{
	int	i;

	i = 2;
	if (nb < 2)
		return (0);
	while (i <= nb / i)
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	if (ft_is_prime(nb) == 1)
		return (nb);
	while (ft_is_prime(nb) != 1 && nb < 2147483647)
		nb++;
	return (nb);
}

/*
int	main(void) {
	printf("%d -> %d\n", 1, ft_find_next_prime(3));
}
*/
