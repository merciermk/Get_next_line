/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmercier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/24 13:15:57 by mmercier          #+#    #+#             */
/*   Updated: 2014/12/12 22:26:13 by mmercier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void		ft_cut(char **save, char **line)
{
	size_t					len;
	char					*tmp;

	len = ft_strchr(*save, '\n') - *save;
	tmp = *save;
	*line = ft_strsub(tmp, 0, len);
	*save = ft_strdup(tmp + len + 1);
	free(tmp);
}

static void		verif(char **line, char **save, int *r)
{
	*line = *save;
	*save = *save + ft_strlen(*save);
	*r = 1;
}

static int		ft_init_gnl(char **save, char **buf)
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

int			get_next_line(int const fd, char **line)
{
	static char				*save;
	char					*tmp;
	int						r;
	char					*buf;

	if (fd == -1 || line == NULL)
		return (-1);
	if (ft_init_gnl(&save, &buf) == -1)
		return (-1);
	tmp = ft_strdup(save);
	bzero(save, BUFF_SIZE);
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
	save = ft_strdup(tmp);
	free(tmp);
	ft_cut(&save, line);
	return (1);
}
