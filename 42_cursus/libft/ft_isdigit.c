/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfafouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 21:27:51 by hfafouri          #+#    #+#             */
/*   Updated: 2023/11/06 18:27:35 by hfafouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
/*#include <stdio.h>
#include <ctype.h>
int main ()
{
	int c = 'd';
	printf ("%d\n", ft_isdigit(c));
	printf ("%d\n", isdigit(c));
}*/
