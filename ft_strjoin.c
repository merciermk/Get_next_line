/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleber <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 15:54:40 by hleber            #+#    #+#             */
/*   Updated: 2014/11/17 13:42:53 by hleber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*to_return;
	size_t	i;

	if (s1 == NULL || s2 == NULL)
	{
		if (s1 == NULL && s2 == NULL)
			return (NULL);
		else if (s1 == NULL)
			return (ft_strdup(s2));
		else
			return (ft_strdup(s1));
	}
	i = ft_strlen(s1) + ft_strlen(s2);
	to_return = (char *)malloc((i + 1) * sizeof(char));
	if (to_return == NULL)
		return (NULL);
	ft_strcpy(to_return, s1);
	ft_strcat(to_return, s2);
	to_return[i] = '\0';
	return (to_return);
}
