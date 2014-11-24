/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readfile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmercier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/16 13:31:54 by mmercier          #+#    #+#             */
/*   Updated: 2014/11/24 17:02:31 by mmercier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

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

char *ft_readfile(int fd)
{
	int ret;
	char recept[BUFF_SIZE + 1];
	char *tmp;

	tmp = (char*)malloc(sizeof(char) + 1);

	while ((ret = read(fd,recept , BUFF_SIZE)))
	{
		recept[ret] = '\0';
		ft_realloc(tmp, BUFF_SIZE);
		tmp = ft_strcat(tmp ,recept);
	}
	return (tmp);
}

char *oneline(char *allread, int *cmpt)
{
	char					*c;
	int						j;
	
	j = 0;
	c = (char*)malloc(sizeof(char) * 999);
	if (allread[*cmpt] == '\n')
		*cmpt += 1;
	while (allread[*cmpt] != '\n' && allread[*cmpt] != '\0')
	{
		c[j] = allread[*cmpt];
		*cmpt += 1;
		j++;
	}
	c[j] = '\0';
	return(c);
}

int get_next_line(int const fd, char **line)
{
	char *allread;
	static int cmpt;

	if (allread == NULL)
		allread = ft_readfile(fd);

	if(fd == -1)
		return(-1);
	*line = oneline(allread, &cmpt);
	if (allread[cmpt] == '\0')
		return (0);
	return (1);
}
