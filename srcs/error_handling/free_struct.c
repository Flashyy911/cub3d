//
// Created by Anass Sbai el idrissi on 2/20/20.
//

#include "cub3d.h"

void free_struct(t_config *game_conf)
{
    int i = 0;

    free(game_conf->no_path);
    free(game_conf->we_path);
    free(game_conf->ea_path);
    free(game_conf->sprite_path);
    while (i < game_conf->lines_count )
            free(game_conf->map[i++]);
    free(game_conf->map);
    exit(1);
}

void raise_error()
{

    exit(1);
}