/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex_l.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfafouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 17:10:10 by hfafouri          #+#    #+#             */
/*   Updated: 2023/11/30 00:00:54 by hfafouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_hex_l(unsigned int nb)
{
	int		count;
	char	*check;

	check = "0123456789abcdef";
	count = 0;
	if (nb >= 16)
	{
		count += ft_putnbr_hex_l(nb / 16);
		count += ft_putnbr_hex_l(nb % 16);
	}
	else
		count += ft_putchar(check[nb]);
	return (count);
}
