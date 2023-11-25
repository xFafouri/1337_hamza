/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfafouri <hfafouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 03:03:12 by hfafouri          #+#    #+#             */
/*   Updated: 2023/11/25 06:53:20 by hfafouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <string.h>
#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (*needle == 0 ft_strlen(needle) == NULL)
		return ((char *)haystack);
	if (len == 0)
		return (NULL);
	while (haystack[i] != '\0' && i < len)
	{
		j = 0;
		while (haystack[i + j] == needle[j] && needle[j] != '\0' && j + i < len)
			j++;
		if (j == ft_strlen(needle))
			return ((char *)&haystack[i]);
		i++;
	}
	return (NULL);
}
/*#include <stdio.h>
#include <string.h>
 int main() 
 {   
	 char *haystack = "Hello, World!";
     char *needle = "He";
 	char *result1 = ft_strnstr(haystack, needle, 6);
 	//char *result1 = strnstr(NULL, needle, 4);

 	printf("%s\n",result1);
	return 0;
}*/
