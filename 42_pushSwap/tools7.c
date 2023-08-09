/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools7.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 15:43:45 by bkaramol          #+#    #+#             */
/*   Updated: 2023/01/14 15:48:33 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	already_sorted(t_s *data)
{
	int	i;
	int	i2;

	i = 0;
	i2 = 1;
	while (i + 1 < data->size_a)
	{
		if (data->stack_a[i] < data->stack_a[i + 1])
			i2++;
		i++;
	}
	if (i2 == data->size_a)
	{
		exit(1);
	}
}

static int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	ft_atoi(const char *str, t_s *data)
{
	int		i;
	int		sign;
	long	number;

	sign = 1;
	number = 0;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		number = (number * 10) + (str[i] - 48) * sign;
		if (number > 2147483647)
			error_exit(data);
		if (number < -2147483648)
			error_exit(data);
		i++;
	}
	return (number);
}

size_t	ft_strlen(const char *s)
{
	size_t	a;

	a = 0;
	while (s[a])
		a++;
	return (a);
}

void	av_checker(t_s *data)
{
	num_checker(data);
	num_checker2(data);
	data->numbers = ft_split(data->str, ' ');
	fill_stacks(data);
	recurrent_nums(data);
	already_sorted(data);
}
