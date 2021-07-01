//
// Created by Anass Sbai el idrissi on 2/17/20.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <fcntl.h>
#include "libft.h"
#include "../minilibx_opengl_20191021/mlx.h"
#include "get_next_line.h"

#ifndef CUB3D_CUB3D_H
#define CUB3D_CUB3D_H
#define texWidth 64
#define texHeight 64
# define K_W 13
# define K_A 0
# define K_S 1
# define K_D 2
# define LEFT_ARROW 124
# define RIGHT_ARROW 123
# define TAB 48
# define ESC 53
# define T_WIDTH 64
# define T_HEIGHT 64
typedef struct      s_point
{
    double x;
    double y;
}                   t_point;

typedef struct		s_resolution
{
    int width;
    int height;
}					t_resolution;

typedef struct		s_cfcolor
{
    int r;
    int g;
    int b;
}					t_cfcolor;

typedef struct		s_map
{
    int				*value;
    int				len;
    struct s_map	*next;
}					t_map;

typedef struct      s_player
{
    t_point pos;
    t_point dir;
    t_point plane;
}                   t_player;

typedef struct      s_env
{
    int key[300];
}                   t_env;

typedef struct		s_img
{
	int				bpp;
	int				sl;
	int				e;
	int				*data;
	void			*ptr;
	int				width;
	int				height;
}					t_img;

typedef struct	s_sprite
{
    double x;
    double y;
}				t_sprite;

typedef struct	s_game
{
    double posX;
    double posY;
    double dirX;
    double dirY;
    double planeY;
    double planeX;
    double cameraX;
    double rayDirX;
    double rayDirY;
    int mapX;
    int mapY;
    double sideDistX;
	double sideDistY;
    double deltaDistX;
    double deltaDistY;
    double perpWallDist;
    //what direction to step in x or y-direction (either +1 or -1)
    int stepX;
	int stepY;

	int hit;   //was there a wall game_conf.hit?
	int side;  //was a NS or a EW wall game_conf.hit?
    double wallX; //where exactly the wall was game_conf.hit
    int texX;
    double step;
    int lineHeight;
}				t_game;

typedef struct		s_config
{
    t_resolution	resl;
    int				spawn;
    char			*no_path;
	char			*so_path;
	char			*we_path;
	char			*ea_path;
	char			*sprite_path;
	t_cfcolor		celling_colors;
	t_cfcolor		floor_colors;
	t_cfcolor       rgb;
	void			*ptr;
	void			*win;
	t_img			im;
	t_img			img[5];
	t_player        player;
	t_env           env;
	char            **array;
	int				n_sprites;
	t_sprite		*sprites;
	double			*distance_sprites;
	int				*index_sprites;
	double			*z_buffer;
    char *path;
    int lines_count;
}					t_config;

void        initialize_conf(t_config *conf);
t_config    ft_parse(char *path);

void fill_conf_infos(t_config *game_conf);
void    set_map(t_config *game_conf,char *line, int fd_cub);
char    **ft_free(char **str);
void check_map(t_config *game_conf);
void    ft_fill_conf(char *line, t_config *game_conf);
void    ft_get_resolution(char *line, t_config *game_conf);
char    *ft_get_path(char *line, t_config *game_conf);
void fill_map(t_config *game_conf,char *line, int fd_cub);
void    ft_get_RGB(char *line, t_cfcolor *game_conf);
void    check_line_char(char c, char *line, t_config *game_conf);
void free_struct(t_config *game_conf);
int ft_is_valid(char c);
void ini_player(t_config *config);
char      **ft_realloc(char **arr, char *line);
void		sort_sprites(int n_sprites, double *d_sprite, int *i_sprite);
void ini_sprite(t_config *config);

#endif //CUB3D_CUB3D_H
