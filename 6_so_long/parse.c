/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42.istanbul.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 21:31:16 by bkaramol          #+#    #+#             */
/*   Updated: 2022/11/16 14:24:19 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_check_struct(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (game->map[i] != NULL)
		i++;
	game->height_map = i;
	game->width_map = ft_strlen(game->map[0]);
	while (i > 0)
	{
		if (game->width_map != ft_strlen(game->map[j]))
			map_struct_error(game);
		i--;
		j++;
	}
}

void	check_borders(t_game *game)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (game->map[0][i])
	{
		if (game->map[0][i] != '1' || game->map[game->height_map - 1][i] != '1')
			map_border_error(game);
		i++;
	}
	while (game->map[j])
	{
		if (game->map[j][0] != '1' || game->map[j][game->width_map - 1] != '1')
			map_border_error(game);
		j++;
	}
}

void	check_comps(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] != '1' && game->map[i][j] != '0' &&
				game->map[i][j] != 'C' && game->map[i][j] != 'E' &&
				game->map[i][j] != 'P')
				map_comps_error(game);
			j++;
		}
		i++;
	}
}

void	count_comps(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'E')
				game->exit++;
			else if (game->map[i][j] == 'C')
				game->col++;
			else if (game->map[i][j] == 'P')
				game->player++;
			j++;
		}
		i++;
	}
	if (game->exit != 1 || game->col < 1 || game->player != 1)
		map_comps_error(game);
}

/* void valid_map(t_game *game)
{
	
} */

int	parse(char *file, t_game *game)
{
	char	*str;
	char	*tmp;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (-1);
	str = NULL;
	tmp = get_next_line(fd);
	line_check1(tmp, fd, game);
	while (tmp)
	{
		str = ft_strjoin_gnl(str, tmp);
		free(tmp);
		tmp = get_next_line(fd);
		line_check2(tmp, fd, str, game);
	}
	if (!str)
		return (-1);
	if (str[ft_strlen(str) - 1] == '\n')
		map_empty_line_error(game, str, tmp);
	game->map = ft_split(str, '\n');
	free_arrays(str, tmp);
	return (fd);
	close(fd);
}
