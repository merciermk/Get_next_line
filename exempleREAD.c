/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readNsavefile.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmercier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/15 15:08:16 by mmercier          #+#    #+#             */
/*   Updated: 2014/11/15 17:09:55 by mmercier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
  
#include "libft.h"
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFF_SIZE 1

int ft_readNsavefile (int fd)
{
	int ret;
	char recept[BUFF_SIZE + 1];
	int fd_;
	char *line;
	fd_ = fd;

	fichier test = 10 octet = 10 char = 10 BUFF_SIZE
	while (ret = (read(fd,recept,BUFF_SIZE)))
	{
		recept[ret] = '\0';
		putstr(recept);
	}

		
		
		=
	while ((ret = (read(..))) != NULL)
	=
	while (read(...) != NULL)
	=
	while (read(...))

	ret[recept] = '\0';
	return (ret);
}

int main()
{
	int fd;
	int retour;

	fd = open("testfile.txt", O_RDONLY);


	retour = ft_readNsavefile (fd);
	return (0);
}
