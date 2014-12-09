/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmercier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/24 13:15:57 by mmercier          #+#    #+#             */
/*   Updated: 2014/12/09 13:07:47 by mmercier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char				*ft_strduplicate(const char *s1)
{
	int						i;
	int						j;
	char					*s2;

	if (!s1)
		return (NULL);
	i = ft_strlen(s1);
	s2 = (char *)malloc(sizeof(char) * (i + 1));
	if (!s2)
		return (NULL);
	j = 0;
	while (j < i)
	{
		s2[j] = s1[j];
		j++;
	}
	s2[j] = '\0';
	return (s2);
}

static void			ft_cut(char **save, char **line)
{
	size_t					len;
	char					*tmp;

	len = ft_strchr(*save, '\n') - *save;
	tmp = *save;
	*line = ft_strsub(tmp, 0, len);
	*save = ft_strduplicate(tmp + len + 1);
	if ((*save) == NULL)
		ft_strdel(save);
	free(tmp);
}

static int			verif(char **line, char **save, int r)
{
	if (r == 0 && (ft_strchr(*save, '\n') == NULL))
	{
		*line = *save;
        *save = ft_realloc(*save, ft_strlen(*save) + 1);
		*save = *save + ft_strlen(*save);
        return (0);
	}
	return (r);
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

int					get_next_line(int const fd, char **line)
{
	static char				*save;
	char					*tmp;
	int						r;
	char					*buf;
    
    r = 1;
	if (fd == -1 || line == NULL)
		return (-1);
	if (ft_init_gnl(&save, &buf) == -1)
		return (-1);
	while ((save != NULL && ft_strchr(save, '\n') == NULL &&
				((r = read(fd, buf, BUFF_SIZE)) > 0)))
	{
		buf[r] = '\0';
		tmp = save;
		save = ft_strjoin(tmp, buf);
        //free(tmp);
	}
	if (r < 1)
		return (verif(line, &save, r));
	ft_cut(&save, line);
	//free(tmp);
	free(buf);
	return (1);
}
