/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 12:52:18 by bkaramol          #+#    #+#             */
/*   Updated: 2023/01/14 15:39:48 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_initializer(t_s *data)
{
	data->size_a = 0;
	data->size_b = 0;
	data->stack_a = 0;
	data->stack_b = 0;
	data->sorted = 0;
	data->str = 0;
	data->numbers = 0;
	data->ac_num = 0;
	data->max_bit = 0;
	data->step = 0;
}

void	error_exit(t_s *data)
{
	write(2, "Error\n", 6);
	free_all(data);
	exit(1);
}

void	free_all(t_s *data)
{
	int	i;

	i = 0;
	if (data->stack_a)
		free(data->stack_a);
	if (data->stack_b)
		free(data->stack_b);
	if (data->sorted)
		free(data->sorted);
	if (data->numbers)
	{
		while (data->numbers[i])
		{
			free(data->numbers[i]);
			i++;
		}
		free(data->numbers);
	}
	free(data);
}
