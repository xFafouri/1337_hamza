/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strch.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfafouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 18:55:50 by hfafouri          #+#    #+#             */
/*   Updated: 2023/11/21 22:52:59 by hfafouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)(s + i));
	return (NULL);
}
/*#include <stdio.h>
int main ()
{
	char	arr[] = "hamzafafouri.";
	int c = ".";

	printf("%s",ft_strchr(arr, c));
}*/
