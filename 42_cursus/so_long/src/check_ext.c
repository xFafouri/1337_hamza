/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ext.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfafouri <hfafouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 15:12:56 by hfafouri          #+#    #+#             */
/*   Updated: 2024/02/01 15:01:01 by hfafouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_extension(char *argv, char *exten)
{
	int	i;
	int	j;

	i = ft_strlen(argv);
	j = ft_strlen(exten);
	if (i < j)
		return (1);
	while (j >= 0)
	{
		if (argv[i] != exten[j])
			return (1);
		i--;
		j--;
	}
	if (i >= 0 && argv[i] == '/')
		return (1);
	return (0);
}

int	check_ext(char *argv)
{
	if (check_extension(&argv[1], ".ber"))
	{
		ft_printf("Invalid file extension\n");
		exit(1);
	}
	return (0);
}
