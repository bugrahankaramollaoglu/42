/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windows_hooks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 10:51:50 by ikayacio          #+#    #+#             */
/*   Updated: 2023/11/10 18:33:23 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	close_program(t_map *Map)
{
	mlx_destroy_window(Map->window.mlx_ptr, Map->window.win_ptr);
	free_map(Map);
	exit(EXIT_SUCCESS);
}

int	render_map(t_map *Map)
{
	int	x;

	mlx_put_image_to_window(Map->window.mlx_ptr,
		Map->window.win_ptr, Map->c_img, 0, 0);
	mlx_put_image_to_window(Map->window.mlx_ptr, Map->window.win_ptr,
		Map->f_img, 0, WINDOW_HEIGHT / 2);
	x = -1;
	while (++x < WINDOW_WIDTH)
		cast_ray(Map, x);
	return (0);
}

int	handle_release(int keycode, t_map *M)
{
	if (keycode == W)
		M->flags.w_flag = 0;
	if (keycode == A)
		M->flags.a_flag = 0;
	if (keycode == S)
		M->flags.s_flag = 0;
	if (keycode == D)
		M->flags.d_flag = 0;
	if (keycode == RIGHT_ARR)
		M->flags.r_flag = 0;
	if (keycode ==LEFT_ARR)
		M->flags.l_flag = 0;
	return (0);
}

int	handle_input(int keycode, t_map *M)
{
	/*
	double	rs;
	double	old_dir_x;
	double	old_pl_x;
	*/
	if (keycode == ESC)
		close_program(M);
	else if (keycode == W || keycode == A || keycode == S || keycode == D)
	{
		if (keycode == W)
			M->flags.w_flag = 1;
		else if (keycode == A)
			M->flags.a_flag = 1;
		else if (keycode == S)
			M->flags.s_flag = 1;
		else if (keycode == D)
			M->flags.d_flag = 1;
		//check_move(M, keycode);
	}
	else if (keycode == RIGHT_ARR || keycode == LEFT_ARR)
	{
		if (keycode == RIGHT_ARR)
			M->flags.r_flag = 1;
		else
			M->flags.l_flag = 1;
		/*
		rs = ROTATION_SPEED;
		if (keycode == RIGHT_ARR)
			rs = -ROTATION_SPEED;
		if (M->start_dir == 'W')
			rs *= -1;
		old_dir_x = M->player.dir_x;
		M->player.dir_x = M->player.dir_x * cos(rs) - M->player.dir_y * sin(rs);
		M->player.dir_y = old_dir_x * sin(rs) + M->player.dir_y * cos(rs);
		old_pl_x = M->player.cam_x;
		M->player.cam_x = M->player.cam_x * cos(rs) - M->player.cam_y * sin(rs);
		M->player.cam_y = old_pl_x * sin(rs) + M->player.cam_y * cos(rs);
		render_map(M);
		*/
	}
	return (0);
}

void	open_window(t_map *Map)
{
	Map->window.win_ptr = mlx_new_window(Map->window.mlx_ptr,
			WINDOW_WIDTH, WINDOW_HEIGHT, "Cub3D");
	mlx_hook(Map->window.win_ptr, 17, 0, close_program, Map);
}
