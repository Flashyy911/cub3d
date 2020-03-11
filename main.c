/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asbai-el <asbai-el@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 19:18:42 by asbai-el          #+#    #+#             */
/*   Updated: 2020/02/27 15:49:39 by asbai-el         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
void game(t_config *config)
{
	double posX = config->player.pos.x, posY = config->player.pos.y;
	double dirX = config->player.dir.x, dirY = config->player.dir.y;
	double planeX = config->player.plane.x, planeY = config->player.plane.y;
	int x = 0;
	celling_floor(config);
	while (x < config->resl.width)
	{
		//calculate ray position and direction
		double cameraX = 2 * x / (double) (config->resl.width) - 1; //x-coordinate in camera space
		double rayDirX = dirX + planeX * cameraX;
		double rayDirY = dirY + planeY * cameraX;

		int mapX = (int) (posX);
		int mapY = (int) (posY);

		//length of ray from current position to next x or y-side
		double sideDistX;
		double sideDistY;

		//length of ray from one x or y-side to next x or y-side
		double deltaDistX = fabs(1 / rayDirX);
		double deltaDistY = fabs(1 / rayDirY);
		double perpWallDist;

		//what direction to step in x or y-direction (either +1 or -1)
		int stepX;
		int stepY;

		int hit = 0; //was there a wall hit?
		int side; //was a NS or a EW wall hit?

		if (rayDirX < 0) {
			stepX = -1;
			sideDistX = (posX - mapX) * deltaDistX;
		} else {
			stepX = 1;
			sideDistX = (mapX + 1.0 - posX) * deltaDistX;
		}
		if (rayDirY < 0) {
			stepY = -1;
			sideDistY = (posY - mapY) * deltaDistY;
		} else {
			stepY = 1;
			sideDistY = (mapY + 1.0 - posY) * deltaDistY;
		}

		while (hit == 0) {
			//jump to next map square, OR in x-direction, OR in y-direction
			if (sideDistX < sideDistY) {
				sideDistX += deltaDistX;
				mapX += stepX;
				side = 0;
			} else {
				sideDistY += deltaDistY;
				mapY += stepY;
				side = 1;
			}
			//Check if ray has hit a wall

			if (config->array[(mapY)][(mapX)] == '1')
				hit = 1;
		}

		if (side == 0) perpWallDist = (mapX - posX + (1 - stepX) / 2) / rayDirX;
		else perpWallDist = (mapY - posY + (1 - stepY) / 2) / rayDirY;

		double wallX; //where exactly the wall was hit
		if (side == 0) wallX = posY + perpWallDist * rayDirY;
		else wallX = posX + perpWallDist * rayDirX;
		wallX -= floor((wallX));

		int texX = (int) (wallX * (double) (config->img[0].width));
		if (side == 0 && rayDirX > 0) texX = config->img[0].width - texX - 1;
		if (side == 1 && rayDirY < 0) texX = config->img[0].width - texX - 1;

		int lineHeight = (int) (config->resl.height / perpWallDist);

		//calculate lowest and highest pixel to fill in current stripe
		int drawStart = -lineHeight / 2 + config->resl.height / 2;
		if (drawStart < 0)
			drawStart = 0;
		int drawEnd = lineHeight / 2 + config->resl.height / 2;
		if (drawEnd >= config->resl.height)
			drawEnd = config->resl.height - 1;

		double step = 1.0 * config->img[0].height / lineHeight;
		double texPos = (drawStart - config->resl.height / 2 + lineHeight / 2) * step;
		int color = get_direction(rayDirX, rayDirY, side);
		while (drawStart < drawEnd)
		{
			//putpixel (x, drawStart, config, color);
			int texY = (int) texPos & (config->img[0].height - 1);
			texPos += step;
			if (color == 0)
				config->im.data[(x + drawStart * config->resl.width)] = config->img[0].data[texX + texY *
																							   config->img[0].width];
			else if (color == 1)
				config->im.data[(x + drawStart * config->resl.width)] = config->img[1].data[texX + texY *
																							   config->img[1].width];
			else if (color == 2)
				config->im.data[(x + drawStart * config->resl.width)] = config->img[2].data[texX + texY *
																							   config->img[2].width];
			else
				config->im.data[(x + drawStart * config->resl.width)] = config->img[3].data[texX + texY *
																							   config->img[3].width];
			drawStart++;
		}
		config->z_buffer[x] = perpWallDist;
		x++;
	}
	int i = 0;
	while (i < config->n_sprites)
	{
		config->distance_sprites[i] = ((pow(posX - config->sprites[i].x, 2)) + (pow(posY - config->sprites[i].y, 2)));
		config->index_sprites[i] = i;
		i++;
	}
	sort_sprites(config->n_sprites, config->distance_sprites, config->index_sprites);
	int j;
	j = 0;

	while (j < config->n_sprites)
	{
		double spriteX = config->sprites[config->index_sprites[j]].x - posX;
		double spriteY = config->sprites[config->index_sprites[j]].y - posY;

		double invDet = 1.0 / (planeX * dirY - dirX * planeY);
		double transformX = invDet * (dirY * spriteX - dirX * spriteY);
		double transformY = invDet * (-planeY * spriteX + planeX * spriteY); //this is actually the depth inside the screen, that what Z is in 3D
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
			int texX = (int)(256 * (stripe - (-spriteWidth / 2 + spriteScreenX)) * T_WIDTH / spriteWidth) / 256;
			int y;
			y = drawStartY;
			if (transformY > 0 && stripe > 0 && stripe < config->resl.width && transformY < config->z_buffer[stripe])
			{
				while (y < drawEndY)
				{
					int d = (y) * 256 - config->resl.height * 128 + spriteHeight * 128;
					int texY = ((d * T_HEIGHT) / spriteHeight) / 256;
					if ((config->img[4].data[texX + texY * config->img[4].width] & 0x00FFFFFF) != 0)
						config->im.data[(stripe + ((y) * config->resl.width))] = config->img[4].data[texX + texY * config->img[4].width];
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

int func(t_config *config)
{
	mlx_clear_window(config->ptr, config->win);
	if (config->env.key[K_W])
	{
		if (config->array[(int)(config->player.pos.y)][(int)(config->player.pos.x + config->player.dir.x * 0.1)] == '0')
			config->player.pos.x += config->player.dir.x * 0.1;
		if (config->array[(int)(config->player.pos.y + config->player.dir.y * 0.1)][(int)(config->player.pos.x)] == '0')
			config->player.pos.y += config->player.dir.y * 0.1;

	}
	if (config->env.key[K_D])
	{

		if (config->array[(int)(config->player.pos.y)][(int)(config->player.pos.x + config->player.plane.x * 0.1)] == '0')
			config->player.pos.x += config->player.plane.x * 0.1;
		if (config->array[(int)(config->player.pos.y + config->player.plane.y * 0.1)][(int)(config->player.pos.x)] == '0')
			config->player.pos.y += config->player.plane.y * 0.1;
	}
	if (config->env.key[K_S])
	{
		if (config->array[(int)(config->player.pos.y)][(int)(config->player.pos.x - config->player.dir.x * 0.1)] == '0')
			config->player.pos.x -= config->player.dir.x * 0.1;
		if (config->array[(int)(config->player.pos.y - config->player.dir.y * 0.1)][(int)(config->player.pos.x)] == '0')
			config->player.pos.y -= config->player.dir.y * 0.1;

	}
	if (config->env.key[K_A])
	{
		if (config->array[(int)(config->player.pos.y)][(int)(config->player.pos.x - config->player.plane.x * 0.1)] == '0')
			config->player.pos.x -= config->player.plane.x * 0.1;
		if (config->array[(int)(config->player.pos.y - config->player.plane.y * 0.1)][(int)(config->player.pos.x)] == '0')
			config->player.pos.y -= config->player.plane.y * 0.1;
	}
	if (config->env.key[LEFT_ARROW])
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
	if (config->env.key[RIGHT_ARROW])
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
	//game(&game_conf);
	//key_handler(&game_conf);
	free_struct(&game_conf);
}
