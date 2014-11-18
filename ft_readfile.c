/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readfile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmercier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/16 13:31:54 by mmercier          #+#    #+#             */
/*   Updated: 2014/11/18 18:24:07 by mmercier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <fcntl.h>
#include "libft.h"

#define BUFF_SIZE 10000

int ft_readfile (int fd)
{
	int ret;
	int fd_;
	char recept[BUFF_SIZE + 1];
	char *tmp;

	fd_ = fd;
	tmp = (char*)malloc(sizeof(char) * (BUFF_SIZE + 1));

	if (fd_ == -1)
		return (-1);
	
	while ((ret = read(fd_,recept , BUFF_SIZE)))
	{
		recept[ret] = '\0';
		tmp  = ft_strcat(tmp ,recept);
		//ft_putstr(recept);
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

