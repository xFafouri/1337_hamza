/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfafouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 21:11:16 by hfafouri          #+#    #+#             */
/*   Updated: 2023/11/23 13:31:02 by hfafouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	check(const char *set, char c)
{
	while (*set && c != *set)
		set++;
	return (c == *set);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	first;
	size_t	last;

	if (!s1 || !set)
		return (ft_strdup(""));
	first = 0;
	last = ft_strlen(s1);
	while (first < last && check(set, s1[first]))
		first++;
	if (first == last)
		return (ft_strdup(""));
	while (last > 0 && check(set, s1[last - 1]))
		last--;
	return (ft_substr(s1, first, last - first));
}
/*#include <stdio.h>
int main ()
{
	char	*str = "abxbabxbaxbabx tkhrbi0a babxbabxabxbbabababb";
	char	*set = "ab";
	printf ("%s\n",ft_strtrim(str, set));
}*/
