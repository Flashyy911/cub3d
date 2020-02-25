//
// Created by Anass Sbai el idrissi on 2/21/20.
//
#include "cub3d.h"



void    set_map(t_config *game_conf,char *line, int fd_cub)
{
    int lines_count;
    int columns_count;
    int i;

    i = -1;
    columns_count = 0;
    while (*(line + ++i))
        if (*(line + i) == '1')
            columns_count++;
    lines_count = 2;
    while (get_next_line(fd_cub, &line))
    {
        free(line);
        lines_count++;
    }
    close(fd_cub);
    game_conf->map = malloc(lines_count * sizeof(int*));
    i = 0;
    while(i < lines_count)
        game_conf->map[i++] = malloc(columns_count * sizeof(int));
    game_conf->columns_count = columns_count;
    game_conf->lines_count = lines_count;
    fill_map(game_conf, line, fd_cub);
}

void fill_map(t_config *game_conf,char *line, int fd_cub)
{
    int i;
    int j;
    int columns_count_check;
    int k;

    k = 1;
    i = 0;
    if (!(fd_cub = open(game_conf->path, O_RDONLY)))
        exit(1);
    while (get_next_line(fd_cub, &line) > 0)
    {
        free(line);
        if (ft_isdigit(*line))
            break;
    }
    if (!ft_isdigit(*line))
        free_struct(game_conf);
    check_line_char('1', line, game_conf);
    while(k >= 0)
    {
        columns_count_check = 0;
        j = 0;
        while(j < ft_strlen(line))
        {
            if (ft_is_valid(*(line + j)) && ft_isdigit(*(line + j)))
                game_conf->map[i][columns_count_check++] = *(line + j) - '0';
            else if (ft_is_valid(*(line + j)))
                game_conf->map[i][columns_count_check++] = *(line + j);
            if (game_conf->spawn && ft_is_valid(*(line + j)) == 1)
                exit(1);
            if (ft_is_valid(*(line + j)) == 1)
                game_conf->spawn = 1;
            j++;
        }
        if (columns_count_check != game_conf->columns_count)
            exit(1);
        if (*(line + j - 1) != '1' || *line != '1')
            exit(1);
        i++;
        if (k == 0 || k == -1)
            break;
        k = get_next_line(fd_cub, &line);

    }
    check_line_char('1', line, game_conf);
}

int ft_is_valid(char c)
{
    if (c == 'N' || c == 'W' || c == 'S' || c == 'E')
        return (1);
    else if (c == '1' || c == '0' || c == '2')
        return (2);
    return (0);
}