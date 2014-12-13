/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleber <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/21 17:55:19 by hleber            #+#    #+#             */
/*   Updated: 2014/12/13 12:56:26 by hleber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
static char			*ft_mallocat(char *s1, char *s2)
{
	unsigned int		len1;
	unsigned int		len2;
	char				*tmp;

	if (!s1 && s2)
		return (s2);
	if (s1 && !s2)
		return (s1);
	if (!s1 && !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	tmp = NULL;
	tmp = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (!tmp)
		return (NULL);
	while (*s1)
		*tmp++ = *s1++;
	while (*s2)
		*tmp++ = *s2++;
	*tmp = '\0';
	free(s1 - len1);
	return (tmp - len1 - len2);
}
 */

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

static void			ft_get(char **line, char **ptr, int *i, char **str)
{
	*line = *ptr;
	*str += ft_strlen(*str);
	*ptr += ft_strlen(*ptr);
	*i = 1;
}

static void 		ft_end(char **str, char **ptr)
{
	bzero(*str, BUF_SIZE);
	if (ft_strchr(*ptr, '\n') != NULL)
		*str = ft_strncpy(*str, ft_strchr(*ptr, '\n') + 1, BUF_SIZE);
	else
		*str = ft_strncpy(*str, ft_strchr(*ptr, '\n'), BUF_SIZE);		
	free(*ptr);
}

int					get_next_line(int const fd, char **line)
{
	int				i;
	char			*buf;
	static char		*str;
	char			*ptr;

	str = (str == NULL) ? ft_strnew(BUF_SIZE) : str;
	ptr = ft_strncpy(ft_strnew(BUF_SIZE), str, BUF_SIZE);
	if (!line || (buf = (char *)malloc((BUF_SIZE + 1) * sizeof(char))) == NULL)
		return (-1);
	while (!ft_strchr(ptr, '\n'))
	{
		if ((i = read(fd, buf, BUF_SIZE)) < 1)
		{
			if (i == 0 && ft_strlen(ptr) > 0)
			{
				ft_get(line, &ptr, &i, &str);
			}
			return (i);
		}
		buf[i] = '\0';
		ptr = ft_mallocat(ptr, buf);
	}
	free(buf);
	*line = ft_line_read(ptr, '\n');
	ft_end(&str, &ptr);
	return (1);
}
