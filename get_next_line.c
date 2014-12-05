/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmercier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/24 13:15:57 by mmercier          #+#    #+#             */
/*   Updated: 2014/12/02 15:44:39 by mmercier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "./libft/libft.h"

static int	ft_end(char **line, char **save)
{
	*line = ft_strdup(*save);
	ft_strdel(save);
	return (0);
}

char				*ft_strduplicate(const char *s1)
{
	int		i;
	int		j;
	char	*s2;

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
	size_t			len;
	char			*tmp;

	len = ft_strchr(*save, '\n') - *save;
	tmp = *save;
	*line = ft_strsub(tmp, 0, len);
	*save = ft_strduplicate(tmp + len + 1);
	if ((*save) == NULL)
				ft_strdel(save);
	free(tmp);
}

int					get_next_line(int const fd, char **line)
{
	static char	*save;
	char		*tmp;
	int			r;
	char		*buf;

	r = 0;
	buf = (char*)malloc(sizeof(char) * BUFF_SIZE + 1);
	if (fd < 0 || BUFF_SIZE <= 0 || r == -1 || line == NULL)
		return (-1);
	if (fd == 0)
		return (0);
	if (save == NULL)
		save = ft_strnew(BUFF_SIZE + 1);
	while ((save != NULL && ft_strchr(save, '\n') == NULL && ((r = read(fd, buf, BUFF_SIZE)) > 0)))
	{
		buf[r] = '\0';
		tmp = save;
		save = ft_strjoin(tmp, buf);
		free(tmp);
	}
	if (r < 0)
		return (-1);
	if (r < BUFF_SIZE && ft_strchr(save, '\n') == NULL)
		return(ft_end(line, &save));
	ft_cut(&save, line);
	return (1);
}
