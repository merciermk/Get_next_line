/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmercier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 09:43:34 by mmercier          #+#    #+#             */
/*   Updated: 2014/11/10 16:02:24 by mmercier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memalloc(size_t size)
{
	int		i;
	int		j;
	char	*alloc;

	alloc = malloc(size);
	i = 0;
	j = size;
	if (j == 0)
		return (NULL);
	if (alloc != NULL)
	{
		while (i < j)
		{
			alloc[i] = 0;
			i++;
		}
		return ((void*)alloc);
	}
	return (NULL);
}
