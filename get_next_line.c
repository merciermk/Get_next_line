/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmercier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/24 13:15:57 by mmercier          #+#    #+#             */
/*   Updated: 2014/11/28 12:08:52 by mmercier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "./libft/libft.h"


static void			ft_cut(char **save, char **line)
{
	size_t			len;
	char			*tmp;

	len = ft_strchr(*save, '\n') - *save;
	tmp = *save;
	*line = ft_strsub(tmp, 0, len);
	*save = ft_strdup(tmp + len + 1);
	if ((*save) == NULL)
		ft_strdel(save);
	free(tmp);
}
	static int			ft_eof(char **line, char **save)
	{
		*line = ft_strdup(*save);
		ft_strdel(save);
		return (0);
	}
/*
static int			ft_error(char **save)
{
	if (*save)
		ft_strdel(save);
	return (-1);
}
*/

int	get_next_line(int const fd, char **line)
{
	static char	*save;
	char		*tmp;
	int		r;
	char		buf[BUFF_SIZE + 1];

	r = 0;
	save = NULL;
	tmp = NULL;
	
	if (fd == -1 || BUFF_SIZE <= 0 || r == -1)
		return (-1);
	if (save == NULL)
		save = ft_strnew(BUFF_SIZE + 1);
	while ((ft_strchr(save, '\n') == NULL) && ((r = read(fd, buf, BUFF_SIZE)) > 0))	
	{
		buf[r] = '\0';
		tmp = save;
		save = ft_strjoin(tmp, buf);
		free(tmp);
	}

	if (r < BUFF_SIZE && ft_strchr(save, '\n') == NULL)
		return (ft_eof(line, &save));
	if (r == -1)
		return (-1);
	ft_cut(&save, line);
	return (1);
}
