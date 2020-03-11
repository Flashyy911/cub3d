/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asbai-el <asbai-el@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 20:41:11 by asbai-el          #+#    #+#             */
/*   Updated: 2020/02/25 20:41:11 by asbai-el         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


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
    conf->lines_count = -1;
    conf->path = NULL;
    conf->n_sprites = 0;
}