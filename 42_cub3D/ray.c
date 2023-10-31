/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 10:51:46 by ikayacio          #+#    #+#             */
/*   Updated: 2023/10/31 16:51:37 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// raycast ışın formülüne göre duvar noktalarında çizgi çizen fonksiyon
// x burada yatayda ekranın hangi koordinatinda cizilecegi
// draw_start/end ise düşeyde ekranın hangi koordinatları arası cizilecegi
void draw_wall_slice(t_map *Map, int x, int draw_start, int draw_end)
{
	t_img *image;
	int y;
	int img_y;
	int color;

	image = &Map->images[Map->id];
	y = draw_start;
	while (y < draw_end)
	{
		img_y = (int)((y - draw_start) * (double)image->height / (double)(draw_end - draw_start));
		color = *(int *)(image->addr + (img_y * image->line_len + x * (image->bpp / 8)));
		mlx_pixel_put(Map->window.mlx_ptr, Map->window.win_ptr, x, y, color);
		y++;
	}
	image = NULL;
}

// farazi ışın doğrusunu çizecek olan fonksiyon
void draw(t_map *Map, int x)
{
	int line_height;
	int draw_start;
	int draw_end;

	line_height = (int)(WINDOW_HEIGHT / Map->ray.perp_dist);
	draw_start = -line_height / 2 + WINDOW_HEIGHT / 2;
	draw_end = line_height / 2 + WINDOW_HEIGHT / 2;
	if (draw_start < 0)
		draw_start = 0;
	if (draw_end >= WINDOW_HEIGHT)
		draw_end = WINDOW_HEIGHT - 1;
	if (Map->ray.side == 0 && Map->ray.dir_x > 0)
		Map->id = 2;
	else if (Map->ray.side == 0 && Map->ray.dir_x < 0)
		Map->id = 3;
	else if (Map->ray.side == 1 && Map->ray.dir_y < 0)
		Map->id = 1;
	else if (Map->ray.side == 1 && Map->ray.dir_y > 0)
		Map->id = 0;
	draw_wall_slice(Map, x, draw_start, draw_end);
}

void loop(t_map *Map, int *map_x, int *map_y)
{
	while (1)
	{
		/* ışının ilk düşey çizgiye olan mesafesi (side_dist_x)
		ilk yatay çizgiye olan mesafesinden (side_dist_y) kısa
		ise buna girer çünkü ilk ona çarpacak. */
		if (Map->ray.side_dist_x < Map->ray.side_dist_y)
		{
			// ışını, bir sonraki vertical grid görene kadar ilerletiyor
			// bunu da ışının konumuna aradaki mesafeyi ekleyerek yapiyor
			Map->ray.side_dist_x += Map->ray.delta_dist_x;
			// hücrenin x koordinatini güncelliyor (çünkü ışın artık o hücreye değdi ve geçti)
			*map_x += Map->ray.step_x;
			// eğer düşey bir çizgiye değdiyse 0 verilir genelde
			Map->ray.side = 0;
		}
		else
		{
			/* ışının ilk yatay çizgiye olan mesafesi (side_dist_y)
			ilk düşey çizgiye olan mesafesinden (side_dist_x) kısa
			ise buna girer çünkü ilk ona çarpacak.  */
			Map->ray.side_dist_y += Map->ray.delta_dist_y;
			// ışını, bir sonraki horizontal grid görene kadar ilerletiyor
			// bunu da ışının konumuna aradaki mesafeyi ekleyerek yapiyor
			*map_y += Map->ray.step_y;
			// eğer yatay bir çizgiye değdiyse 1 verilir genelde
			Map->ray.side = 1;
		}
		if (*map_x >= 0 && *map_x < Map->col_count && *map_y >= 0 && *map_y < Map->row_count && Map->map[*map_y][*map_x] == '1')
			break;
	}
}

// initializes various properties of the ray based on the
// camera direction and map grid cell.
void ray_init(t_map *Map, double camera_x, int map_x, int map_y)
{
	// ray.dir_x ve ray.dir_y ışının koordinatları
	// aşağıdaki formülle oyuncunun bakışına göre ışını ayarlıyor böylece
	// oyuncu hangi doğru ile bakıyorsa ışın da o yönde gidiyor
	Map->ray.dir_x = Map->player.dir_x + Map->player.cam_x * camera_x;
	Map->ray.dir_y = Map->player.dir_y + Map->player.cam_y * camera_x;

	// ışının bir blok ilerlemek için kat etmesi gereken mesafeyi
	// hesapliyor. sol/alt durumunda negatif olacagından floatAbs() diyor
	Map->ray.delta_dist_x = fabs(1 / Map->ray.dir_x);
	Map->ray.delta_dist_y = fabs(1 / Map->ray.dir_y);

	// side_dist_x/y oyuncudan çıkan ışının düşey ve yatay düzlemde
	// başlangıçta duvarlara uzaklıgını belirler
	// delta_dist_x/y ışının yatay ve düşey düzlemde en fazla
	// ne kadar gideceğini belirler, yani azami mesafesini verir
	// böylelikle ışını constant değil blok görene kadar ilerletiyoruz, skipping
	// problemi çözülmüş oluyor
	Map->ray.side_dist_x = (map_x + 1.0 - Map->player.pos_x) * Map->ray.delta_dist_x;
	Map->ray.side_dist_y = (map_y + 1.0 - Map->player.pos_y) * Map->ray.delta_dist_y;

	// ışının sağa mı (1) sola mı (-1) gideceğini belirler (x ekseni düşün)
	Map->ray.step_x = 1;
	Map->ray.step_y = 1;

	// eğer oyuncunun bakış yönü sol/alt ise ışık da o yöne bakıyor
	if (Map->ray.dir_x < 0)
	{
		Map->ray.step_x = -1;
		Map->ray.side_dist_x = (Map->player.pos_x - map_x) * Map->ray.delta_dist_x;
	}
	if (Map->ray.dir_y < 0)
	{
		Map->ray.step_y = -1;
		Map->ray.side_dist_y = (Map->player.pos_y - map_y) * Map->ray.delta_dist_y;
	}
}

// ışın gönderen fonksiyon
// x burada ekranın her bir sütunu (width) yani 600
// tüm sütunlar giriyor bu fonksiyona, x 0-599 tüm değerleri aliyor
void cast_ray(t_map *Map, int x)
{
	// current column. ranges from -1 to +1
	double camera_x;
	// haritanın o an hangi konumunda player (think 2D)
	int map_x;
	int map_y;

	// böylelikle -1 +1 aralıgını veriyoruz
	camera_x = 2 * x / (double)WINDOW_WIDTH - 1;

	map_x = (int)Map->player.pos_x;
	map_y = (int)Map->player.pos_y;

	// player.dir_x burada karakterin (x düzlemi oldugu icin)
	// saga ya da sola bakıp bakmadıgını gösterir (S-W). karakter
	// NORTH ya da SOUTH bakiyosa dir_x 0, WEST bakiyosa -1, SOUTHsa 1 olur
	if (Map->player.dir_x == 0)
	{
		// dir_y eğer karakter W-E bakiyosa 0, NORTH bakıyosa (-1) ya da SOUTH bakıyosa (1) olur
		// yani burada karakterin yukarı ya da asagi bakmasini kontrol eder
		if (Map->player.dir_y == -1 || Map->player.dir_y == 1)
		{
			// cam_x/y burada kamera genişliği.
			// başlangıçta cam_y=0.66 olarak başlıyor
			Map->player.cam_y = 0.0;
			// ışınlar x düzleminde (düşey) gittiği için cam_x'i güncelliyor
			Map->player.cam_x = Map->player.dir_y * -1;
		}
	}
	// açıları ayarladıktan sonra ışın göndermeye başlıyor
	ray_init(Map, camera_x, map_x, map_y);
	loop(Map, &map_x, &map_y);
	// perpendicular-distance yani ışının 3D düzlemde dikay uzaklıgı
	Map->ray.perp_dist = fabs((map_y - Map->player.pos_y + (1 - Map->ray.step_y) / 2) / Map->ray.dir_y);
	// eğer ışın yatay bir grid çizgisine değdiyse 1, düşeye değdiyse 0 verilir
	// raycast algoritmasının bir özelliği. bu sayede duvar atlama olayını çözüyor
	if (Map->ray.side == 0)
		Map->ray.perp_dist = fabs((map_x - Map->player.pos_x + (1 - Map->ray.step_x) / 2) / Map->ray.dir_x);
	// sonunda da haritayi çiziyor, her seferinde bir x yani width çizgisi çizilecek şekilde
	draw(Map, x);
}
