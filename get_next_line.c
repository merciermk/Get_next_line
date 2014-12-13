/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmercier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/24 13:15:57 by mmercier          #+#    #+#             */
/*   Updated: 2014/12/13 14:58:13 by mmercier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void			ft_cut(char **save, char **tmp)
{
	bzero(*save, BUFF_SIZE);
	if (ft_strchr(*tmp, '\n') != NULL)
		*save = ft_strncpy(*save, ft_strchr(*tmp, '\n') + 1, BUFF_SIZE);
	else
		*save = ft_strncpy(*save, ft_strchr(*tmp, '\n'), BUFF_SIZE);
	free(*tmp);
}

static void			verif(char **line, char **save, int *r)
{
	*line = *save;
	*save = *save + ft_strlen(*save);
	*r = 1;
}

static int			ft_init_gnl(char **save, char **buf)
{
	*buf = (char*)malloc(sizeof(char) * (BUFF_SIZE + 1));
	if (*buf == NULL)
		return (-1);
	if (*save == NULL)
	{
		*save = (char *)malloc((BUFF_SIZE + 1) * sizeof(char));
		if (*save == NULL)
			return (-1);
	}
	return (1);
}

static char			*ft_line_read(char *tmp, char end)
{
	size_t			t;
	char			*line;

	i = 0;
	while (tmp[t] != end)
		t++;
	line = (char *)malloc((i + 1) * sizeof(char));
	i = 0;
	while (tmp[t] != end)
	{
		line[i] = tmp[i];
		t++;
	}
	line[t] = '\0';
	return (line);
}

int					get_next_line(int const fd, char **line)
{
	static char				*save;
	int						r;
	char					*buf;
	char					*tmp;

	if (fd == -1 || line == NULL)
		return (-1);
	if (ft_init_gnl(&save, &buf) == -1)
		return (-1);
	tmp = ft_strncpy(ft_strnew(BUFF_SIZE), save, BUFF_SIZE);
	while (!(ft_strchr(tmp, '\n')))
	{
		if ((r = read(fd, buf, BUFF_SIZE)) < 1)
		{
			if (r == 0 && ft_strlen(tmp) > 0)
				verif(line, &tmp, &r);
			return (r);
		}
		buf[r] = '\0';
		tmp = ft_mallocat(tmp, buf);
	}
	free(buf);
	*line = ft_line_read(tmp, '\n');
	ft_cut(&save, &tmp);
	return (1);
}
