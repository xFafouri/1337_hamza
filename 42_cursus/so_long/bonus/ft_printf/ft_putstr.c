/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfafouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 02:37:36 by hfafouri          #+#    #+#             */
/*   Updated: 2023/11/28 18:25:12 by hfafouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str)
{
	int	count;

	count = 0;
	if (str == NULL)
	{
		write (1, "(null)", 6);
		return (6);
	}
	while (*str != '\0')
	{
		ft_putchar((int)*str);
		++count;
		++str;
	}
	return (count);
}
