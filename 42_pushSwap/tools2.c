/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 17:50:10 by bkaramol          #+#    #+#             */
/*   Updated: 2023/01/14 16:11:42 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_s *data)
{
	int	temp;

	if (data->size_a >= 2)
	{
		temp = data->stack_a[0];
		data->stack_a[0] = data->stack_a[1];
		data->stack_a[1] = temp;
		write(1, "sa\n", 3);
	}
}

void	sb(t_s *data)
{
	int	temp;

	if (data->size_b >= 2)
	{
		temp = data->stack_b[0];
		data->stack_b[0] = data->stack_b[1];
		data->stack_b[1] = temp;
		write(1, "sb\n", 3);
	}
}

void	ss(t_s *data)
{
	int	temp;

	if (data->size_a >= 2 && data->size_b >= 2)
	{
		temp = data->stack_a[0];
		data->stack_a[0] = data->stack_a[1];
		data->stack_a[1] = temp;
		temp = data->stack_b[0];
		data->stack_b[0] = data->stack_b[1];
		data->stack_b[1] = temp;
		write(1, "ss\n", 3);
	}
}

void	ra(t_s *data)
{
	int	i;
	int	temp;

	if (data->size_a >= 2)
	{
		i = 0;
		temp = data->stack_a[0];
		while (i < data->size_a - 1)
		{
			data->stack_a[i] = data->stack_a[i + 1];
			i++;
		}
		data->stack_a[i] = temp;
		write(1, "ra\n", 3);
	}
}

void	rb(t_s *data)
{
	int	i;
	int	temp;

	if (data->size_b >= 2)
	{
		i = 0;
		temp = data->stack_b[0];
		while (i < data->size_b - 1)
		{
			data->stack_b[i] = data->stack_b[i + 1];
			i++;
		}
		data->stack_b[i] = temp;
		write(1, "rb\n", 3);
	}
}
