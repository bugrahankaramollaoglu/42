/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools9.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 16:11:09 by bkaramol          #+#    #+#             */
/*   Updated: 2023/01/14 16:11:14 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*decrease_indice(int *arr, int size)
{
	int	i;

	i = size - 1;
	while (i)
	{
		arr[i] = arr[i - 1];
		i--;
	}
	return (arr);
}

int	*increase_indice(int *arr, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		arr[i] = arr[i + 1];
		i++;
	}
	return (arr);
}

void	pa(t_s *data)
{
	int	i;

	i = 0;
	if (data->size_b)
	{
		data->size_a++;
		data->stack_a = decrease_indice(data->stack_a, data->size_a);
		data->stack_a[0] = data->stack_b[0];
		data->size_b--;
		data->stack_b = increase_indice(data->stack_b, data->size_b);
		write(1, "pa\n", 3);
	}
}

void	pb(t_s *data)
{
	if (data->size_a > 0)
	{
		data->size_b++;
		data->stack_b = decrease_indice(data->stack_b, data->size_b);
		data->stack_b[0] = data->stack_a[0];
		data->size_a--;
		data->stack_a = increase_indice(data->stack_a, data->size_a);
		write(1, "pb\n", 3);
	}
}
