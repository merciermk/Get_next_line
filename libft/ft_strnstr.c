/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmercier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 20:07:49 by mmercier          #+#    #+#             */
/*   Updated: 2014/12/11 14:45:19 by mmercier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	char	c;
	char	sc;
	size_t	l;
	int		i;

	i = 0;
	if ((c = *s2++) != '\0')
	{
		l = ft_strlen(s2);
		while (!i || ft_strncmp(s1, s2, l) != 0)
		{
			i = 1;
			if ((sc = *s1++) == '\0' || n-- < 1)
				return (NULL);
			while (sc != c)
			{
				if ((sc = *s1++) == '\0' || n-- < 1)
					return (NULL);
			}
			if (l > n)
				return (NULL);
		}
		s1--;
	}
	return ((char *)s1);
}
