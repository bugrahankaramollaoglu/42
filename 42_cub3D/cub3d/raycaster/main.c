#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "mlx/mlx.h"

# define width 640
# define height 480
# define mapWidth 24
# define mapHeight 24
# define WHITE	0xffffff
# define RED	0XF51313
# define LILAC	0x8C1DEE
# define BLACK	0x000000
# define GRAY	0x726E6E
# define GREEN	0x25bc17



typedef struct s_image
{
    void    *img;
    void    *buffer;
    int     bbp;
    int     size_line;
    int     endian;
    int     width_i;
    int     height_i;
}               t_image;

typedef struct s_player
{
    double pos_x;
    double pos_y;
    double dirX;
    double dirY; //initial direction vector
    double planeX;
    double planeY; //the 2d raycaster version of camera plane
    double speed;
} t_player;

typedef struct s_nec
{
    void    *mlx;
    void    *win;
    t_player *player;
    t_image  *image;
}t_nec;


void    put_2d(int x, int drawStart, int drawEnd, int color, t_image *img);
void    init_map(t_image *image, t_player *player, void *mlx, void *win);
int keyboard(int keycode, t_nec *nec);

int worldMap[mapWidth][mapHeight]=
{
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

t_image wall;

int main()
{
    void    *mlx = mlx_init();
    void    *win = mlx_new_window(mlx, width, height, "cub3d");
    t_nec nec;
    nec.mlx = mlx;
    nec.win = win;
    t_image image;
    t_player player;
    image.img = mlx_new_image(mlx, width, height);
    image.buffer = mlx_get_data_addr(image.img, &(image.bbp), &(image.size_line), &(image.endian));
    player.pos_x = 22, player.pos_y = 12;  //x and y start position
    player.dirX = -1, player.dirY = 0; //initial direction vector
    player.speed = 0.006000;
    player.planeX = 0, player.planeY = 0.66; //the 2d raycaster version of camera plane
    nec.player = &player;
    nec.image = &image;
    wall.img = mlx_xpm_file_to_image(mlx, "textures/wall1.xpm", &(wall.width_i), &(wall.height_i));
    wall.buffer = mlx_get_data_addr(wall.img, &(wall.bbp), &(wall.size_line), &(wall.endian));
    init_map(&image, &player, mlx, win);
    mlx_hook(nec.win, 2, 1L << 0, keyboard, &nec);
    mlx_loop(mlx);
}

void my_mlx_pixel_put(int x, int y, int color, t_image *img){
	char *dst = img->buffer + (y * img->size_line + x * (img->bbp / 8));
	*(unsigned int*)dst = color;
}

void    put_2d(int x, int drawStart, int drawEnd, int color, t_image *img)
{
    while (drawStart < drawEnd)
    {
        my_mlx_pixel_put(x, drawStart, color, img);
        drawStart++;
    }    
}

int color_image(int y, int x){
	char *dst = wall.buffer + (y * wall.size_line + x * (wall.bbp / 8));
	return *(unsigned int*)dst;
}


void    init_map(t_image *image, t_player *player, void *mlx, void *win)
{
    // double time = 0; //time of current frame
    // double oldTime = 0; //time of previous frame

    for (size_t i = 0; i < width; i++)
    {
        put_2d(i, 0, height / 2, GRAY,image);
        put_2d(i, height / 2, height, WHITE, image);
    }
    
    for (int x = 0; x < width; x++)
    {
        //ışın konumunu ve yönünü hesapla
        double cameraX = 2 * x / (double)width - 1; //x-coordinate in camera space
        double rayDirX = player->dirX + player->planeX * cameraX;
        double rayDirY = player->dirY + player->planeY * cameraX;

        //haritada hangi kutudayız
        int mapX = (int)player->pos_x;
        int mapY = (int)player->pos_y;

        //geçerli konumdan bir sonraki x veya y kenarına kadar olan ışın uzunluğu
        double sideDistX;
        double sideDistY;

        double deltaDistX = (rayDirX == 0) ? 1e30 : fabs(1 / rayDirX);
        double deltaDistY = (rayDirY == 0) ? 1e30 : fabs(1 / rayDirY);

        double perpWallDist;


        //what direction to step in x or y-direction (either +1 or -1)
        int stepX;
        int stepY;

        int hit = 0; //was there a wall hit?
        int side; //was a NS or a EW wall hit?
        //calculate step and initial sideDist
        if(rayDirX < 0)
        {
            stepX = -1;
            sideDistX = (player->pos_x - mapX) * deltaDistX;
        }
        else
        {
            stepX = 1;
            sideDistX = (mapX + 1.0 - player->pos_x) * deltaDistX;
        }
        if(rayDirY < 0)
        {
            stepY = -1;
            sideDistY = (player->pos_y - mapY) * deltaDistY;
        }
        else
        {
            stepY = 1;
            sideDistY = (mapY + 1.0 - player->pos_y) * deltaDistY;
        }
        // printf("cameraX:%d, y:%d, x:%f, y:%f\n", stepX, stepY,deltaDistX, deltaDistY); pause();
        //perform DDA
        while(hit == 0)
        {
            //x yönünde veya y yönünde bir sonraki harita karesine atla
            if(sideDistX < sideDistY)
            {
                sideDistX += deltaDistX;
                mapX += stepX;
                side = 0;
            }
            else
            {
                sideDistY += deltaDistY;
                mapY += stepY;
                side = 1;
            }
            //ray'in duvara çarpıp çarpmadığını kontrol et
            if(worldMap[mapX][mapY] > 0) hit = 1;
        }
        if(side == 0) perpWallDist = (sideDistX - deltaDistX);
        else          perpWallDist = (sideDistY - deltaDistY);

        //Ekranda çizilecek çizginin yüksekliğini hesapla
        int lineHeight = (int)(height / perpWallDist);

        //geçerli şeridi doldurmak için en düşük ve en yüksek pikseli hesapla
        int pitch = 100;
        int drawStart = -lineHeight / 2 + height / 2;
        if(drawStart < 0) drawStart = 0;
        int drawEnd = lineHeight / 2 + height / 2;
        if(drawEnd >= height) drawEnd = height - 1;

        double wallX; //where exactly the wall was hit
        if(side == 0) wallX = player->pos_y + perpWallDist * rayDirY;
        else          wallX = player->pos_x + perpWallDist * rayDirX;
        wallX -= floor((wallX));

        //x coordinate on the texture
        int texX = (int)(wallX * (double)(64));
        if(side == 0 && rayDirX > 0) texX = 64 - texX - 1;
        if(side == 1 && rayDirY < 0) texX = 64 - texX - 1;

        // TODO: an integer-only bresenham or DDA like algorithm could make the texture coordinate stepping faster
        // How much to increase the texture coordinate per screen pixel
        double step = 1.0 * 64 / lineHeight;
        // Starting texture coordinate
        double texPos = (drawStart - height / 2 + lineHeight / 2) * step;
        int color;
        for(int y = drawStart; y < drawEnd; y++)
        {
            // Cast the texture coordinate to integer, and mask with (texHeight - 1) in case of overflow
            int texY = (int)texPos & (64 - 1);
            texPos += step;
            //make color darker for y-sides: R, G and B byte each divided through two with a "shift" and an "and"
            color = color_image(texY, texX);
            if(side == 1) color = (color >> 1) & 8355711;
            put_2d(x, y, y + 1, color, image);
        }
    }
    mlx_put_image_to_window(mlx, win, image->img, 0, 0);
}

int keyboard(int keycode, t_nec *nec)
{
    double x = nec->player->pos_x;
	double y = nec->player->pos_y;
    double movespeed = nec->player->speed * 50.0;
    double rootspeed = nec->player->speed * 20.0;

	if (keycode == 119 || keycode == 13){
		printf("W tuşuna basıldı.\n");
        x += nec->player->dirX * movespeed;
        y += nec->player->dirY * movespeed;
	}
	else if (keycode == 115 || keycode == 1){
		printf("S tuşuna basıldı.\n");
        x -= nec->player->dirX * movespeed;
        y -= nec->player->dirY * movespeed;
	}
	else if (keycode == 100 || keycode == 2 || keycode == 65363 || keycode == 124){
		printf("D tuşuna basıldı.\n");
        double oldDirX = nec->player->dirX;
        nec->player->dirX = nec->player->dirX * cos(-rootspeed) - nec->player->dirY * sin(-rootspeed);
        nec->player->dirY = oldDirX * sin(-rootspeed) + nec->player->dirY * cos(-rootspeed);
        double oldPlaneX = nec->player->planeX;
        nec->player->planeX = nec->player->planeX * cos(-rootspeed) - nec->player->planeY * sin(-rootspeed);
        nec->player->planeY = oldPlaneX * sin(-rootspeed) + nec->player->planeY * cos(-rootspeed);
	}
	else if (keycode == 97 || keycode == 0 || keycode == 65361 || keycode == 123){
		printf("A tuşuna basıldı.\n");
        double oldDirX = nec->player->dirX;
        nec->player->dirX = nec->player->dirX * cos(rootspeed) - nec->player->dirY * sin(rootspeed);
        nec->player->dirY = oldDirX * sin(rootspeed) + nec->player->dirY * cos(rootspeed);
        double oldPlaneX = nec->player->planeX;
        nec->player->planeX = nec->player->planeX * cos(rootspeed) - nec->player->planeY * sin(rootspeed);
        nec->player->planeY = oldPlaneX * sin(rootspeed) + nec->player->planeY * cos(rootspeed);
		
	}
	else if (keycode == 53 || keycode == 65307){
		printf("ESC tuşuna basıldı.\n");
		exit(1);
	}
    nec->player->pos_x = x;
    nec->player->pos_y = y;
    mlx_clear_window(nec->mlx, nec->win);
    init_map(nec->image, nec->player, nec->mlx, nec->win);
}