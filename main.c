/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmercier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/15 14:43:28 by mmercier          #+#    #+#             */
/*   Updated: 2014/11/20 17:19:28 by mmercier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <fcntl.h>

int get_next_line(int fd, char **line);

int main()
{
	int fd;
	int retour;
	char **c;

	fd = open("testfile.txt", O_RDONLY);

	retour = get_next_line(fd, c);

}
