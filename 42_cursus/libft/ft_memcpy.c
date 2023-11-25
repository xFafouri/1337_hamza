/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfafouri <hfafouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 23:12:16 by hfafouri          #+#    #+#             */
/*   Updated: 2023/11/24 00:16:34 by hfafouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*s1;
	unsigned char		*s2;
	size_t				i;

	s1 = (unsigned char *) dst;
	s2 = (unsigned char *) src;
	i = 0;
	if (s1 == s2 || n == 0)
		return (s1);
	while (i < n)
	{
		s1[i] = s2[i];
		i++;
	}
	return (dst);
}
/*#include <string.h>
#include <stdio.h>
int main()
{
    printf("%s",ft_memcpy(NULL, NULL, 3));
    return 0;
}*/
