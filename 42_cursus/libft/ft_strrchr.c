/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfafouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 21:38:56 by hfafouri          #+#    #+#             */
/*   Updated: 2023/11/08 23:17:12 by hfafouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*p;

	p = 0;
	while (*s != '\0')
	{
		if (*s == (unsigned char)c)
			p = s;
		s++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)s);
	else
		return ((char *)p);
}
/*#include <stdio.h>
int main ()
{
	char	arr[] = "hamza.fafouri.reda";
	int c = '.';

	printf("%s", ft_strrchr(arr , c));
}*/
