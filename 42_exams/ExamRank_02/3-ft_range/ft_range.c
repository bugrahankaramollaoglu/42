/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 12:48:27 by bkaramol          #+#    #+#             */
/*   Updated: 2022/10/19 23:55:17 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

/* It must allocate (with malloc()) an array of integers, fill it with consecutive
values that begin at start and end at end (Including start and end !), then
return a pointer to the first value of the array.

Examples:

- With (1, 3) you will return an array containing 1, 2 and 3.
- With (-1, 2) you will return an array containing -1, 0, 1 and 2.
- With (0, 0) you will return an array containing 0.
- With (0, -3) you will return an array containing 0, -1, -2 and -3. */

int ft_abs(int nb)
{
	if (nb < 0)
		return (-nb);
	return nb;
}

int	*ft_range(int start, int end)
{
	int len = ft_abs(start - end) + 1;
	int *arr;
	arr = (int *)malloc(sizeof(int) * len);
	int a = 0;
	int i = 0;

	if (start == end)
	{
		arr[a] = start;
	}
	else if (start > end)
	{
		while (len)
		{
			arr[a] = start - i;
			a++;
			i++;
			len--;
		}
	}
	else if (start < end)
	{
		while (len)
		{
			arr[a] = start + i;
			a++;
			i++;
			len--;
		}
	}
	return arr;
}

#include <stdio.h>

int main() {
	int i = 0;
	int *arr = ft_range(4, 0);
	while (i < 5)
	{
		printf("%d ", arr[i]);
		i++;
	}
}
