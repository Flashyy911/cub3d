/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asbai-el <asbai-el@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 19:18:42 by asbai-el          #+#    #+#             */
/*   Updated: 2020/02/25 20:13:55 by asbai-el         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"

int main(int argc, char **argv)
{
	t_config game_conf;
	argc = 0;
	game_conf = ft_parse(argv[1]);

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

	while (i < game_conf.lines_count)
	{
		j = 0;
		while (j < game_conf.columns_count)
		{
			printf("%d ", game_conf.map[i][j]);
			j++;
		}
		printf("\n");
		i ++;
	}
	free_struct(&game_conf);
}
