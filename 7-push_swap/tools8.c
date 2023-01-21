/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools8.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 16:10:49 by bkaramol          #+#    #+#             */
/*   Updated: 2023/01/14 16:12:39 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr(t_s *data)
{
	int	i;
	int	temp;

	if (data->size_a >= 2 && data->size_b >= 2)
	{
		i = 0;
		temp = data->stack_a[0];
		while (i < data->size_a - 1)
		{
			data->stack_a[i] = data->stack_a[i + 1];
			i++;
		}
		data->stack_a[i] = temp;
		i = 0;
		temp = data->stack_b[0];
		while (i < data->size_b - 1)
		{
			data->stack_b[i] = data->stack_b[i + 1];
			i++;
		}
		data->stack_b[i] = temp;
		write(1, "rr\n", 3);
	}
}

void	rra(t_s *data)
{
	int	i;
	int	temp;
	int	len;

	if (data->size_a >= 2)
	{
		i = 0;
		temp = data->stack_a[data->size_a - 1];
		len = data->size_a - 1;
		while (i < len - 1)
		{
			data->stack_a[len] = data->stack_a[len - 1];
			i++;
			len--;
		}
		data->stack_a[0] = temp;
		write(1, "rra\n", 4);
	}
}

void	rrb(t_s *data)
{
	int	i;
	int	temp;
	int	len;

	if (data->size_b >= 2)
	{
		i = 0;
		temp = data->stack_b[data->size_b - 1];
		len = data->size_b - 1;
		while (i < len - 1)
		{
			data->stack_b[len] = data->stack_b[len - 1];
			i++;
			len--;
		}
		data->stack_b[0] = temp;
		write(1, "rrb\n", 4);
	}
}

void	rrr(t_s *data)
{
	int	i;
	int	temp;
	int	len;

	if (data->size_a >= 2 && data->size_b >= 2)
	{
		i = 0;
		temp = data->stack_a[data->size_a - 1];
		len = data->size_a - 1;
		while (i < len - 1)
		{
			data->stack_a[len] = data->stack_a[len - 1];
			i++;
			len--;
		}
		data->stack_a[0] = temp;
		i = 0;
		temp = data->stack_b[data->size_b - 1];
		len = data->size_b - 1;
		while (i++ < len-- - 1)
			data->stack_b[len] = data->stack_b[len - 1];
		data->stack_b[0] = temp;
		write(1, "rrr\n", 4);
	}
}
