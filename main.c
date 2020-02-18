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
}
