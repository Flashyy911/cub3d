/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filling_utilities.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asbai-el <asbai-el@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 20:40:54 by asbai-el          #+#    #+#             */
/*   Updated: 2020/02/25 20:40:54 by asbai-el         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void ft_get_resolution(char *line, t_config *game_conf)
{
    int i;

    i = 1;
    while (ft_isspace(*(line + i)))
        i++;
    if (!ft_isdigit(*(line + i)))
        exit(1);
    game_conf->resl.height = ft_atoi(line + i);
    while (ft_isdigit(*(line + i)))
        i++;
    if (!ft_isspace(*(line + i)))
        exit(1);
    while (ft_isspace(*(line + i)))
        i++;
    if (!ft_isdigit(*(line + i)))
        exit(1);
    game_conf->resl.width = ft_atoi(line + i);
    while (ft_isdigit(*(line + i)) || ft_isspace(*(line + i)))
        i++;
    if (*(line + i) != '\0')
        exit(1);
}

char    *ft_get_path(char *line, t_config *game_conf)
{
    int i;

    i = 0;
    while(ft_isalpha(*(line + i)))
        i++;
    while(ft_isspace(*(line + i)))
        i++;
    return (ft_strdup((line + i)));
}

void    ft_get_RGB(char *line, t_cfcolor *color)
{
    int i;

    i = 1;
    while(ft_isspace(*(line + i)))
        i++;
    color->r = ft_atoi((line + i));
    while (ft_isdigit(*(line + i)))
        i++;
    if (*(line + i++) != ',')
        exit(1);
    color->g = ft_atoi((line + i));
    while (ft_isdigit(*(line + i)))
        i++;
    if (*(line + i++) != ',')
        exit(1);
    color->b = ft_atoi((line + i));
    while (ft_isdigit(*(line + i)))
        i++;
    while(ft_isspace(*(line + i)))
        i++;
    if (*(line + i) != '\0')
        exit (1);
}