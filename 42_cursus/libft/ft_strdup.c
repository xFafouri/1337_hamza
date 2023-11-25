/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfafouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 14:35:25 by hfafouri          #+#    #+#             */
/*   Updated: 2023/11/20 17:20:39 by hfafouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*cpy;

	i = 0;
	cpy = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!cpy)
		return (NULL);
	while (s1[i])
	{
		cpy[i] = s1[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}
/*#include <stdio.h>
#include <string.h>
int main ()
{
	printf("%s\n", strdup(NULL));
	//printf ("%s\n", ft_strdup(NULL));
}*/
