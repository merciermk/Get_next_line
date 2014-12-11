/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmercier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/19 14:24:50 by mmercier          #+#    #+#             */
/*   Updated: 2014/11/20 13:24:19 by mmercier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			nothing(char c)
{
	return ((c == ' ') || (c == '\t') || (c == '\n'));
}

static const char	*s_end(const char *str)
{
	str = str + ft_strlen(str);
	while (nothing(*(str - 1)))
		--str;
	return (str);
}

char				*ft_strtrim(char const *s)
{
	char		*to_return;
	const char	*begin;
	const char	*end;

	if (s == NULL)
		return (NULL);
	begin = s;
	while (nothing(*begin))
		++begin;
	end = s_end(s);
	to_return = ft_strsub(begin, 0, (size_t)(end - begin));
	if (to_return == NULL)
	{
		to_return = (char*)malloc(1);
		to_return[0] = '\0';
	}
	return (to_return);
}
