/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asbai-el <asbai-el@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 19:18:42 by asbai-el          #+#    #+#             */
/*   Updated: 2021/06/25 21:41:07 by asbai-el         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

void ini_game(t_config *config)
{
	config->ptr = mlx_init();
	config->win = mlx_new_window(config->ptr, config->resl.width, config->resl.height, "Cub3D");
}

int	get_direction(double raydirx, double raydiry, int side)
{
	if (side == 1)
	{
		if (-raydiry > 0)
			return (0);
		else
			return (1);
	} else
	{
		if (raydirx < 0)
			return (2);
		else
			return (3);
	}
}
unsigned long create_hex(int r, int g, int b)
{
	return ((r << 16) | (g << 8) | (b));
}

void celling_floor(t_config *config)
{
	int i;
	int j;
	i = 0;
	while (i < config->resl.height) {
		j = 0;
		while (j < config->resl.width) {
			if (i < config->resl.height / 2)
				config->im.data[j + i * config->resl.width] =
					create_hex(config->celling_colors.r,
							   config->celling_colors.g, config->celling_colors.b);
			else
				config->im.data[j + i * config->resl.width] =
					create_hex(config->floor_colors.r,
							   config->floor_colors.g, config->floor_colors.b);
			j++;
		}
		i++;
	}
}

void init_game_conf(t_game *game_conf, t_config *config)
{
    game_conf->posX = config->player.pos.x;
    game_conf->posY = config->player.pos.y;
    game_conf->dirX = config->player.dir.x;
    game_conf->dirY = config->player.dir.y;
    game_conf->planeX = config->player.plane.x;
    game_conf->planeY = config->player.plane.y;
}
void game(t_config *config)
{

    t_game game_conf;
    int x = 0;

	init_game_conf(&game_conf,config);
	celling_floor(config);
	while (x < config->resl.width)
	{
		//calculate ray position and direction
        game_conf.cameraX = 2 * x / (double) (config->resl.width) - 1; //x-coordinate in camera space
        game_conf.rayDirX = game_conf.dirX + game_conf.planeX * game_conf.cameraX;
        game_conf.rayDirY = game_conf.dirY + game_conf.planeY * game_conf.cameraX;

		game_conf.mapX = (int) (game_conf.posX);
		game_conf.mapY = (int) (game_conf.posY);

		//length of ray from one x or y-side to next x or y-side
		game_conf.deltaDistX = fabs(1 / game_conf.rayDirX);
		game_conf.deltaDistY = fabs(1 / game_conf.rayDirY);
		game_conf.hit = 0; //was there a wall game_conf.hit?

		if (game_conf.rayDirX < 0) {
			game_conf.stepX = -1;
			game_conf.sideDistX = (game_conf.posX - game_conf.mapX) * game_conf.deltaDistX;
		} else {
			game_conf.stepX = 1;
			game_conf.sideDistX = (game_conf.mapX + 1.0 - game_conf.posX) * game_conf.deltaDistX;
		}
		if (game_conf.rayDirY < 0) {
			game_conf.stepY = -1;
			game_conf.sideDistY = (game_conf.posY - game_conf.mapY) * game_conf.deltaDistY;
		} else {
			game_conf.stepY = 1;
			game_conf.sideDistY = (game_conf.mapY + 1.0 - game_conf.posY) * game_conf.deltaDistY;
		}

		while (game_conf.hit == 0) {
			//jump to next map square, OR in x-direction, OR in y-direction
			if (game_conf.sideDistX < game_conf.sideDistY) {
				game_conf.sideDistX += game_conf.deltaDistX;
				game_conf.mapX += game_conf.stepX;
				game_conf.side = 0;
			} else {
				game_conf.sideDistY += game_conf.deltaDistY;
				game_conf.mapY += game_conf.stepY;
				game_conf.side = 1;
			}
			//Check if ray has game_conf.hit a wall

			if (config->array[(game_conf.mapY)][(game_conf.mapX)] == '1')
				game_conf.hit = 1;
		}

		if (game_conf.side == 0) game_conf.perpWallDist = (game_conf.mapX - game_conf.posX + (1 - game_conf.stepX) / 2) / game_conf.rayDirX;
		else game_conf.perpWallDist = (game_conf.mapY - game_conf.posY + (1 - game_conf.stepY) / 2) / game_conf.rayDirY;

		 
		if (game_conf.side == 0) game_conf.wallX = game_conf.posY + game_conf.perpWallDist * game_conf.rayDirY;
		else game_conf.wallX = game_conf.posX + game_conf.perpWallDist * game_conf.rayDirX;
		game_conf.wallX -= floor((game_conf.wallX));

		game_conf.texX = (int) (game_conf.wallX * (double) (config->img[0].width));
		if (game_conf.side == 0 && game_conf.rayDirX > 0) game_conf.texX = config->img[0].width - game_conf.texX - 1;
		if (game_conf.side == 1 && game_conf.rayDirY < 0) game_conf.texX = config->img[0].width - game_conf.texX - 1;

		game_conf.lineHeight = (int) (config->resl.height / game_conf.perpWallDist);
		

		//calculate lowest and highest pixel to fill in current stripe
		int drawStart = -game_conf.lineHeight / 2 + config->resl.height / 2;
		if (drawStart < 0)
			drawStart = 0;
		int drawEnd = game_conf.lineHeight / 2 + config->resl.height / 2;
		if (drawEnd >= config->resl.height)
			drawEnd = config->resl.height - 1;

		
		game_conf.step = 1.0 * config->img[0].height / game_conf.lineHeight;
		double texPos = (drawStart - config->resl.height / 2 + game_conf.lineHeight / 2) * game_conf.step;
		int color = get_direction(game_conf.rayDirX, game_conf.rayDirY, game_conf.side);
		while (drawStart < drawEnd)
		{
			//putpixel (x, drawStart, config, color);
			int texY = (int) texPos & (config->img[0].height - 1);
			texPos += game_conf.step;
			if (color == 0)
				config->im.data[(x + drawStart * config->resl.width)] = config->img[0].data[game_conf.texX + texY *
																							   config->img[0].width];
			else if (color == 1)
				config->im.data[(x + drawStart * config->resl.width)] = config->img[1].data[game_conf.texX + texY *
																							   config->img[1].width];
			else if (color == 2)
				config->im.data[(x + drawStart * config->resl.width)] = config->img[2].data[game_conf.texX + texY *
																							   config->img[2].width];
			else
				config->im.data[(x + drawStart * config->resl.width)] = config->img[3].data[game_conf.texX + texY *
																							   config->img[3].width];
			drawStart++;
		}
		config->z_buffer[x] = game_conf.perpWallDist;
		x++;
	}
	int i = 0;
	while (i < config->n_sprites)
	{
		config->distance_sprites[i] = ((pow(game_conf.posX - config->sprites[i].x, 2)) + (pow(game_conf.posY - config->sprites[i].y, 2)));
		config->index_sprites[i] = i;
		i++;
	}
	sort_sprites(config->n_sprites, config->distance_sprites, config->index_sprites);
	int j;
	j = 0;

	while (j < config->n_sprites)
	{
		double spriteX = config->sprites[config->index_sprites[j]].x - game_conf.posX;
		double spriteY = config->sprites[config->index_sprites[j]].y - game_conf.posY;

		double invDet = 1.0 / (game_conf.planeX * game_conf.dirY - game_conf.dirX * game_conf.planeY);
		double transformX = invDet * (game_conf.dirY * spriteX - game_conf.dirX * spriteY);
		double transformY = invDet * (-game_conf.planeY * spriteX + game_conf.planeX * spriteY); //this is actually the depth inside the screen, that what Z is in 3D
		int spriteScreenX = (int)((config->resl.width / 2) * (1 + transformX / transformY));
		int spriteHeight = abs((int)(config->resl.height / (transformY)));

		int drawStartY = -spriteHeight / 2 + config->resl.height / 2;
		if(drawStartY < 0) drawStartY = 0;
		int drawEndY = spriteHeight / 2 + config->resl.height / 2;
		if(drawEndY >= config->resl.height) drawEndY = config->resl.height - 1;

		int spriteWidth = abs( (int) (config->resl.height / (transformY)));
		int drawStartX = -spriteWidth / 2 + spriteScreenX;
		if(drawStartX < 0) drawStartX = 0;
		int drawEndX = spriteWidth / 2 + spriteScreenX;
		if (drawEndX >= config->resl.width)
			drawEndX = config->resl.width - 1;

		int stripe;
		stripe = drawStartX;
		while (stripe < drawEndX)
		{
			game_conf.texX = (int)(256 * (stripe - (-spriteWidth / 2 + spriteScreenX)) * T_WIDTH / spriteWidth) / 256;
			int y;
			y = drawStartY;
			if (transformY > 0 && stripe > 0 && stripe < config->resl.width && transformY < config->z_buffer[stripe])
			{
				while (y < drawEndY)
				{
					int d = (y) * 256 - config->resl.height * 128 + spriteHeight * 128;
					int texY = ((d * T_HEIGHT) / spriteHeight) / 256;
					if ((config->img[4].data[game_conf.texX + texY * config->img[4].width] & 0x00FFFFFF) != 0)
						config->im.data[(stripe + ((y) * config->resl.width))] = config->img[4].data[game_conf.texX + texY * config->img[4].width];
					y++;
				}
			}
			stripe++;
		}
		j++;
	}
	mlx_put_image_to_window(config->ptr, config->win, config->im.ptr, 0, 0);
}

int close_window(void *params)
{
	free_struct(params);
	exit(0);
}

int key_pressed(int keyCode, t_env *env)
{
	env->key[keyCode] = 1;
	return (0);
}
int key_released(int keyCode, t_env *env)
{
	env->key[keyCode] = 0;
	return (0);
}

void W_Key(t_config *config)
{
    if (config->array[(int)(config->player.pos.y)][(int)(config->player.pos.x + config->player.dir.x * 0.1)] == '0')
        config->player.pos.x += config->player.dir.x * 0.1;
    if (config->array[(int)(config->player.pos.y + config->player.dir.y * 0.1)][(int)(config->player.pos.x)] == '0')
        config->player.pos.y += config->player.dir.y * 0.1;
}


void D_Key(t_config *config)
{

    if (config->array[(int)(config->player.pos.y)][(int)(config->player.pos.x + config->player.plane.x * 0.1)] == '0')
        config->player.pos.x += config->player.plane.x * 0.1;
    if (config->array[(int)(config->player.pos.y + config->player.plane.y * 0.1)][(int)(config->player.pos.x)] == '0')
        config->player.pos.y += config->player.plane.y * 0.1;

}

void S_Key(t_config *config)
{
    if (config->array[(int)(config->player.pos.y)][(int)(config->player.pos.x - config->player.dir.x * 0.1)] == '0')
        config->player.pos.x -= config->player.dir.x * 0.1;
    if (config->array[(int)(config->player.pos.y - config->player.dir.y * 0.1)][(int)(config->player.pos.x)] == '0')
        config->player.pos.y -= config->player.dir.y * 0.1;
}


void A_Key(t_config *config)
{
    if (config->array[(int)(config->player.pos.y)][(int)(config->player.pos.x - config->player.plane.x * 0.1)] == '0')
        config->player.pos.x -= config->player.plane.x * 0.1;
    if (config->array[(int)(config->player.pos.y - config->player.plane.y * 0.1)][(int)(config->player.pos.x)] == '0')
        config->player.pos.y -= config->player.plane.y * 0.1;
}

void Left_Key(t_config *config)
{
    double rotSpeed;
    rotSpeed = 0.1;
    double oldDirX = config->player.dir.x;
    config->player.dir.x = config->player.dir.x * cos(rotSpeed) - config->player.dir.y * sin(rotSpeed);
    config->player.dir.y = oldDirX * sin(rotSpeed) + config->player.dir.y * cos(rotSpeed);
    double oldPlaneX = config->player.plane.x;
    config->player.plane.x = config->player.plane.x * cos(rotSpeed) - config->player.plane.y * sin(rotSpeed);
    config->player.plane.y = oldPlaneX * sin(rotSpeed) + config->player.plane.y * cos(rotSpeed);
}

void Right_Key(t_config *config)
{
    double rotSpeed;
    rotSpeed = -0.1;
    double oldDirX = config->player.dir.x;
    config->player.dir.x = config->player.dir.x * cos(rotSpeed) - config->player.dir.y * sin(rotSpeed);
    config->player.dir.y = oldDirX * sin(rotSpeed) + config->player.dir.y * cos(rotSpeed);
    double oldPlaneX = config->player.plane.x;
    config->player.plane.x = config->player.plane.x * cos(rotSpeed) - config->player.plane.y * sin(rotSpeed);
    config->player.plane.y = oldPlaneX * sin(rotSpeed) + config->player.plane.y * cos(rotSpeed);
}

int func(t_config *config)
{
    mlx_clear_window(config->ptr, config->win);
    if (config->env.key[K_W])
        W_Key(config);
    if (config->env.key[K_D])
            D_Key(config);
    if (config->env.key[K_S])
        S_Key(config);
    if (config->env.key[K_A])
        A_Key(config);
    if (config->env.key[LEFT_ARROW])
        Left_Key(config);
    if (config->env.key[RIGHT_ARROW])
        Right_Key(config);
    game(config);
    return (1);
}

void key_handler(t_config *config)
{
	mlx_hook(config->win, 17, 0, close_window, config);
	mlx_hook(config->win, 2, 0, key_pressed, &config->env);
	mlx_hook(config->win, 3, 0, key_released, &config->env);
	mlx_loop_hook(config->ptr, func, config);
	mlx_loop(config->ptr);
}

void ini_images(t_config *conf)
{
	conf->im.ptr = mlx_new_image(conf->ptr, conf->resl.width, conf->resl.height);
	conf->im.data = (int *)mlx_get_data_addr(conf->im.ptr, &conf->im.bpp,
											 &conf->im.sl, &conf->im.e);
	conf->img[0].ptr = mlx_xpm_file_to_image(conf->ptr, conf->no_path,
											 &conf->img[0].width, &conf->img[0].height);
	conf->img[0].data = (int*)mlx_get_data_addr(conf->img[0].ptr,
												&conf->img[0].bpp, &conf->img[0].sl, &conf->img[0].e);
	conf->img[1].ptr = mlx_xpm_file_to_image(conf->ptr, conf->so_path,
											 &conf->img[1].width, &conf->img[1].height);
	conf->img[1].data = (int*)mlx_get_data_addr(conf->img[1].ptr,
												&conf->img[1].bpp, &conf->img[1].sl, &conf->img[1].e);
	conf->img[2].ptr = mlx_xpm_file_to_image(conf->ptr, conf->we_path,
											 &conf->img[2].width, &conf->img[2].height);
	conf->img[2].data = (int*)mlx_get_data_addr(conf->img[2].ptr,
												&conf->img[2].bpp, &conf->img[2].sl, &conf->img[2].e);
	conf->img[3].ptr = mlx_xpm_file_to_image(conf->ptr, conf->ea_path,
											 &conf->img[3].width, &conf->img[3].height);
	conf->img[3].data = (int*)mlx_get_data_addr(conf->img[3].ptr,
												&conf->img[3].bpp, &conf->img[3].sl, &conf->img[2].e);
	conf->img[4].ptr = mlx_xpm_file_to_image(conf->ptr, conf->sprite_path,
											 &conf->img[4].width, &conf->img[4].height);
	conf->img[4].data = (int*)mlx_get_data_addr(conf->img[4].ptr,
												&conf->img[4].bpp, &conf->img[4].sl, &conf->img[4].e);
}

int main(int argc, char **argv)
{
	t_config game_conf;
	argc = 0;
	game_conf = ft_parse(argv[1]);
	ini_player(&game_conf);
	ini_sprite(&game_conf);
	ini_game(&game_conf);
	int k = 0;
	while (k < 300)
	{
		game_conf.env.key[k] = 0;
		k++;
	}
	// TODO : free me
	game_conf.z_buffer = malloc(game_conf.resl.width * sizeof(double));
	printf("R %d %d\n", game_conf.resl.width, game_conf.resl.height);
	printf("NO %s\n", game_conf.no_path);
	printf("SO %s\n", game_conf.so_path);
	printf("WE %s\n", game_conf.we_path);
	printf("EA %s\n", game_conf.ea_path);
	printf("S %s\n", game_conf.sprite_path);
	printf("F %d %d %d\n", game_conf.floor_colors.r, game_conf.floor_colors.g, game_conf.floor_colors.b);
	printf("C %d %d %d\n", game_conf.celling_colors.r, game_conf.celling_colors.g, game_conf.celling_colors.b);
	int i = 0;
	int j = 0;

	ini_images(&game_conf);
    game(&game_conf);
    key_handler(&game_conf);
    free_struct(&game_conf);
}