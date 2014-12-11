/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmercier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 18:41:46 by mmercier          #+#    #+#             */
/*   Updated: 2014/11/09 18:44:53 by mmercier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
		ft_putstr_fd ("-2147483648", fd);
	else
	{
		if (n < 0)
		{
			ft_putchar_fd ('-', fd);
			n = -n;
		}
		if (n < 10)
		{
			ft_putchar_fd (n + 48, fd);
		}
		else
		{
			ft_putnbr_fd (n / 10, fd);
			ft_putnbr_fd (n % 10, fd);
		}
	}
}
