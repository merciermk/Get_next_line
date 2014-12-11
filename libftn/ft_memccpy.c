/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmercier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 21:22:34 by mmercier          #+#    #+#             */
/*   Updated: 2014/11/14 10:16:34 by mmercier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	unsigned char		*srcc;
	unsigned char		*destc;
	unsigned char		i;

	if (!n)
		return (NULL);
	srcc = (unsigned char *)s2;
	destc = (unsigned char *)s1;
	i = (size_t)c;
	while (n)
	{
		if ((*destc++ = *srcc++) == i)
			return (destc);
		n--;
	}
	return (NULL);
}
