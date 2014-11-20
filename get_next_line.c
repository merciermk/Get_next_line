/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readfile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmercier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/16 13:31:54 by mmercier          #+#    #+#             */
/*   Updated: 2014/11/20 19:05:33 by mmercier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include "libft.h"

#define BUFF_SIZE 10

char *ft_readfile (int fd)
{
	int ret;
	int fd_;
	char recept[BUFF_SIZE + 1];
	char *tmp;
	
	fd_ = fd;
	tmp = (char*)malloc(sizeof(char*));

	while ((ret = read(fd_,recept , BUFF_SIZE)))
	{
		recept[ret] = '\0';
		//ft_putstr("while readfile"); //test
		ft_realloc(tmp, BUFF_SIZE);
		tmp = ft_strcat(tmp ,recept);
	}
	//ft_putstr("\ntest de char retour\n"); // test
	//ft_putstr(tmp); // test	
	return (tmp);
}

char *ft_oneline(char *src)
{
	char *dst;
	int i;

	i = 0;

	while (src[i] != '\n')
	{
		dst[i] = src[i];
		i++;
	//	ft_putstr("oneline while"); //test
	}
	return (dst);
}

int get_next_line(int const fd, char ** line)
{
	char *allread;
	char *single;

	if(fd == -1)
		return(-1);
	
	allread = ft_readfile(fd);
	single = ft_oneline(allread);



	ft_putstr(single);
	return(0);
}
