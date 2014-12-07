/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonamy <abonamy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/26 14:49:48 by abonamy           #+#    #+#             */
/*   Updated: 2014/11/30 14:26:52 by abonamy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h> // open

int		main(int argc, char **argv)
{
	int		fd1; 		// file descriptor
	int		fd2;
	int		fd3;
	char	*str1;		// buffer
	char	*str2;
	char	*str3;
	int		st1 = 1;	// return of get_next_line
	int		st2 = 1;
	int		st3 = 1;

	if (argc == 1) // STDIN -> ./gnl < file42
	{
		if ((fd1 = open("/dev/stdin", O_RDONLY)) == -1)
			return (1);
		while (get_next_line(fd1, &str1) > 0)
			ft_putendl(str1);
		if (close(fd1) == -1)
			return (1);
	}
	else if (argc == 2) // only one argument -> ./gnl file42
	{
		if ((fd1 = open(argv[1], O_RDONLY)) == -1)
			return (1);
		while (get_next_line(fd1, &str1) > 0)
			ft_putendl(str1);
		if (close(fd1) == -1)
			return (1);
	}
	else if (argc == 3) // for 2 fd -> ./gnl file41 file42
	{
		if (ft_strcmp(argv[1], argv[2]) == 0)
		{
			ft_putendl("Seriously !?");
			return (0);
		}
		if ((fd1 = open(argv[1], O_RDONLY)) == -1)
			return (1);
		if ((fd2 = open(argv[2], O_RDONLY)) == -1)
			return (1);
		while ((st1  > 0) || (st2 > 0))
		{
			if ((st1 = get_next_line(fd1, &str1)) > 0)
				ft_putendl(str1);
			if ((st2 = get_next_line(fd2, &str2)) > 0)
				ft_putendl(str2);
		}
		if (close(fd1) == -1)
			return (1);
		if (close(fd2) == -1)
			return (1);
	}
	else if (argc == 4) // for 3 fd -> ./gnl file41 file42 file43
	{
		if (ft_strcmp(argv[1], argv[2]) == 0 || ft_strcmp(argv[1], argv[3]) == 0
				||ft_strcmp(argv[2], argv[3]) == 0)
		{
			ft_putendl("Seriously !?");
			return (0);
		}
		if ((fd1 = open(argv[1], O_RDONLY)) == -1)
			return (1);
		if ((fd2 = open(argv[2], O_RDONLY)) == -1)
			return (1);
		if ((fd3 = open(argv[3], O_RDONLY)) == -1)
			return (1);
		while ((st1  > 0) || (st2 > 0) || (st3 > 0))
		{
			if ((st1 = get_next_line(fd1, &str1)) > 0)
				ft_putendl(str1);
			if ((st2 = get_next_line(fd2, &str2)) > 0)
				ft_putendl(str2);
			if ((st3 = get_next_line(fd3, &str3)) > 0)
				ft_putendl(str3);
		}
		if (close(fd1) == -1)
			return (1);
		if (close(fd2) == -1)
			return (1);
		if (close(fd3) == -1)
			return (1);
	}
	else
	{
		ft_putendl("Seriously !?");
	}
	return (0);
}
