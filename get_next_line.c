/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmercier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/24 13:15:57 by mmercier          #+#    #+#             */
/*   Updated: 2014/11/25 12:47:48 by mmercier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"


char *ft_cutpart(char *save, char **line)
{
	while()	
}
int	get_next_line(int const fd, char **line)
{
	static char	*save;
	char		*tmp;
	int			r;
	char		buf[BUFF_SIZE + 1];

	*line = " ";
	r = 1;
	tmp = (char*)malloc(sizeof(char) * BUFF_SIZE + 1);
	if (fd == -1 || BUFF_SIZE <= 0 || r == -1)
		return (-1);
	if (save == NULL)
		save = ft_strnew(BUFF_SIZE + 1);
	while (((r = read(fd, buf, BUFF_SIZE)) > 0) && (ft_strchr(save, '\n') == NULL))
	{
		buf[r] = '\0';
		tmp = save;
		save = ft_strjoin(tmp, buf);
		free(tmp);
	}
	return(0);
}
