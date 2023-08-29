/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools0.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 12:52:01 by bkaramol          #+#    #+#             */
/*   Updated: 2023/04/28 00:28:05 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac, char **av)
{
	t_s *data;
	int i;

	if (ac >= 2)
	{
		data = malloc(sizeof(t_s));
		if (!data)
			return (0);
		stack_initializer(data);
		i = 2;
		data->ac_num = ac - 1;
		if (!av[i])
			error_exit(data);
		data->str = av[1];
		while (i <= data->ac_num)
		{
			gather_arguments(data, av[i]);
			i++;
		}
		av_checker(data);
		bubble_sort(data->sorted, data->size_a);
		sort(data);
		free_all(data);
	}
}
