#include "./minilibx-linux/mlx.h"
#include <stdio.h>

typedef struct s_data
{
	void *img;
	char *addr;
	int bits_per_pixel;
	int line_length;
	int endian;
} t_data;

// (x,y) koordinatina color renginde nokta koyar
void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int main(void)
{
	void *mlx;
	void *mlx_win;
	t_data img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 800, 500, "Hello world!");
	img.img = mlx_new_image(mlx, 800, 500);
	// resmin adresi mlx_get_data_addr ile alınır
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	// Note that 0x00FF0000 is the hex representation of ARGB(0,255,0,0).
	// (50, 50)'ye kırmızı bir nokta basılır
	my_mlx_pixel_put(&img, 50, 50, 0x00FF0000);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
