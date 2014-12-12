/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmercier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 20:07:49 by mmercier          #+#    #+#             */
/*   Updated: 2014/11/15 11:10:30 by mmercier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!*s2)
		return ((char*)s1);
	while (s1[i] != '\0' && i <= n)
	{
		while (s1[i] == s2[j] && i <= n)
		{
			i++;
			j++;
			if (s2[j] == '\0')
				return ((char*)s1 + i - j);
		}
		i++;
	}
	return (NULL);
}
