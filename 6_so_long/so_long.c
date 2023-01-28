/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42.istanbul.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 21:31:20 by bkaramol          #+#    #+#             */
/*   Updated: 2022/11/16 01:34:50 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "so_long.h"

void	init_all(t_game *game)
{
	game->map = NULL;
	game->player = 0;
	game->p_x = 0;
	game->p_y = 0;
	game->col = 0;
	game->steps = 0;
	game->exit = 0;
	game->width_map = 0;
	game->height_map = 0;
}

void	window_init(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		window_mlx_error(game);
	game->mlx_w = mlx_new_window(game->mlx, game->width_map * 64,
			game->height_map * 64, "aun aprendo");
	if (!game->mlx_w)
		window_mlx_error(game);
}
int	main(int ac, char **av)
{
	t_game	*game;

	if (ac == 2)
	{
		game = malloc(sizeof(t_game));
		if (!game)
			return (0);
		init_all(game);
		extension_check(av[1], game);
		window_init(game);
		create_map(game);
		mlx_hook(game->mlx_w, 2, 1L << 0, move, game);
		mlx_hook(game->mlx_w, 17, 1L << 17, exit_game, game);
		mlx_loop(game->mlx);
	}
	else
		params_number_error();
	return (0);
}
