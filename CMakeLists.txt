cmake_minimum_required(VERSION 3.15)
project(Cub3d C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_COMPILER /usr/bin/gcc)

#set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -Werror")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -lmlx -L minilibx_opengl_20191021 -framework OpenGL -framework AppKit")

include_directories(includes)

add_executable(Cub3d includes/cub3d.h includes/get_next_line.h main.c gnl/get_next_line.c gnl/get_next_line_utils.c includes/libft.h srcs/parsing/parsing.c srcs/parsing/filling_utilities.c libft/ft_strncmp.c
        libft/ft_atoi.c libft/ft_isdigit.c libft/ft_isspace.c libft/ft_isalpha.c
        libft/ft_putstr_fd.c
        libft/ft_putendl_fd.c
        libft/ft_putchar_fd.c
        srcs/error_handling/free_struct.c srcs/parsing/map_utilities.c srcs/parsing/utils.c srcs/error_handling/put_error.c srcs/player_utilities/initialize_player.c srcs/sprite/initialize_sprite.c srcs/sprite/sort_sprites.c)
