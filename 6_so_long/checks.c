/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42.istanbul.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 21:30:02 by bkaramol          #+#    #+#             */
/*   Updated: 2022/11/16 01:15:24 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	line_check1(char *tmp, int fd, t_game *game)
{
	if (!tmp || tmp[0] != '1')
	{
		free(game);
		close(fd);
		perror("ERROR:\n it should have been 1\n");
		exit(EXIT_FAILURE);
	}
}

void	line_check2(char *tmp, int fd, char *str, t_game *game)
{
	if (tmp != NULL && tmp[0] != '1')
	{
		free_all(game, str, tmp);
		close(fd);
		perror("ERROR:\n it should have been 1\n");
		exit(EXIT_FAILURE);
	}
}

void	map_check(t_game *game)
{
	map_check_struct(game);
	check_borders(game);
	check_comps(game);
	count_comps(game);
}

void	extension_check(char *thing, t_game *game)
{
	int	i;

	i = ft_strlen(thing) - 4;
	if (thing[i] == '.' && thing[i + 1] == 'b' && thing[i + 2] == 'e'
		&& thing[i + 3] == 'r')
	{
		if (parse(thing, game) == -1)
			parse_error(game);
		map_check(game);
	}
	else
		file_error(game);
}
