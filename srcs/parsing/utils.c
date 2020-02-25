//
// Created by Anass Sbai el idrissi on 2/21/20.
//

#include "cub3d.h"

void initialize_conf(t_config *conf)
{
    conf->no_path = NULL;
    conf->we_path = NULL;
    conf->ea_path = NULL;
    conf->so_path = NULL;
    conf->sprite_path = NULL;
    conf->resl.width = 0;
    conf->resl.height = 0;
    conf->celling_colors.r = -1;
    conf->celling_colors.g = -1;
    conf->celling_colors.b = -1;
    conf->floor_colors.r = -1;
    conf->floor_colors.g = -1;
    conf->floor_colors.b = -1;
    conf->spawn = 0;
    conf->player.dir.x =-1;
    conf->player.dir.y =-1;
    conf->player.plane.x =-1;
    conf->player.plane.y =-1;
    conf->player.pos.x =-1;
    conf->player.pos.y =-1;
    conf->map_arr = NULL;
    conf->columns_count = -1;
    conf->lines_count = -1;
    conf->path = NULL;
    //conf->map = NULL;
}