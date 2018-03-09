/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvertohr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 13:40:04 by tvertohr          #+#    #+#             */
/*   Updated: 2017/12/14 16:56:01 by tvertohr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			line_cut(char **ourlines, char **line)
{
	char			*new_line;
	int				size_of_line;
	int				diff;

	new_line = ft_strchr(*ourlines, LEND);
	if (new_line != 0)
	{
		size_of_line = ft_strlen(new_line);
		diff = new_line - *ourlines;
		*line = ft_strsub(*ourlines, 0, diff);
		ft_memmove(*ourlines, ++new_line, size_of_line);
		new_line = NULL;
		return (T);
	}
	return (F);
}

static void			join(char **ourlines, char *ourbuffer)
{
	char			*new_line;

	new_line = NULL;
	new_line = ft_strdup(*ourlines);
	ft_memdel((void **)ourlines);
	*ourlines = ft_strjoin(new_line, ourbuffer);
	ft_memdel((void **)&new_line);
}

static int			inf_reader(int fd, char **ourlines,
								char **line, char *ourbuffer)
{
	int				res_of_read;
	int				res_of_check;

	while ((res_of_read = read(fd, ourbuffer, BUFF_SIZE)))
	{
		if (res_of_read < 0)
			return (ERROR);
		*(ourbuffer + res_of_read) = SEND;
		if (*ourlines)
			join(ourlines, ourbuffer);
		else if (!*ourlines)
			*ourlines = ft_strdup(ourbuffer);
		res_of_check = line_cut(ourlines, line);
		if (res_of_check)
			return (T);
	}
	return (F);
}

int					get_next_line(int const fd, char **line)
{
	int				read_resalt;
	char			ourbuffer[BUFF_SIZE + 1];
	static char		*ourlines[MAX];
	int				r;

	if (!line || fd < 0 || fd > MAX || BUFF_SIZE <= 0 ||
		(r = read(fd, ourbuffer, 0)) < 0)
		return (ERROR);
	if (!(ourlines[fd]) && (ourlines[fd] = ft_strnew(0)) == NULL)
		return (ERROR);
	else if (*(ourlines + fd) && line_cut(&*(ourlines + fd), line))
		return (1);
	read_resalt = inf_reader(fd, &*(ourlines + fd), line, ourbuffer);
	if (read_resalt != 0)
		return (read_resalt);
	else if (!(*(ourlines + fd)) || *(*(ourlines + fd)) == SEND)
		return (0);
	*line = *(ourlines + fd);
	*(ourlines + fd) = NULL;
	return (1);
}
