/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 19:05:53 by ikayacio          #+#    #+#             */
/*   Updated: 2023/10/29 15:49:30 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move(t_map *Map, double x, double y)
{
	Map->player.pos_x = x;
	Map->player.pos_y = y;
	render_map(Map);
}

void	img_init2(void *img, int color, int y, int x)
{
	int		pixel_bits;
	int		line_bytes;
	int		endian;
	char	*buffer;
	int		pixel;

	buffer = mlx_get_data_addr(img, &pixel_bits, &line_bytes, &endian);
	while (y < WINDOW_HEIGHT / 2)
	{
		x = 0;
		while (x < WINDOW_WIDTH)
		{
			pixel = (y * line_bytes) + (x * 4);
			buffer[pixel + 0] = (color >> 0) & 0xFF;
			buffer[pixel + 1] = (color >> 8) & 0xFF;
			buffer[pixel + 2] = (color >> 16) & 0xFF;
			buffer[pixel + 3] = (color >> 24) & 0xFF;
			x++;
		}
		y++;
	}
}

void	img_init(t_map *data, int i)
{
	data->f_col = find_color(data->f, -1);
	data->c_col = find_color(data->c, -1);
	data->f_img = mlx_new_image(data->window.mlx_ptr,
			WINDOW_WIDTH, WINDOW_HEIGHT);
	data->c_img = mlx_new_image(data->window.mlx_ptr,
			WINDOW_WIDTH, WINDOW_HEIGHT);

	img_init2(data->c_img, data->c_col, 0, 0);
	img_init2(data->f_img, data->f_col, 0, 0);
	data->images[0].img = mlx_xpm_file_to_image(data->window.mlx_ptr, data->no,
			&data->images[0].width, &data->images[0].height);
	data->images[1].img = mlx_xpm_file_to_image(data->window.mlx_ptr, data->so,
			&data->images[1].width, &data->images[1].height);
	data->images[2].img = mlx_xpm_file_to_image(data->window.mlx_ptr, data->we,
			&data->images[2].width, &data->images[2].height);
	data->images[3].img = mlx_xpm_file_to_image(data->window.mlx_ptr, data->ea,
			&data->images[3].width, &data->images[3].height);
	while (++i < 4)
		data->images[i].addr = mlx_get_data_addr(data->images[i].img,
				&data->images[i].bpp, &data->images[i].line_len,
				&data->images[i].endian);
	render_map(data);
	mlx_key_hook(data->window.win_ptr, &handle_input, data);
	mlx_loop_hook(data->window.mlx_ptr, &handle_no_event, data);
	mlx_loop(data->window.mlx_ptr);
}

void	img_delete(t_map *data)
{
	if (!data)
		return ;
	if (data->c_img)
		mlx_destroy_image(data->window.mlx_ptr, data->c_img);
	if (data->f_img)
		mlx_destroy_image(data->window.mlx_ptr, data->f_img);
	if (data->images[0].img)
		mlx_destroy_image(data->window.mlx_ptr, data->images[0].img);
	if (data->images[1].img)
		mlx_destroy_image(data->window.mlx_ptr, data->images[1].img);
	if (data->images[2].img)
		mlx_destroy_image(data->window.mlx_ptr, data->images[2].img);
	if (data->images[3].img)
		mlx_destroy_image(data->window.mlx_ptr, data->images[3].img);
}

void	check_move(t_map *Map, int keycode)
{
	double	nw_x;
	double	nw_y;

	nw_x = Map->player.pos_x + Map->player.dir_y * MOVE_SPEED;
	nw_y = Map->player.pos_y - Map->player.dir_x * MOVE_SPEED;
	if (keycode == S || keycode == W)
	{
		nw_x = Map->player.pos_x - Map->player.dir_x * MOVE_SPEED;
		nw_y = Map->player.pos_y - Map->player.dir_y * MOVE_SPEED;
		if (keycode == W)
		{
			nw_x = Map->player.pos_x + Map->player.dir_x * MOVE_SPEED;
			nw_y = Map->player.pos_y + Map->player.dir_y * MOVE_SPEED;
		}
	}
	else if ((keycode == A && Map->start_dir == 'W')
		|| (keycode == D && Map->start_dir != 'W'))
	{
		nw_x = Map->player.pos_x - Map->player.dir_y * MOVE_SPEED;
		nw_y = Map->player.pos_y + Map->player.dir_x * MOVE_SPEED;
	}
	if (nw_x >= 0 && nw_x < WINDOW_WIDTH && nw_y >= 0 && nw_y < WINDOW_HEIGHT)
		if (Map->map[(int)nw_y][(int)nw_x] &&
			Map->map[(int)nw_y][(int)nw_x] != '1')
			move(Map, nw_x, nw_y);
}
