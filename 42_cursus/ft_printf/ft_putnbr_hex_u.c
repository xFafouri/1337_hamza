/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex_u.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfafouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 17:12:04 by hfafouri          #+#    #+#             */
/*   Updated: 2023/11/28 18:15:09 by hfafouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_hex_u(unsigned int nb)
{
	int		count;
	char	*check;

	check = "0123456789ABCDEF";
	count = 0;
	if (nb >= 16)
	{
		count += ft_putnbr_hex_u(nb / 16);
		count += ft_putnbr_hex_u(nb % 16);
	}
	else
	{
		count += ft_putchar(check[nb]);
	}
	return (count);
}
