#include "./minilibx-linux/mlx.h"
#include <stdio.h>

typedef struct s_vars
{
	void *mlx;
	void *win;
} t_vars;

int close(int keycode, t_vars *vars)
{
	// sadece esc'ye bastığında kapansın
	if (keycode == 53)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		return (0);
	}
	// if eklemezsen neye basarsan bas, kapanır
	// mlx_destroy_window(vars->mlx, vars->win);
}

int main(void)
{
	t_vars vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1000, 300, "Hello world!");
	mlx_hook(vars.win, 2, 1L << 0, close, &vars);
	mlx_loop(vars.mlx);
}
