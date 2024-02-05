/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfafouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 06:30:26 by hfafouri          #+#    #+#             */
/*   Updated: 2023/11/29 15:40:52 by hfafouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_hex_p(unsigned long nb)
{
	int		count;
	char	*check;

	count = 0;
	check = "0123456789abcdef";
	if (nb >= 16)
	{
		count += ft_putnbr_hex_p(nb / 16);
		count += ft_putnbr_hex_p(nb % 16);
	}
	else
	{
		count += ft_putchar(check[nb]);
	}
	return (count);
}
