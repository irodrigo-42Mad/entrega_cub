/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irodrigo <irodrigo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 17:07:08 by jdiaz-co          #+#    #+#             */
/*   Updated: 2021/03/26 12:07:48 by irodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./cub3d_bonus.h"

static int	fill_char(char **s, char **line, int fd)
{
	int		i;
	char	*aux;

	i = 0;
	while (s[fd][i] != '\n' && s[fd][i] != '\0')
		i++;
	if (s[fd][i] == '\n')
	{
		*line = ft_substr(s[fd], 0, i);
		aux = ft_strdup(s[fd] + i + 1);
		free(s[fd]);
		s[fd] = aux;
	}
	else if (s[fd][i] == '\0')
	{
		*line = ft_strdup(s[fd]);
		free(s[fd]);
		s[fd] = NULL;
		return (0);
	}
	return (1);
}

static int	result(int r, char **s, char **line, int fd)
{
	if (r < 0)
		return (-1);
	else if (r == 0 && (s[fd] == NULL || s[fd][0] == '\0'))
	{
		*line = ft_strdup("");
		free(s[fd]);
		s[fd] = NULL;
		return (0);
	}
	return (fill_char(s, line, fd));
}

int	get_next_line(int fd, char **line)
{
	t_text		*data;
	static char	*s[4096];

	data = ft_calloc(1, sizeof(t_text));
	data->buffer = malloc(sizeof(char *) * BUFFER_SIZE + 1);
	if (!data->buffer || fd < 0 || line == NULL)
		return (-1);
	data->r = read(fd, data->buffer, BUFFER_SIZE);
	while (data->r > 0)
	{
		data->buffer[data->r] = '\0';
		if (s[fd] == NULL)
			s[fd] = ft_strdup(data->buffer);
		else
		{
			data->aux = ft_strjoin(s[fd], data->buffer);
			free(s[fd]);
			s[fd] = data->aux;
		}
		if (ft_strchr(s[fd], '\n'))
			break ;
		data->r = read(fd, data->buffer, BUFFER_SIZE);
	}
	free(data->buffer);
	return (result(data->r, s, line, fd));
}
