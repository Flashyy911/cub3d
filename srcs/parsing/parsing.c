//
// Created by Anass Sbai el idrissi on 2/17/20.
//

#include "cub3d.h"
#include <fcntl.h>


t_config    ft_parse(char *path)
{
    t_config    game_conf;

    int len;
    int count;

    initialize_conf(&game_conf);
    fill_conf_infos(&game_conf, path);
   // fill_map(&game_conf);
    return (game_conf);
}

void fill_conf_infos(t_config *game_conf, char *path)
{
    int fd_cub;
    char *line;
    int gnl_return;
    int lines_count;

    line = NULL;
    lines_count = 2;
    gnl_return = 1;
    if (!(fd_cub = open(path, O_RDONLY)))
        exit(1);
    while (gnl_return)
    {
        gnl_return = get_next_line(fd_cub, &line);
        if (ft_isdigit(*line))
        {
            while (get_next_line(fd_cub, &line))
                lines_count++;
            break;
        }
        ft_fill_conf(line, game_conf);
    }
    printf("%d\n", lines_count);
    free(line);
    close(fd_cub);
    //fill_map(game_conf, path, line, fd_cub, gnl_return);
}

void    fill_map(t_config *game_conf, char *path,char *line, int fd_cub, int gnl_return)
{
    int j;
    int i;
    int count;

    line = NULL;
    j = 0;
    i = 0;
    gnl_return = 2;
    if (!(fd_cub = open(path, O_RDONLY)))
        exit(1);
    while (gnl_return)
    {
        gnl_return = get_next_line(fd_cub, &line);
        game_conf->map_arr[j] = malloc(ft_strlen(line));
        if (*line != 1)
            exit(1);
        if (i == 0) {
            check_line_char('1', line, game_conf);
        }
        while (*line + i++)
            game_conf->map_arr[j][i] = *(line + i);
        if (*line != i - 1)
            exit(1);
        j++;
    }
        check_line_char('1', line, game_conf);
}

void    check_line_char(char c, char *line, t_config *game_conf)
{
    while (*line)
    {
        if (*line != c)
            exit (1);
        line++;
    }
}

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
    //conf->map = NULL;
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
        exit(1);
}