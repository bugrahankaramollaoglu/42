/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42.istanbul.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 21:31:08 by bkaramol          #+#    #+#             */
/*   Updated: 2022/11/14 21:31:08 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_all(t_game *game, char *str, char *tmp)
{
	free(game);
	free(str);
	free(tmp);
}

void	free_arrays(char *str, char *tmp)
{
	free(str);
	free(tmp);
}

void	free_struct(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[i])
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
	free(game);
}
