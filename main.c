/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmercier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/15 14:43:28 by mmercier          #+#    #+#             */
/*   Updated: 2014/11/22 19:36:27 by mmercier         ###   ########.fr       */
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
    char retour;
    char retour2;
    char retour3;

	fd = open("testfile.txt", O_RDONLY);

		
    //while(get_next_line(fd, &c) > 0);
	//	ft_putstr(c);
	//	ft_putchar('\n');
   
	get_next_line(fd, &c);
	ft_putstr(c);
	ft_putstr("passage 2 :\n");
	get_next_line(fd, &c);
	ft_putstr(c);

	return(0);
}
