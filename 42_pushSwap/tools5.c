/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 03:24:26 by bkaramol          #+#    #+#             */
/*   Updated: 2023/04/28 00:25:35 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	gather_arguments(t_s *data, char *s)
{
	char		*buffer;
	static int	i;

	i = 0;
	if (!s)
		error_exit(data);
	buffer = ft_strjoin(data->str, s);
	while (buffer[i])
	{
		data->str[i] = buffer[i];
		i++;
	}
	free(buffer);
}

void	num_checker(t_s *data)
{
	int	i;

	i = 0;
	while (data->str[i])
	{
		if ((data->str[i] == '+' || data->str[i] == '-') && (data->str[i
					+ 1] == '+' || data->str[i + 1] == '-'))
			error_exit(data);
		if ((data->str[i] == '+' || data->str[i] == '-') && (data->str[i
					+ 1] == '\0' || data->str[i + 1] == ' ' || data->str[i
					+ 1] == '\t'))
			error_exit(data);
		if ((data->str[i] >= '0' && data->str[i] <= '9') && (data->str[i
					+ 1] == '+' || data->str[i + 1] == '-'))
			error_exit(data);
		if ((data->str[i] == ' ' || data->str[i] == '\t') && (data->str[i
					+ 1] == '0') && (data->str[i + 2] >= '0' && data->str[i
					+ 2] <= '9'))
			error_exit(data);
		i++;
	}
}

void	num_checker2(t_s *data)
{
	int	i;

	i = 0;
	while (data->str[i])
	{
		if (!((data->str[i] >= '0' && data->str[i] <= '9')
				|| (data->str[i] == ' ' || data->str[i] == '+'
					|| data->str[i] == '-')))
			error_exit(data);
		if (data->str[0] == '0' && (data->str[1] >= '0' && data->str[1] <= '9'))
			error_exit(data);
		i++;
	}
}

void	recurrent_nums(t_s *data)
{
	int	i;
	int	i2;

	i = 0;
	i2 = 0;
	while (i < data->size_a - 1)
	{
		i2 = i + 1;
		while (i2 < data->size_a)
		{
			if (data->stack_a[i] == data->stack_a[i2])
			{
				error_exit(data);
			}
			i2++;
		}
		i++;
	}
}

void	fill_stacks(t_s *data)
{
	int	i;
	int	i2;
	int	num_of_nums;

	i = 0;
	i2 = 0;
	while (data->numbers[i2])
		i2++;
	data->ac_num = i2;
	num_of_nums = word_counter(data->str, ' ');
	data->size_a = num_of_nums;
	data->ac_num = num_of_nums;
	data->size_b = 0;
	data->stack_a = malloc(sizeof(int) * num_of_nums);
	data->stack_b = malloc(sizeof(int) * num_of_nums);
	data->sorted = malloc(sizeof(int) * num_of_nums);
	data->len = data->size_a;
	while (i < num_of_nums)
	{
		data->stack_a[i] = ft_atoi(data->numbers[i], data);
		data->sorted[i] = data->stack_a[i];
		i++;
	}
}
