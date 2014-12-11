/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmercier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 11:54:12 by mmercier          #+#    #+#             */
/*   Updated: 2014/11/14 10:18:43 by mmercier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char		*src;
	char		*dst;
	size_t		i;

	src = (char *)s;
	if (src && f)
	{
		dst = ft_strnew(ft_strlen(s));
		i = 0;
		while (src[i] != '\0')
		{
			dst[i] = (*f)(src[i]);
			i++;
		}
		return (dst);
	}
	return (NULL);
}
