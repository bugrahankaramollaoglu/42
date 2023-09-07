/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 18:18:24 by bkaramol          #+#    #+#             */
/*   Updated: 2023/08/15 00:38:42 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bubble_sort(int *arr, unsigned int size)
{
	int	i;
	int	i2;
	int	tmp;

	i = 0;
	i2 = 0;
	while (i < size - 1)
	{
		while (i2 < size - 1)
		{
			if (arr[i2] > arr[i2 + 1])
			{
				tmp = arr[i2];
				arr[i2] = arr[i2 + 1];
				arr[i2 + 1] = tmp;
			}
			i2++;
		}
		i2 = 0;
		i++;
	}
}

int	word_counter(char *s, char c)
{
	int	counter;

	counter = 0;
	while (*s)
	{
		if (*s != c && (s[1] == '\0' || s[1] == c))
			counter++;
		s++;
	}
	return (counter);
}

void	sort_3(t_s *data)
{
	if ((data->stack_a[0] > data->stack_a[2])
		&& (data->stack_a[2] > data->stack_a[1]))
	{
		rra(data);
		rra(data);
	}
	else if ((data->stack_a[1] > data->stack_a[2])
		&& (data->stack_a[2] > data->stack_a[0]))
	{
		rra(data);
		sa(data);
	}
	else if ((data->stack_a[1] > data->stack_a[0])
		&& (data->stack_a[0] > data->stack_a[2]))
		rra(data);
	else if ((data->stack_a[2] > data->stack_a[0])
		&& (data->stack_a[0] > data->stack_a[1]))
		sa(data);
	else if ((data->stack_a[0] > data->stack_a[1])
		&& (data->stack_a[1] > data->stack_a[2]))
	{
		ra(data);
		sa(data);
	}
}

void	sort_5(t_s *data)
{
	while (data->sorted[2] <= data->stack_a[0])
		ra(data);
	if (data->sorted[2] > data->stack_a[0])
		pb(data);
	while (data->sorted[2] <= data->stack_a[0])
		ra(data);
	if (data->sorted[2] > data->stack_a[0])
		pb(data);
	sort_3(data);
	if (data->stack_b[1] > data->stack_b[0])
		sb(data);
	pa(data);
	pa(data);
}

void	sort(t_s *data)
{
	if (data->ac_num == 2)
	{
		sa(data);
	}
	else if (data->ac_num == 3)
		sort_3(data);
	else if (data->ac_num == 5)
		sort_5(data);
	else if (data->ac_num == 4 || data->ac_num >= 6)
	{
		find_maxbit(data);
		radix(data);
	}
	else
	{
		free_all(data);
	}
}
