/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfafouri <hfafouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 02:25:56 by hfafouri          #+#    #+#             */
/*   Updated: 2024/01/28 18:11:49 by hfafouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_format(char check, va_list ap)
{
	int	count;

	count = 0;
	if (check == 'c')
		count = ft_putchar(va_arg(ap, int));
	else if (check == 's')
		count = ft_putstr(va_arg(ap, char *));
	else if (check == 'd' || check == 'i')
		count = ft_putnbr(va_arg(ap, int));
	else if (check == 'u')
		count = ft_putnbr_u(va_arg(ap, unsigned int));
	else if (check == 'p')
	{
		count = ft_putstr("0x");
		count += ft_putnbr_hex_p(va_arg(ap, unsigned long));
	}
	else if (check == 'x')
		count = ft_putnbr_hex_l(va_arg(ap, unsigned int));
	else if (check == 'X')
		count = ft_putnbr_hex_u(va_arg(ap, unsigned int));
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;
	int		i;

	count = 0;
	i = 0;
	va_start(ap, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '\0')
				return (count);
			if (ft_strchrr("cspdiuxX", format[i]))
				count += check_format((format[i]), ap);
			else if (format[i] == '%')
				count += ft_putchar(format[i]);
		}
		else
			count += ft_putchar(format[i]);
		i++;
	}
	va_end(ap);
	return (count);
}
/*#include <stdio.h>
int main()
{
	int a;
	int i;
	i = ft_printf("%d=  \t\n====%%%%%%%%%%%%%%", 42);
	printf("\n");
	a = printf("%d=  \t\n====%%%%%%%%%%%%%%", 42);
	printf("\n");
	printf("%d\n", i);
	printf("%d\n", a);
}*/
