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
	config->win = mlx_new_window(config->ptr, config->resl.width, config->resl.height, "Cub3d");
}

void draw(int x, int drawstart, int drawend, t_config *config)
{
	while (drawstart < drawend)
	{
		mlx_pixel_put(config->ptr, config->win, x, drawstart, 0xffffff);
		drawstart++;
	}
}

void game(t_config *config)
{
	double posX = config->player.pos.x, posY = config->player.pos.y;
	double dirX = config->player.dir.x, dirY = config->player.dir.y;
	double planeX = config->player.plane.x, planeY = config->player.plane.y;

	for(int x = 0; x < config->resl.width; x++)
	{
		//calculate ray position and direction
		double cameraX = 2 * x / (double)(config->resl.width) -1; //x-coordinate in camera space
		double rayDirX = dirX + planeX * cameraX;
		double rayDirY = dirY + planeY * cameraX;

		int mapX = (int)(posX);
		int mapY = (int)(posY);

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

		if (rayDirX < 0)
		{
			stepX = -1;
			sideDistX = (posX - mapX) * deltaDistX;
		}
		else
		{
			stepX = 1;
			sideDistX = (mapX + 1.0 - posX) * deltaDistX;
		}
		if (rayDirY < 0)
		{
			stepY = -1;
			sideDistY = (posY - mapY) * deltaDistY;
		}
		else
		{
			stepY = 1;
			sideDistY = (mapY + 1.0 - posY) * deltaDistY;
		}

		while (hit == 0)
		{
			//jump to next map square, OR in x-direction, OR in y-direction
			if (sideDistX < sideDistY)
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
			//Check if ray has hit a wall
			if (config->array[mapY][mapX] == '1') hit = 1;
		}

		if (side == 0) perpWallDist = (mapX - posX + (1 - stepX) / 2) / rayDirX;
		else           perpWallDist = (mapY - posY + (1 - stepY) / 2) / rayDirY;

		int lineHeight = (int)(config->resl.height / perpWallDist);

		//calculate lowest and highest pixel to fill in current stripe
		int drawStart = -lineHeight / 2 + config->resl.height / 2;
		if(drawStart < 0)drawStart = 0;
		int drawEnd = lineHeight / 2 + config->resl.height / 2;
		if(drawEnd >= config->resl.height)drawEnd = config->resl.height - 1;

		draw(x, drawStart, drawEnd, config);
	}
}

int close_window(void *params)
{
	free_struct(params);
	exit(0);
}

int key_pressed(int keyCode,t_config *config)
{
	printf("%d\n", keyCode);
	if (keyCode == 13) // up
	{
		mlx_clear_window(config->ptr, config->win);
		config->player.pos.x += config->player.dir.x * 0.3;
		config->player.pos.y += config->player.dir.y * 0.3;
		game(config);
	}
	if (keyCode == 2) // right
	{
		mlx_clear_window(config->ptr, config->win);
		config->player.pos.x += config->player.plane.x * 0.3;
		config->player.pos.y += config->player.plane.y * 0.3;
		game(config);
	}
	if (keyCode == 1) // down
	{
		mlx_clear_window(config->ptr, config->win);
		config->player.pos.x -= config->player.dir.x * 0.3;
		config->player.pos.y -= config->player.dir.y * 0.3;
		game(config);
	}
	if (keyCode == 0) // left
	{
		mlx_clear_window(config->ptr, config->win);
		config->player.pos.x -= config->player.plane.x * 0.3;
		config->player.pos.y -= config->player.plane.y * 0.3;
		game(config);
	}
	if (keyCode == 124) // right
	{
		mlx_clear_window(config->ptr, config->win);
		double rotSpeed;

		rotSpeed = 0.2;
		double oldDirX = config->player.dir.x;
		config->player.dir.x = config->player.dir.x * cos(rotSpeed) - config->player.dir.y * sin(rotSpeed);
		config->player.dir.y = oldDirX * sin(rotSpeed) + config->player.dir.y * cos(rotSpeed);
		double oldPlaneX = config->player.plane.x;
		config->player.plane.x = config->player.plane.x * cos(rotSpeed) - config->player.plane.y * sin(rotSpeed);
		config->player.plane.y = oldPlaneX * sin(rotSpeed) + config->player.plane.y * cos(rotSpeed);
		game(config);
	}
	if (keyCode == 123) // left
	{
		mlx_clear_window(config->ptr, config->win);
		double rotSpeed;

		rotSpeed = -0.2;
		double oldDirX = config->player.dir.x;
		config->player.dir.x = config->player.dir.x * cos(rotSpeed) - config->player.dir.y * sin(rotSpeed);
		config->player.dir.y = oldDirX * sin(rotSpeed) + config->player.dir.y * cos(rotSpeed);
		double oldPlaneX = config->player.plane.x;
		config->player.plane.x = config->player.plane.x * cos(rotSpeed) - config->player.plane.y * sin(rotSpeed);
		config->player.plane.y = oldPlaneX * sin(rotSpeed) + config->player.plane.y * cos(rotSpeed);
		game(config);
	}
	return (0);
}

void key_handler(t_config *config)
{
	mlx_hook(config->win, 17, 0, close_window, config);
	mlx_hook(config->win, 2, 0, key_pressed, config);
	mlx_loop(config->ptr);
}
int main(int argc, char **argv)
{
	t_config game_conf;
	argc = 0;
	game_conf = ft_parse(argv[1]);
	ini_player(&game_conf);
	//ini_game(&game_conf);

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

	//game(&game_conf);
	while (i < game_conf.lines_count + 2)
	{
		j = 0;
		while (game_conf.array[i][j])
		{
			printf("%c", game_conf.array[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}

	//free_struct(&game_conf);

	//key_handler(&game_conf);
}
