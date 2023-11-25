/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfafouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 16:09:02 by hfafouri          #+#    #+#             */
/*   Updated: 2023/11/20 14:48:49 by hfafouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count(char *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			count++;
		while (*s && *s != c)
			s++;
	}
	return (count);
}

static char	**ft_free(char **str, int n)
{
	while (n > 0)
	{
		free(str[--n]);
	}
	free(str);
	return (0);
}

static char	**ft_bahloul(char **tab, const char *s, char c)
{
	int	i;
	int	j;
	int	n;

	i = 0;
	n = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] == '\0')
			break ;
		j = 0;
		while (s[i] != '\0' && s[i] != c && j++ >= 0)
			i++;
		tab[n++] = ft_substr(s, i - j, j);
		if (!tab[n - 1])
			return (ft_free(tab, n));
	}
	tab[n] = NULL;
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;

	if (!s)
		return (NULL);
	tab = (char **)malloc((ft_count((char *)s, c) + 1) * sizeof(char *));
	if (!tab)
		return (NULL);
	return (ft_bahloul(tab, s, c));
}
/*#include <stdio.h>

int	main(void)
{
	char	*s;
	char	c;
	int		i;
	char	**r;

	s = "hamza.fafouri.abdellatif.bouyatas";
	c = 'a';
	r = ft_split(s, c);
	i = 0;
	while (r[i])
	{
		printf("%s\n", r[i]);
		i++;
	}
}*/
