/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readfile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmercier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/16 13:31:54 by mmercier          #+#    #+#             */
/*   Updated: 2014/11/22 19:54:11 by mmercier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include "libft.h"
#include <stdio.h>

#define BUFF_SIZE 1

char *ft_readfile (int fd, char *allread)
{
	int ret;
	char recept[BUFF_SIZE + 1];
	char *tmp;

	tmp = (char*)malloc(sizeof(char) + 1);

	while ((ret = read(fd,recept , BUFF_SIZE + 1)))
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
	char					*chr;
	int						mal;

	j = 0;
	c = (char*)malloc(sizeof(char) * 100);
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
	static	char *allread;
	//char *one;
	static int cmpt;

	if(fd == -1)
		return(-1);
	if (allread == NULL)
		allread = ft_readfile(fd, allread);
	*line = oneline(allread, &cmpt);

	return(0);
}
