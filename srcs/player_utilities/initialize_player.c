/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_player.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asbai-el <asbai-el@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 20:38:50 by asbai-el          #+#    #+#             */
/*   Updated: 2020/02/26 21:06:58 by asbai-el         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void ini_dir(char dir, t_player *player)
{
	if (dir == 'N')
	{
		player->dir.x = 0;
		player->dir.y = -1;
	}
	else if (dir == 'W')
	{
		player->dir.x = -1;
		player->dir.y = 0;
	}
	else if (dir == 'S')
	{
		player->dir.x = 0;
		player->dir.y = 1;
	}
	else if (dir == 'E')
	{
		player->dir.x = 1;
		player->dir.y = 0;
	}
}

void ini_plane(char dir, t_player *player)
{
	if (dir == 'N')
	{
		player->plane.x = 0.66;
		player->plane.y = 0;
	}
	else if (dir == 'W')
	{
		player->plane.x = 0;
		player->plane.y = -0.66;
	}
	else if (dir == 'S')
	{
		player->plane.x = -0.66;
		player->plane.y = 0;
	}
	else if (dir == 'E')
	{
		player->plane.x = 0;
		player->plane.y = 0.66;
	}
}

void ini_player(t_config *config)
{
	int i;
	int j;


	i = 0;
	while (config->array[i])
	{
		j = 0;
		while (config->array[i][j])
		{
			if (ft_is_valid(config->array[i][j]) == 1)
			{
				config->player.pos.x = j + 0.5;
				config->player.pos.y = i + 0.5;
				ini_dir(config->array[i][j], &config->player);
				ini_plane(config->array[i][j], &config->player);
				config->array[i][j] = '0';
				return ;
			}
			j++;
		}
		i++;
	}
}