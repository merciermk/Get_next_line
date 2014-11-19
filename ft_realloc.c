/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmercier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/19 11:07:30 by mmercier          #+#    #+#             */
/*   Updated: 2014/11/19 13:38:15 by mmercier         ###   ########.fr       */
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
	return (ptr);
}
