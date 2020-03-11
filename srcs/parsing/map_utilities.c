//
// Created by Anass Sbai el idrissi on 2/21/20.
//
#include "cub3d.h"


void    set_map(t_config *game_conf,char *line, int fd_cub)
{
    char **tmp;

    game_conf->lines_count = 2;

    game_conf->array = malloc(2 * sizeof(char*));
    game_conf->array[0] = ft_strdup(line);
    game_conf->array[1] = NULL;
    line = NULL;
    while (get_next_line(fd_cub, &line) > 0)
    {
        tmp = game_conf->array;
        game_conf->array = ft_realloc(game_conf->array, line);
        ft_free(tmp);
        free(line);
        line = NULL;
        game_conf->lines_count++;
    }
    free(line);
    game_conf->array = ft_realloc(game_conf->array, line);
    if (game_conf->lines_count < 3)
        exit(1);
    check_map(game_conf);
}

char    **ft_free(char **str)
{
    int i;
    i = 0;
    while (str[i] != NULL)
    {
        free(str[i]);
        str[i++] = NULL;
    }
    free(str);
    return (NULL);
}

static  int    arr_count(char **arr)
{
    int i;
    i = 0;
    while (arr[i])
        i++;
    return (i);
}
char      **ft_realloc(char **arr, char *line)
{
    char   **newarr;
    int       count;
    int       i;
    i = 0;
    count = arr_count(arr);
    newarr = malloc((count + 2) * sizeof(char*));
    while (i < count)
    {
        newarr[i] = ft_strdup(arr[i]);
        i++;
    }
    newarr[i] = ft_strdup(line);
    newarr[i + 1] = NULL;
    return (newarr);
}

int check_value(char c)
{
    if (c == '1' || c == '0' || ft_is_valid(c) == 1 || c == '2')
        return (1);
    return (0);
}

int check_line(char **array, int i, int j, char value)
{
    if (i > 0 && array[i][j] == value && (!check_value(array[i + 1][j]) || !check_value(array[i - 1][j]) || !check_value(array[i][j - 1]) || !check_value(array[i][j + 1])))
        return (1);
    return (0);
}

int fl_line(char *line)
{
    int i;

    i = 0;
    while (line[i])
    {
        if (line[i] != '1' && line[i] != ' ')
            return (-1);
        i++;
    }
    return (i);
}

void check_map(t_config *game_conf)
{
    int i;
    int j;

    i = 0;
    while (i < game_conf->lines_count - 1)
    {
        j = 0;
        if (check_value(game_conf->array[i][j]) == 0 && game_conf->array[i][j] != ' ')
        {
            printf("err");
            exit(1);
        }
        if (i == 0 && fl_line(game_conf->array[i]) == -1)
        {
            printf("ewpp");
            exit(1);
        }
        while (game_conf->array[i][j])
        {
            if (j == 0 && game_conf->array[i][j] != ' ' && game_conf->array[i][j] != '1')
            {
                printf("ew");
                exit(1);
            }
            if (check_line(game_conf->array, i, j, '0') ||
            check_line(game_conf->array, i, j, '2') ||
            (ft_is_valid(game_conf->array[i][j]) == 1 &&
            check_line(game_conf->array, i, j, game_conf->array[i][j])))
            {
                printf("ew");
                exit(1);
            }
            j++;
        }
        i++;
    }
    if (fl_line(game_conf->array[i]) == -1)
    {
        printf("ewp=");
        exit(1);
    }
}

int ft_is_valid(char c)
{
    if (c == 'N' || c == 'W' || c == 'S' || c == 'E')
        return (1);
    else if (c == '1' || c == '0' || c == '2')
        return (2);
    return (0);
}