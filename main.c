/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmercier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/15 14:43:28 by mmercier          #+#    #+#             */
/*   Updated: 2014/11/24 16:55:04 by mmercier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <fcntl.h>
#include "libft.h"
#include <stdio.h>

int get_next_line(int fd, char **line);

int main()
{
	int fd;
	char *c;
	//int i;

	fd = open("testfile.txt", O_RDONLY);
		
    while((get_next_line(fd, &c)) != 0)
	{
		ft_putendl(c);	
	}
 
 /*
	i = get_next_line(fd, &c);
	ft_putstr(c);
	printf("%d", i);
	i =get_next_line(fd, &c);
	printf("%d", i);
	
	ft_putstr(c);
	printf("%d", i);
	i = get_next_line(fd, &c);
	ft_putstr(c);
	printf("%d", i);
	get_next_line(fd, &c);
	ft_putstr(c);
	printf("%d", i);
	get_next_line(fd, &c);
	ft_putstr(c);
	printf("%d", i);
	get_next_line(fd, &c);
	ft_putstr(c);
	printf("%d", i);
	*/
	return(0);
}
