/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 10:51:46 by ikayacio          #+#    #+#             */
/*   Updated: 2023/11/11 22:56:02 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// çizgi çizgi çiziliyor bütün ekran, bu da bir çizgiyi çizen fonksiyon
// @2 (x) burada x ekseninde hangi konumda çizileceği start/end ise çizginin monitörde boyu
void draw_wall_slice(t_map *Map, int x, int draw_start, int draw_end)
{
	t_img *image;

	image = &Map->images[Map->id];

	// 3D duvarın 2D yüzeyine 2D resim bastırırken kullanılacak yatay konum
	// ışının duvarın hangi x koordinatına denk geldigini tutan degisken
	double tex_x;

	// yatay/dikey duvarlara göre formül uyguluyor. yatay duvarlar horizonla paralel
	// soldan sağa giden, dikey duvarlar ise ufka dik giden duvarlar
	if (Map->ray.side == 0) // dikey duvar
		tex_x = Map->player.pos_y + Map->ray.perp_dist * Map->ray.dir_y;
	else // yatay duvar
		tex_x = Map->player.pos_x + Map->ray.perp_dist * Map->ray.dir_x;

	// tex_x haritanın boyutuna göre çok küçük/büyük değerler alabilir. bu değerleri
	// basitleştirmek için [0-1] aralıgına aliyoruz bu formülle
	tex_x = (tex_x - floor(tex_x)) * image->width;

	// Resim özelliklerini saklamak için değişkenleri bildir.
	int img_height = draw_end - draw_start;
	int img_width = 1;
	int img_bits_per_pixel = image->bpp;
	int img_line_len = image->line_len;
	int endian;

	// Duvar dilimi için yeni bir resim oluştur.
	void *img_ptr = mlx_new_image(Map->window.mlx_ptr, img_width, img_height);

	// Resim verisini al.
	char *img_addr = mlx_get_data_addr(img_ptr, &img_bits_per_pixel, &img_line_len, &endian);

	// resim verisini yeni resme kopyala.
	for (int y = 0; y < img_height; y++)
	{
		int tex_y = (int)((y / (double)img_height) * image->height);
		int texel_offset = (tex_y * image->line_len + (int)tex_x * (image->bpp / 8));
		int img_offset = y * img_line_len;

		// Orijinal resimden yeni resme bir texel kopyala.
		*(int *)(img_addr + img_offset) = *(int *)(image->addr + texel_offset);
	}

	// Yeni resmi belirtilen konuma yerleştir.
	mlx_put_image_to_window(Map->window.mlx_ptr, Map->window.win_ptr, img_ptr, x, draw_start);

	mlx_destroy_image(Map->window.mlx_ptr, img_ptr);
}

// Raycasting sonuçlarına dayanarak duvarı pencereye çizme işlevi.
void draw(t_map *Map, int x)
{
	int line_height;
	int draw_start;
	int draw_end;

	// Ekran üzerindeki duvar diliminin yüksekliğini hesapla.
	line_height = (int)(WINDOW_HEIGHT / Map->ray.perp_dist);
	draw_start = -line_height / 2 + WINDOW_HEIGHT / 2;
	draw_end = line_height / 2 + WINDOW_HEIGHT / 2;

	// Çizim sınırlarının pencere sınırları içinde olduğundan emin ol.
	// draw_start ve draw_end çizilecek dikey çizginin konumları
	// 0'dan kısa ve ekrandan uzun olamaz
	if (draw_start < 0)
		draw_start = 0;
	if (draw_end >= WINDOW_HEIGHT)
		draw_end = WINDOW_HEIGHT - 1;

	// Duvarın tarafına ve yöne bağlı olarak yüzeyine çizilecek texture idsini belirle.
	if (Map->ray.side == 0 && Map->ray.dir_x > 0)
		Map->id = 2;
	else if (Map->ray.side == 0 && Map->ray.dir_x < 0)
		Map->id = 3;
	else if (Map->ray.side == 1 && Map->ray.dir_y < 0)
		Map->id = 1;
	else if (Map->ray.side == 1 && Map->ray.dir_y > 0)
		Map->id = 0;

	// Pencereye duvar dilimini çiz.
	draw_wall_slice(Map, x, draw_start, draw_end);
}

// burasi nokta atlama notioniyla ilgili
void loop(t_map *Map, int *map_x, int *map_y)
{
	while (1)
	{
		// Işın ilk yatay mı dikey mi gride değecek bunu kontrol ediyor. böylelikle
		// nokta atlama (notion) sorunu çözülüyor
		if (Map->ray.side_dist_x < Map->ray.side_dist_y) // ışın dikey gride daha yakınsa buna girer
		{
			Map->ray.side_dist_x += Map->ray.delta_dist_x;
			*map_x += Map->ray.step_x; // ışını o kadar ilerletiyor
			Map->ray.side = 0;		   // eğer en son dikey gride değmişse ray.side=0 olur
		}
		else // ışın yatay gride daha yakınsa da buna girer
		{
			Map->ray.side_dist_y += Map->ray.delta_dist_y;
			*map_y += Map->ray.step_y; // yine o kadar ilerletiyor
			Map->ray.side = 1;		   // eğer en son yatay gride değmişse ray.side=1 olur
		}

		// Işın bir duvara çarparsa looptan çıkıyor ki tekrar kontrolleri yapsin,
		// böylelikle haritanın dışına çıkmasın
		if (*map_x >= 0 && *map_x < Map->col_count && *map_y >= 0 &&
			*map_y < Map->row_count && Map->map[*map_y][*map_x] == '1')
			break;
	}
}

// Ray parametrelerini oyuncu pozisyonuna ve kamera yönetimine dayalı olarak başlatma işlevi.
// dir_x/y        -> ışının vektör koordinatları
// delta_dist_x/y -> dikey/yatay gridler arasındaki constant mesafe
// side_dist_x/y  -> bir sonraki dikey(side_dist_x) ve yatay(side_dist_y) gridlere uzaklık
// step_x/y		  -> ışın x/y düzlemlerinde pozitif mi (sağ/yukarı) negatif mi (sol/aşağı)
// camera_x/y	  -> camera plane's x/y coordinates
// map_x/y 		  -> ışının 2D haritada mevcut konumu
void ray_init(t_map *Map, double camera_x, int map_x, int map_y)
{
	// Başlangıç ray yönlendirmesini ve mesafelerini hesapla.
	Map->ray.dir_x = Map->player.dir_x + Map->player.cam_x * camera_x;
	Map->ray.dir_y = Map->player.dir_y + Map->player.cam_y * camera_x;
	Map->ray.delta_dist_x = fabs(1 / Map->ray.dir_x);
	Map->ray.delta_dist_y = fabs(1 / Map->ray.dir_y);
	Map->ray.side_dist_x = (map_x + 1.0 - Map->player.pos_x) * Map->ray.delta_dist_x;

	// öncelikle step_x/y 1'e eşitleniyor (yani hem x hem y ekseninde pozitif başlangıç olarak)
	Map->ray.step_x = 1;
	Map->ray.step_y = 1;
	Map->ray.side_dist_y = (map_y + 1.0 - Map->player.pos_y) * Map->ray.delta_dist_y;

	// checks if the ray is moving in the negative x direction (west)
	if (Map->ray.dir_x < 0)
	{
		Map->ray.step_x = -1;
		Map->ray.side_dist_x = (Map->player.pos_x - map_x) * Map->ray.delta_dist_x;
	}

	// checks if the ray is moving in the negative y direction (south)
	if (Map->ray.dir_y < 0)
	{
		Map->ray.step_y = -1;
		Map->ray.side_dist_y = (Map->player.pos_y - map_y) * Map->ray.delta_dist_y;
	}
	// During the main raycasting loop, these side distances are updated as the ray
	// moves through the grid. The smaller of the two side distances will indicate
	// which direction (horizontal or vertical) the ray should move to the next grid
	// cell. The algorithm repeatedly increments or decrements the ray's position based
	// on the smaller side distance until the ray hits a wall or obstacle.
}

// Tek bir ışını başlat ve karşılık gelen duvar dilimini çizme işlevi.
// ekranın genişliği boyunca soldan sağa bu fonksiyon calısacak
// x [0, width] aralıgında olacak sekilde ray gönderilecek
void cast_ray(t_map *Map, int x)
{
	double camera_x;
	// oyuncunun haritadaki konumu
	int map_x;
	int map_y;

	// Mevcut ışın için kamera X koordinatını hesapla.
	camera_x = 2 * x / (double)WINDOW_WIDTH - 1;
	map_x = (int)Map->player.pos_x;
	map_y = (int)Map->player.pos_y;

	// NORTH or SOUTH
	if (Map->player.dir_x == 0)
	{
		// again, NORTH or SOUTH
		if (Map->player.dir_y == -1 || Map->player.dir_y == 1)
		{
			// oyuncunun bakış açısıyla kameara açısını eşitliyoruz
			Map->player.cam_y = 0.0;
			Map->player.cam_x = Map->player.dir_y * -1;
		}
	}

	// bunlara göre ışın gönder ve bu ışını sürekli güncelle
	ray_init(Map, camera_x, map_x, map_y);
	loop(Map, &map_x, &map_y);

	// Duvara olan dik uzaklığı hesapla ve duvar dilimini çiz.
	Map->ray.perp_dist = fabs((map_y - Map->player.pos_y + (1 - Map->ray.step_y) / 2) / Map->ray.dir_y);
	if (Map->ray.side == 0)
		Map->ray.perp_dist = fabs((map_x - Map->player.pos_x + (1 - Map->ray.step_x) / 2) / Map->ray.dir_x);
	draw(Map, x);
}
