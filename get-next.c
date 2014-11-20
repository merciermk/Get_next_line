/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readfile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmercier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/16 13:31:54 by mmercier          #+#    #+#             */
/*   Updated: 2014/11/20 15:46:33 by mmercier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <fcntl.h>
#include "libft.h"

#define BUFF_SIZE 10

char *ft_readfile (int fd)
{
	int ret;
	int fd_;
	char recept[BUFF_SIZE + 1];
	char *tmp;

	fd_ = fd;
	tmp = malloc(sizeof(char*));

	if (fd_ == -1)
		return (-1);
	
	while ((ret = read(fd_,recept , BUFF_SIZE)))
	{
		recept[ret] = '\0';
		ft_realloc(tmp, BUFF_SIZE);
		tmp = ft_strcat(tmp ,recept);
	}
	ft_putstr("\ntest de char retour\n"); // test
	ft_putstr(tmp); // test	
	return (tmp);
}

char *linebyline()
{
}

int get_next_line(int const fd, char ** line)
{
	
}

