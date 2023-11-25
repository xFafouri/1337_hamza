/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfafouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 21:18:29 by hfafouri          #+#    #+#             */
/*   Updated: 2023/11/25 15:23:21 by hfafouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	count(long long nb)
{
	int	i;

	i = 1;
	if (nb < 0)
	{
		i++;
		nb = -nb;
	}
	while (nb > 9)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char		*str;
	long long	nbr;
	int			i;
	int			nb;

	nbr = n;
	nb = count(n);
	str = (char *)malloc(nb + 1);
	if (str == NULL)
		return (NULL);
	if (nbr < 0)
	{
		nbr = -nbr;
	}
	i = nb - 1;
	while (i >= 0)
	{
		str[i--] = nbr % 10 + '0';
		nbr = nbr / 10;
	}
	if (n < 0)
		str[0] = '-';
	str[nb] = '\0';
	return (str);
}
/*#include <stdio.h>
int main ()
{
	int i = 123456;

	printf("%s",ft_itoa(i));
}*/
