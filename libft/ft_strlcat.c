/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmercier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 14:12:37 by mmercier          #+#    #+#             */
/*   Updated: 2014/11/11 18:06:25 by mmercier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *s1, const char *s2, size_t size)
{
	char		*dst_cpy;
	const char	*src_cpy;
	size_t		i;
	size_t		dlen;

	dst_cpy = (char *)s1;
	src_cpy = (char *)s2;
	i = size;
	while (i-- != 0 && *dst_cpy != '\0')
		++dst_cpy;
	dlen = dst_cpy - s1;
	i = size - dlen;
	if (i == 0)
		return (dlen + ft_strlen(src_cpy));
	while (*src_cpy != '\0')
	{
		if (i != 1)
		{
			*dst_cpy++ = *src_cpy;
			i--;
		}
		src_cpy++;
	}
	*dst_cpy = '\0';
	return (dlen + (src_cpy - s2));
}
