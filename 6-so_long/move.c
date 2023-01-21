/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42.istanbul.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 21:31:11 by bkaramol          #+#    #+#             */
/*   Updated: 2022/11/14 21:32:56 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move_check(int x, int y, t_game *game)
{
	if (game->map[game->p_y + y][game->p_x + x] == '1')
		return (1);
	if (game->map[game->p_y + y][game->p_x + x] == 'E' && game->col != 0)
		return (1);
	if (game->map[game->p_y + y][game->p_x + x] == 'E' && game->col == 0)
	{
		game->p_x += x;
		game->p_y += y;
		game->steps++;
		ft_printf("your counter of moves: %d\n", game->steps);
		free_struct(game);
		exit(0);
	}
	if (game->map[game->p_y + y][game->p_x + x] == 'C')
	{
		print_image(game, GROUND, game->p_x + x, game->p_y + y);
		game->col--;
		game->map[game->p_y + y][game->p_x + x] = '0';
		return (0);
	}
	return (0);
}

int	do_move(int x, int y, t_game *game)
{
	if (move_check(x, y, game) == 1)
		return (1);
	print_image(game, GROUND, game->p_x, game->p_y);
	if (game->steps % 2 == 0)
		print_image(game, PLAYER2, game->p_x + x, game->p_y + y);
	else
		print_image(game, PLAYER1, game->p_x + x, game->p_y + y);
	game->p_x += x;
	game->p_y += y;
	game->steps++;
	ft_printf("your counter of moves: %d\n", game->steps);
	return (0);
}

int	move(int key, t_game *game)
{
	if (key == 53)
		exit_game(game);
	else if (key == 13)
		do_move(0, -1, game);
	else if (key == 0)
		do_move(-1, 0, game);
	else if (key == 2)
		do_move(1, 0, game);
	else if (key == 1)
		do_move(0, 1, game);
	return (0);
}
