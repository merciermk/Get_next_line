/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readfile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmercier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/16 13:31:54 by mmercier          #+#    #+#             */
/*   Updated: 2014/11/18 14:02:25 by mmercier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <fcntl.h>
#include "libft.h"

#define BUFF_SIZE 10

int ft_readfile (int fd)
{
	int ret;
	int fd_;
	char recept[BUFF_SIZE + 1];
	char *retour;

	fd_ = fd;

	if (fd_ == -1)
		return (-1);
	
	while (ret = read(fd_,recept , BUFF_SIZE))
	{
		recept[ret] = '\0';
		retour = (char *)malloc(sizeof(char) + (BUFF_SIZE + 1));
		retour = ft_strcat(retour ,recept);
		ft_putstr(recept);
	}
	ft_putstr("test de char retour\n");
	ft_putstr(retour);
	return (ret);
}

int main()
{
	int fd;
	int retour;

	fd = open("testfile.txt", O_RDONLY);

	retour = ft_readfile (fd);
	ft_putnbr(retour);
	return (0);
}

