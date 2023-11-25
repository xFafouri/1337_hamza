/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfafouri <hfafouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 16:04:49 by hfafouri          #+#    #+#             */
/*   Updated: 2023/11/13 15:02:21 by hfafouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*p;

	p = (unsigned char *)s;
	while (n > 0)
	{
		*p = 0;
		n--;
		p++;
	}
}
/*#include <stdio.h>
#include <string.h>
int main()
{
	char	arr[6] = "hamza";
	ft_bzero(arr + 2 , 1);
	printf("%s\n", arr);
	printf("%s\n", bzero(arr , 0));
}*/
