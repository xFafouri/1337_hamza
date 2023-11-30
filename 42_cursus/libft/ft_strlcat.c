/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfafouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 15:19:03 by hfafouri          #+#    #+#             */
/*   Updated: 2023/11/28 18:59:46 by hfafouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	lendest;
	size_t	lensrc;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (dstsize == 0)
		return (ft_strlen(src));
	lendest = ft_strlen(dst);
	lensrc = ft_strlen(src);
	if (dstsize <= lendest)
	{
		return (dstsize + lensrc);
	}
	while (dst[i] && i < dstsize - 1)
		i++;
	while (i < dstsize - 1 && src[j])
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (lendest + lensrc);
}
/*#include <stdio.h>
#include <string.h>
int main ()
{
	char dest[] = "hamza";
	char src[] = "fafouri";

	printf ("%zu | %s ", ft_strlcat(dest, src, 8), dest);
	//printf("%lu | %s", , dst);
}*/
