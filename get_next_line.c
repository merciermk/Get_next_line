/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmercier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/24 13:15:57 by mmercier          #+#    #+#             */
/*   Updated: 2014/11/24 17:22:29 by mmercier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_realloc(void *ptr, size_t size)
{
	char	*res;

	if (ptr == NULL)
		return (malloc(size));
	if (size == 0)
		return (ptr);
	if ((res = (char *)(malloc(size))))
	{
		ft_strncpy(res, (const char *)ptr, ft_strlen((char *)ptr));
		free (ptr);
		return (res);
	}
	return (NULL);
}

char *readline(int fd)
{
	int i;
	char buf[BUFF_SIZE + 1];
	char *str;

	str = ft_strnew(1);
	//	if (*line == NULL)
	//		*line = ft_strnew(1);

	while((i = read(fd, buf, BUFF_SIZE)))
	{
		buf[i] = '\0';
		str = ft_strjoin(str, buf);		
	}
	return(str);
}

int	get_next_line(int const fd, char **line)
{

	*line = readline(fd);
	return(0);
}
