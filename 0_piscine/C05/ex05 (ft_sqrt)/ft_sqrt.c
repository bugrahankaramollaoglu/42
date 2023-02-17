/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 16:12:03 by bkaramol          #+#    #+#             */
/*   Updated: 2022/02/28 13:40:58 by bkaramol         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int ft_sqrt(int nb)
{
	int a;

	a = 1;
	while (a * a <= nb && nb > 0)
	{
		if (a * a == nb)
			return (a);
		/* çünkü bunun karesi INT_MAX'ı aşıyor */
		else if (a >= 46341)
			return (0);
		a++;
	}
	return (0);
}

/*
int	main(void)
{
	printf("%d", ft_sqrt(256));
}
*/
