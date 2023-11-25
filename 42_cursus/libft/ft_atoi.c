/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfafouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 02:01:12 by hfafouri          #+#    #+#             */
/*   Updated: 2023/11/22 21:50:18 by hfafouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	r;
	int	s;

	r = 0;
	s = 1;
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			s *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		r = r * 10 + (*str - 48);
		str++;
	}
	return (r * s);
}
/*#include <stdio.h>
#include <stdlib.h>
int main()
{
	printf("%d" , ft_atoi("--124o52"));

}*/
