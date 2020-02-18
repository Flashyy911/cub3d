cmake_minimum_required(VERSION 3.15)
project(Cub3d C)

set(CMAKE_C_STANDARD 99)


#set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -Werror")
include_directories(includes)
add_executable(Cub3d includes/cub3d.h includes/get_next_line.h main.c gnl/get_next_line.c gnl/get_next_line_utils.c includes/libft.h srcs/parsing/parsing.c srcs/parsing/filling_utilities.c libft/ft_strncmp.c
        libft/ft_atoi.c libft/ft_isdigit.c libft/ft_isspace.c libft/ft_isalpha.c)
