/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmercier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/15 14:43:28 by mmercier          #+#    #+#             */
/*   Updated: 2014/11/15 14:57:10 by mmercier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <fcntl.h>

ft_readNsave(int fd);

int main()
{
	int fd;
	int retour[12];

	fd = open("testfile.txt", O_RDONLY);

	retour = ft_readNsavefile(fd);

}
