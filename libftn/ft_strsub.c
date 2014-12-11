/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmercier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/13 20:34:17 by mmercier          #+#    #+#             */
/*   Updated: 2014/11/14 10:24:20 by mmercier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*to_return;

	if (s == NULL)
		return (NULL);
	i = 0;
	to_return = (char*)malloc((len + 1) * sizeof(char));
	if (to_return == NULL)
		return (NULL);
	while (i < len && s[(size_t)start + i] != '\0')
	{
		to_return[i] = s[(size_t)start + i];
		i++;
	}
	to_return[len] = '\0';
	return (to_return);
}
