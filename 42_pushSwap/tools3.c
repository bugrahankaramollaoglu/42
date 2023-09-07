/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 12:52:30 by bkaramol          #+#    #+#             */
/*   Updated: 2023/08/30 17:19:53 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void find_maxbit(t_s *data)
{
	int max;

	data->max_bit = 0;
	max = data->size_a - 1;
	while (max > 0)
	{
		data->max_bit++;
		max /= 2;
	}
}

int find_index(t_s *data, int nbr)
{
	int i;

	i = 0;
	while (i < data->len)
	{
		if (data->sorted[i] == nbr)
			return (i);
		i++;
	}
	return (0);
}

void radix(t_s *data)
{
	int i;
	int x;
	int alen;

	i = 0;
	alen = data->size_a;
	while (i < data->max_bit)
	{
		x = 0;
		while (x++ < alen)
		{
			if ((find_index(data, data->stack_a[0]) >> i & 1) == 1)
				ra(data);
			else
				pb(data);
		}
		while (data->size_b)
			pa(data);
		i++;
	}
}
