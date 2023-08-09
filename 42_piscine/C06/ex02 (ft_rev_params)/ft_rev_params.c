/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 13:54:09 by bkaramol          #+#    #+#             */
/*   Updated: 2022/02/28 15:45:15 by bkaramol         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc > 1)
	{
		while (argc > 1)
		{
			while (argv[argc - 1][i])
			{
				write(1, &argv[argc - 1][i], 1);
				i++;
			}
			i = 0;
			argc--;
			write(1, "\n", 1);
		}
	}
	return (0);
}
