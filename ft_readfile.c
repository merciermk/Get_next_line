/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readfile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmercier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/16 13:31:54 by mmercier          #+#    #+#             */
/*   Updated: 2014/11/19 14:05:17 by mmercier         ###   ########.fr       */
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
	ft_putstr("\ntest de char retour\n");
	ft_putstr(tmp);
	
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

