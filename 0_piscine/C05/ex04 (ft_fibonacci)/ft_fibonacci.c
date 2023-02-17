/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 16:08:35 by bkaramol          #+#    #+#             */
/*   Updated: 2022/02/28 13:40:05 by bkaramol         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

/* fibonacci formülünü bilmek gerekiyor: fibo = (n-2) + (n-1) */
int	ft_fibonacci(int index)
{
	if (index < 0)
		return (-1);
	if (index < 2)
		return (index);
	return (ft_fibonacci(index - 2) + ft_fibonacci(index - 1));
}

/*
int	main(void)
{
	printf("%d", ft_fibonacci(0));
	printf("%d", ft_fibonacci(1));
	printf("%d", ft_fibonacci(2));
	printf("%d", ft_fibonacci(3));
	printf("%d", ft_fibonacci(4));
	printf("%d", ft_fibonacci(5));
	printf("%d", ft_fibonacci(6));
	printf("%d", ft_fibonacci(7));
	printf("%d", ft_fibonacci(8));
}
*/
