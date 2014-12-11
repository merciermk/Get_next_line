/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcpy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmercier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 12:10:27 by mmercier          #+#    #+#             */
/*   Updated: 2014/11/08 11:01:01 by mmercier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*dstc;
	const char	*srcc;
	int			i;

	dstc = (char *)dst;
	srcc = (const char *)src;
	i = 0;
	while (n > 0)
	{
		dstc[i] = srcc[i];
		i++;
		n--;
	}
	return (dst);
}
