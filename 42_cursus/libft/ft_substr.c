/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfafouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 16:32:44 by hfafouri          #+#    #+#             */
/*   Updated: 2023/11/19 03:07:50 by hfafouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
//#include <string.h>
//#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*sub;
	size_t		i;

	if (s == NULL)
		return (NULL);
	i = 0;
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen (s) - start)
		len = ft_strlen(s) - start;
	sub = (char *)malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (NULL);
	while (i < len)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[len] = '\0';
	return ((char *)sub);
}
/*#include <stdio.h>
int main ()
{
	const char *str = "hello, hamza!";
	char *r = ft_substr(str, 0,5);

	printf("%s", r);
}*/
