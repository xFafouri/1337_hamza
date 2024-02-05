/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfafouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 02:36:57 by hfafouri          #+#    #+#             */
/*   Updated: 2023/11/30 00:08:46 by hfafouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_putnbr_recursive(int nb, int count)
{
	if (nb == INT_MIN)
	{
		ft_putstr("-2147483648");
		count += 11;
	}
	else
	{
		if (nb < 0)
		{
			ft_putchar('-');
			nb *= -1;
			count++;
		}
		if (nb >= 10)
		{
			count = ft_putnbr_recursive(nb / 10, count);
			count = ft_putnbr_recursive(nb % 10, count);
		}
		else
		{
			ft_putchar(nb + '0');
			count++;
		}
	}
	return (count);
}

int	ft_putnbr(int nb)
{
	int	count;

	count = 0;
	count = ft_putnbr_recursive(nb, count);
	return (count);
}
