/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfafouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 22:25:38 by hfafouri          #+#    #+#             */
/*   Updated: 2023/11/17 01:18:39 by hfafouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*p;

	i = 0;
	p = (unsigned char *)s;
	while (n > 0)
	{
		if (p[i] == (unsigned char)c)
			return (p + i);
		i++;
		n--;
	}
	return (NULL);
}
/*#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	*str;

	str = strdup("hamza");
	// printf("%s\n", ft_memchr(arr, 'a',80));
	printf("%s\n", memchr(str, 'a', 80));
}*/
