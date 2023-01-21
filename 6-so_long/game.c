/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42.istanbul.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 21:30:46 by bkaramol          #+#    #+#             */
/*   Updated: 2022/11/16 01:42:06 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	create_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'P')
			{
				game->p_x = x;
				game->p_y = y;
			}
			send_to_print(game, x, y);
			x++;
		}
		y++;
	}
}

void	send_to_print(t_game *game, int x, int y)
{
	if (game->map[y][x] == 'P')
	{
		print_image(game, GROUND, x, y);
		print_image(game, PLAYER1, x, y);
	}
	else if (game->map[y][x] == '0')
		print_image(game, GROUND, x, y);
	else if (game->map[y][x] == '1')
		print_image(game, GRAY, x, y);
	else if (game->map[y][x] == 'C')
	{
		print_image(game, GROUND, x, y);
		print_image(game, APPLE, x, y);
	}
	else if (game->map[y][x] == 'E')
		print_image(game, EXIT, x, y);
}

void	print_image(t_game *game, char *path, int x, int y)
{
	int	size;
	int	i;
	int	j;

	size = 64;
	i = y * size;
	j = x * size;
	game->img = mlx_xpm_file_to_image(game->mlx, path, &size, &size);
	mlx_put_image_to_window(game->mlx, game->mlx_w, game->img, j, i);
	mlx_destroy_image(game->mlx, game->img);
}

int	exit_game(t_game *game)
{
	mlx_clear_window(game->mlx, game->mlx_w);
	mlx_destroy_window(game->mlx, game->mlx_w);
	free_struct(game);
	exit(0);
}
