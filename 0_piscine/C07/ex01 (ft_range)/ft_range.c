/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 17:03:46 by bkaramol          #+#    #+#             */
/*   Updated: 2023/01/18 17:13:07 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	size;
	int	*arr;
	int	*n;
	int	i;

	size = max - min;
	arr = malloc(sizeof(int) * size);
	if (!arr)
		return (0);
	if (min >= max)
		return (NULL);
	else
	{
		while (size--)
			arr[i++] = min++;
		return (arr);
	}
}
#include <stdio.h>

int	main(void)
{
	int	*arr;

	arr = malloc(sizeof(int) * 10);
	arr = ft_range(3, 7);
	for (int i = 0; i < 10; i++)
	{
		printf("[%d]", arr[i]);
	}
}
