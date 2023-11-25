/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfafouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 00:55:28 by hfafouri          #+#    #+#             */
/*   Updated: 2023/11/23 13:39:21 by hfafouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*s1;
	const unsigned char	*s2;

	s1 = (unsigned char *)dst;
	s2 = (const unsigned char *)src;
	if (s1 == s2)
		return (dst);
	if (s1 < s2)
		ft_memcpy(s1, s2, len);
	else
	{
		s1 += len;
		s2 += len;
		while (len > 0)
		{
			s1--;
			s2--;
			*s1 = *s2;
			len--;
		}
	}
	return (dst);
}
/*#include <string.h>
#include <stdio.h>
int main()
{
    char str[] = "abcdefg";
	
    //ft_memcpy(str + 6, str, length - 6);
    printf("%s",memmove(str + 2, str, 3));

    // printf("Result: %s\n", str);

    return 0;
}*/
