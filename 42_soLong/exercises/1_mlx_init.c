#include "./minilibx-linux/mlx.h"
#include <stdio.h>

// gcc -o my_program main.c -L./minilibx-linux -lmlx -lXext -lX11 -lm
// minilibx-linux must be maked beforehand

int main(void)
{
	void *mlx;
	void *mlx_win;

	mlx = mlx_init();

	// mlx_new_window() returns a pointer to the window we have just created.
	// en/boy ve pencere ölçülerini veriyoruz.
	mlx_win = mlx_new_window(mlx, 800, 500, "merhaba pencere");

	// mlx_loop sürekli klavye ve fareden input bekler
	mlx_loop(mlx);
}
