/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleber <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/21 17:55:19 by hleber            #+#    #+#             */
/*   Updated: 2014/12/12 15:07:10 by hleber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char			*ft_line_read(char *str, char end)
{
	size_t			i;
	char			*line;

	i = 0;
	while (str[i] != end)
		i++;
	line = (char *)malloc((i + 1) * sizeof(char));
	i = 0;
	while (str[i] != end)
	{
		line[i] = str[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

static void			ft_get(char **line, char **str, int *i)
{
	*line = *str;
	*str += ft_strlen(*str);
	*i = 1;
}

int					get_next_line(int const fd, char **line)
{
	int				i;
	char			*buf;
	static char		*str;
	char			*ptr;
	char			end;

	str = (str == NULL) ? ft_strnew(BUF_SIZE) : str;
	ptr = ft_strncpy(ft_strnew(BUF_SIZE), str, BUF_SIZE);
	if (!line || (buf = (char *)malloc((BUF_SIZE + 1) * sizeof(char))) == NULL)
		return (-1);
	while (!ft_strchr(ptr, '\n'))
	{
		if ((i = read(fd, buf, BUF_SIZE)) < 1)
		{
			if (i == 0 && ft_strlen(ptr) > 0)				
				ft_get(line, &ptr, &i);
			return (i);
		}
		buf[i] = '\0';
		ptr = ft_mallocat(ptr, buf);
	}
	free(buf);
	end = '\n';
	*line = ft_line_read(ptr, end);
	bzero(str, BUF_SIZE);
	if (ft_strchr(ptr, '\n') != NULL)
		str = ft_strncpy(str, ft_strchr(ptr, '\n') + 1, BUF_SIZE);
	else
		str = ft_strncpy(str, ft_strchr(ptr, '\n'), BUF_SIZE);
	free(ptr);
	return (1);
}
