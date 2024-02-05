/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfafouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 17:30:33 by hfafouri          #+#    #+#             */
/*   Updated: 2023/11/28 18:24:40 by hfafouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_u_rec(unsigned int n, int count)
{
	if (n < 10)
	{
		ft_putchar(n + '0');
		count++;
	}
	else
	{
		count = ft_putnbr_u_rec(n / 10, count);
		count = ft_putnbr_u_rec(n % 10, count);
	}
	return (count);
}

int	ft_putnbr_u(unsigned int nb)
{
	int	count;

	count = 0;
	count = ft_putnbr_u_rec(nb, count);
	return (count);
}
