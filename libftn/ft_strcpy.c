/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmercier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 13:37:36 by mmercier          #+#    #+#             */
/*   Updated: 2014/11/11 18:19:32 by mmercier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strcpy(char *dst, const char *scr)
{
	int tmp;

	tmp = 0;
	while (scr[tmp] != '\0')
	{
		dst[tmp] = scr[tmp];
		tmp++;
	}
	dst[tmp] = '\0';
	return (dst);
}
