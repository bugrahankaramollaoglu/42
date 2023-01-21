/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 13:21:29 by bkaramol          #+#    #+#             */
/*   Updated: 2022/02/28 13:36:58 by bkaramol         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int	ft_iterative_factorial(int nb)
{
	int	factorial;
	int	a;

	factorial = 1;
	a = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
		return (0);
	while (a++ < nb)
		factorial *= a;
	return (factorial);
}

/*
int	main(void)
{
	int b;
	b = ft_iterative_factorial(5);
	printf("%d", b);
}

*/
