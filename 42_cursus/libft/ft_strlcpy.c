/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfafouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 21:26:38 by hfafouri          #+#    #+#             */
/*   Updated: 2023/11/23 14:29:29 by hfafouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
//#include <stdio.h>
//#include <string.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	len;

	len = 0;
	if (dstsize == 0)
		return (ft_strlen(src));
	while (src[len] && len < dstsize - 1)
	{
		dst[len] = src[len];
		len++;
	}
	if (len < dstsize)
	{
		dst[len] = '\0';
	}
	while (src[len])
		len++;
	return (len);
}
/*#include <stdio.h>
#include <string.h>
int main ()
{
	char	dst[] = "hamza";
	const char	src[] = "fafouri";

	printf("%zu | dst = %s | src= %s ", ft_strlcpy(dst, src, 6), dst, src);
	//printf("%zu", strlcpy(dst, src, 3));
}*/
