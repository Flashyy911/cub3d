/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asbai-el <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 09:28:49 by asbai-el          #+#    #+#             */
/*   Updated: 2020/01/19 20:10:16 by asbai-el         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

static int			malloc_file_content(char **file_content, int *j, int fd,
		char ***line)
{
	if (*line == NULL)
		return (-1);
	if (!(**line = ft_strdup("")))
		return (-1);
	*j = 1;
	if (!*(file_content))
	{
		if (fd < 0 || fd > 4068)
			return (-1);
		if (!(*(file_content) = malloc(BUFFER_SIZE + 1)))
			return (-1);
		*j = read(fd, *(file_content), BUFFER_SIZE);
		*(file_content[0] + *j) = '\0';
		if (j <= 0)
			return (*j);
	}
	return (0);
}

static int			read_file_content(int fd, char **file_content,
		int *j, int *i)
{
	*j = read(fd, *(file_content), BUFFER_SIZE);
	*(file_content[0] + *j) = '\0';
	if (*j == 0)
		*(file_content[0]) = '\0';
	*i = 0;
	if (*j < 0)
		free(*file_content);
	return (*j);
}

void				free_null(char **str)
{
	free(*str);
	*str = NULL;
}

int					get_next_line(int fd, char **line)
{
	static char	*file_content;
	int			j;
	int			i;

	i = 0;
	if ((malloc_file_content(&file_content, &j, fd, &line)) == -1)
		return (-1);
	while ((*(file_content + i) != '\n'))
	{
		if (*(file_content + i) == '\0')
			if (read_file_content(fd, &file_content, &j, &i) == -1)
				return (-1);
		if (j <= 0)
			break ;
		if (*(file_content + i) != '\n')
			*line = ft_strcharjoin(line, (file_content + i), &i);
	}
	file_content = ft_memccpy(file_content, file_content + i + 1, '\n',
			ft_strlen(file_content));
	if (j <= 0 || (file_content[0] == '\0' && *line[0] == '\0' && j == 0))
	{
		free_null(&file_content);
		return (j == 0 || *line[0] == '\0') ? 0 : -1;
	}
	return (1);
}
