/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42.istanbul.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 21:30:39 by bkaramol          #+#    #+#             */
/*   Updated: 2022/11/14 21:30:39 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_struct_error(t_game *game)
{
	free_struct(game);
	perror("ERROR:\nit should be rectangular\n");
	exit(EXIT_FAILURE);
}

void	map_border_error(t_game *game)
{
	free_struct(game);
	perror("ERROR:\nyour map must be surrounded by 1s\n");
	exit(EXIT_FAILURE);
}

void	map_comps_error(t_game *game)
{
	free_struct(game);
	perror("ERROR:\nit can only consist of 10CEP or numbers not correct\n");
	exit(EXIT_FAILURE);
}

void	map_empty_line_error(t_game *game, char *str, char *temp)
{
	free_all(game, str, temp);
	perror("ERROR:\nmap cannot have empty lines\n");
	exit(EXIT_FAILURE);
}
