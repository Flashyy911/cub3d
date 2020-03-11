//
// Created by Anass Sbai el idrissi on 2/20/20.
//

#include "cub3d.h"

void free_struct(t_config *game_conf)
{

	free(game_conf->path);
	free(game_conf->no_path);
	free(game_conf->so_path);
	free(game_conf->we_path);
	free(game_conf->ea_path);
	free(game_conf->sprite_path);
 	ft_free(game_conf->array);
    exit(1);
}

void raise_error()
{

    exit(1);
}