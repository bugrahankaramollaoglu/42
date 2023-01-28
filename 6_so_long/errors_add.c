/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42.istanbul.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 21:30:33 by bkaramol          #+#    #+#             */
/*   Updated: 2022/11/14 21:30:34 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	parse_error(t_game *game)
{
	free(game);
	perror("ERROR:\nmap is erroneous!!\n");
	exit(EXIT_FAILURE);
}

void	file_error(t_game *game)
{
	free(game);
	perror("ERROR:\nit should have end with .ber extension\n");
	exit(EXIT_FAILURE);
}

void	window_mlx_error(t_game *game)
{
	free_struct(game);
	perror("ERROR:\nmlx could not have opened window\n");
	exit(EXIT_FAILURE);
}

void	params_number_error(void)
{
	perror("ERROR:\nyou should have given <./so_long map.ber> (2 parameters)\n");
	exit(EXIT_FAILURE);
}
