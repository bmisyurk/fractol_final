/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmisyurk <bmisyurk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/23 14:23:12 by bmisyurk          #+#    #+#             */
/*   Updated: 2014/12/03 02:13:54 by bmisyurk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_buffer(char **buf, char **line)
{
	int		len;
	char	*to_free;

	if (ft_strchr(*buf, '\n') != NULL)
	{
		len = ft_strchr(*buf, '\n') - *buf;
		to_free = *line;
		*line = ft_strsub(*buf, 0, len);
		free(to_free);
		to_free = *buf;
		*buf = ft_strdup(ft_strchr(*buf, '\n') + 1);
		free(to_free);
		return (1);
	}
	*line = ft_strdup(*buf);
	ft_strdel(buf);
	return (0);
}

int	read_k(char **line, const int fd, char **buf, char *str)
{
	char	*tmp;
	int		len;
	int		k;

	while ((k = read(fd, str, BUFF_SIZE)))
	{
		if (k == -1)
			return (k);
		str[k] = '\0';
		tmp = *line;
		*line = ft_strjoin(tmp, str);
		(tmp) ? ft_strdel(&tmp) : 0;
		if (ft_strchr(*line, '\n'))
		{
			len = ft_strchr(*line, '\n') - *line;
			*buf = ft_strdup(ft_strchr(*line, '\n') + 1);
			tmp = *line;
			*line = ft_strsub(tmp, 0, len);
			ft_strdel(&tmp);
			break ;
		}
		ft_bzero(str, BUFF_SIZE);
	}
	return (k);
}

int	get_next_line(const int fd, char **line)
{
	int			k;
	static char	*buf[4096];
	char		*str;

	if (fd < 0 || !line || BUFF_SIZE < 0 || (read(fd, NULL, 0) < 0))
		return (-1);
	if (!(str = ft_strnew(BUFF_SIZE)))
		return (-1);
	*line = NULL;
	if (buf[fd] != NULL)
		if (ft_buffer(&buf[fd], line))
		{
			ft_strdel(&str);
			return (1);
		}
	if ((k = read_k(line, fd, &buf[fd], str)) == -1)
		return (-1);
	ft_strdel(&str);
	if (k == 0 && ft_strlen(*line) == 0)
		return (0);
	return (1);
}
