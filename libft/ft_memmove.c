/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memove.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmercier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 20:44:14 by mmercier          #+#    #+#             */
/*   Updated: 2014/11/09 11:49:55 by mmercier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memmove(void *dst, const void *src, size_t len)
{
	int		i;
	char	*tmp;

	i = ft_strlen(src);
	tmp = (char *)malloc(i);
	ft_memcpy (tmp, src, len);
	ft_memcpy (dst, tmp, len);
	return (dst);
}
