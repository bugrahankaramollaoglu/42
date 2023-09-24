#include "./minilibx-linux/mlx.h"
#include <stdio.h>

/* renkler hexadecimal sayı olarak tutulur
0xTTRRGGBB ifadesinde Transparency, red, gren, blue */

typedef struct s_data
{
	void *img;
	char *addr;
	int bits_per_pixel;
	int line_length;
	int endian;
} t_data;

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
	mlx_win = mlx_new_window(mlx, 1000, 1000, "Hello world!");
	img.img = mlx_new_image(mlx, 1000, 1000);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								 &img.endian);

	// sol kenar. i burada sol üstten itibaren hangi satırda olduğunu gösterir. 500 dersen şu an tam ekranın
	// ortasındaki satırı seçer. 1000 dersen ekranın son satırını seçer (çizdiğin piksel görünmez).
	int i = 250;
	// ekranın sonuna kadar (en alt kenar) çizgi çizmek için 1000 yazılır.
	while (i < 500)
	{
		// 2. parametre burada hangi sütunu seçeceğini gösterir. 500 dersen şu an tam ekranın ortasındaki sütunu seçer.
		// 0x... burada ARGB(0, 255, 0) renk kodudur (kırmızı).
		my_mlx_pixel_put(&img, 250, i, 0xFFFFFFFF);
		i++;
	}

	// sağ kenar
	i = 250;
	while (i < 500)
	{
		my_mlx_pixel_put(&img, 500, i, 0x640FFF);
		i++;
	}

	// üst kenar
	i = 250;
	while (i < 500)
	{
		my_mlx_pixel_put(&img, i, 500, 0x640FFF);
		i++;
	}

	// alt kenar
	i = 250;
	while (i < 500)
	{
		my_mlx_pixel_put(&img, i, 250, 0x640F28);
		i++;
	}

	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
