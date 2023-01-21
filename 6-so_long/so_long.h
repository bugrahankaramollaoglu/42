/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42.istanbul.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 21:31:24 by bkaramol          #+#    #+#             */
/*   Updated: 2022/11/14 21:35:26 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./libft/libft.h"
# include "./mlx/mlx.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define PLAYER1 "./img/player1.xpm"
# define PLAYER2 "./img/player2.xpm"
# define APPLE "./img/apple.xpm"
# define EXIT "./img/exit.xpm"
# define GRAY "./img/gray.xpm"
# define GROUND "./img/ground.xpm"

typedef struct s_game
{
	char	**map;
	int		p_x;
	int		p_y;
	int		col;
	int		player;
	int		steps;
	int		exit;
	void	*mlx;
	void	*mlx_w;
	void	*img;
	int		width_map;
	int		height_map;
}			t_game;

void		init_all(t_game *game);
void		window_init(t_game *game);
int			parse(char *file, t_game *game);
void		map_check(t_game *game);
void		extension_check(char *file, t_game *game);
void		map_check_struct(t_game *game);
void		check_borders(t_game *game);
void		check_comps(t_game *game);
void		count_comps(t_game *game);
int			exit_game(t_game *game);
int			move(int key, t_game *game);
void		create_map(t_game *game);
void		send_to_print(t_game *game, int x, int y);
void		print_image(t_game *game, char *path, int x, int y);
int			move_check(int x, int y, t_game *game);
void		line_check1(char *tmp, int fd, t_game *game);
void		line_check2(char *tmp, int fd, char *str, t_game *game);
void		parse_error(t_game *game);
void		file_error(t_game *game);
void		map_struct_error(t_game *game);
void		map_border_error(t_game *game);
void		map_comps_error(t_game *game);
void		map_empty_line_error(t_game *game, char *str, char *temp);
void		window_mlx_error(t_game *game);
void		params_number_error(void);
void		free_all(t_game *game, char *str, char *temp);
void		free_arrays(char *str, char *temp);
void		free_struct(t_game *game);

#endif