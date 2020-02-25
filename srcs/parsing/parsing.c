//
// Created by Anass Sbai el idrissi on 2/17/20.
//

#include "cub3d.h"



t_config    ft_parse(char *path)
{
    t_config    game_conf;

    initialize_conf(&game_conf);
    game_conf.path = path;
    fill_conf_infos(&game_conf);
    return (game_conf);
}

void fill_conf_infos(t_config *game_conf)
{
    int fd_cub;
    char *line;
    int gnl_return;

    line = NULL;
    gnl_return = 1;
    if ((fd_cub = open(game_conf->path, O_RDONLY)) < 0)
        exit(1);
    while (gnl_return > 0)
    {
        gnl_return = get_next_line(fd_cub, &line);
        if (ft_isdigit(*line))
        {
            free(line);
            break;
        }
        ft_fill_conf(line, game_conf);
        free(line);
    }
    set_map(game_conf, line, fd_cub);
}

void    check_line_char(char c, char *line, t_config *game_conf)
{
    while (*line)
    {
        if (*line != c && *line != ' ')
            exit (1);
        line++;
    }
}

void    ft_fill_conf(char *line, t_config *game_conf)
{
    if (ft_strncmp("R ", line, 2) == 0)
        ft_get_resolution(line, game_conf);
    else if (ft_strncmp("NO ",line, 2) == 0)
        game_conf->no_path = ft_get_path(line, game_conf);
    else if (ft_strncmp("SO ", line, 2) == 0)
        game_conf->so_path = ft_get_path(line, game_conf);
    else if (ft_strncmp("WE ", line, 2) == 0)
        game_conf->we_path = ft_get_path(line, game_conf);
    else if (ft_strncmp("EA ", line, 2) == 0)
        game_conf->ea_path = ft_get_path(line, game_conf);
    else if (ft_strncmp("S ", line, 2) == 0)
        game_conf->sprite_path = ft_get_path(line, game_conf);
    else if (ft_strncmp("F ", line, 2) == 0)
        ft_get_RGB(line, &game_conf->floor_colors);
    else if (ft_strncmp("C ", line, 2) == 0)
        ft_get_RGB(line, &game_conf->celling_colors);
    else if (ft_isspace(*line) || *line == '\0');
    else
        free_struct(game_conf);
}