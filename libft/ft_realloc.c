/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmercier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/09 18:48:54 by mmercier          #+#    #+#             */
/*   Updated: 2014/12/11 14:39:04 by mmercier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_realloc(void *ptr, size_t size)
{
	char *tmp;

	tmp = (char*)malloc(sizeof(ptr) * ft_strlen(ptr));
	if (!tmp)
		return (NULL);
	ft_memcpy(tmp, ptr, ft_strlen(ptr));
	ptr = (char*)malloc(sizeof(char*) * size);
	if (!ptr)
		return (NULL);
	ft_memcpy(ptr, tmp, ft_strlen(tmp));
	free(tmp);
	return (ptr);
}
