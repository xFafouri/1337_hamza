/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfafouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 00:47:52 by hfafouri          #+#    #+#             */
/*   Updated: 2023/11/19 03:32:00 by hfafouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	nb;

	if (fd >= 0)
	{
		nb = n;
		if (nb < 0)
		{
			ft_putchar_fd('-', fd);
			nb *= -1;
		}
		if (nb < 10)
			ft_putchar_fd(nb + 48, fd);
		else
		{
			ft_putnbr_fd(nb / 10, fd);
			ft_putnbr_fd(nb % 10, fd);
		}
	}
}
