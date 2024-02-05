/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfafouri <hfafouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 11:41:56 by hfafouri          #+#    #+#             */
/*   Updated: 2024/02/01 15:01:08 by hfafouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	valid_map(char c)
{
	int	i;

	i = 0;
	while (i < 5)
	{
		if ('0' == c || '1' == c || 'C' == c || 'E' == c || 'P' == c)
			return (1);
		i++;
	}
	return (0);
}

int	read_line(char *av)
{
	int		fd;
	int		i;
	char	*str;

	fd = open(av, O_RDONLY);
	str = get_next_line(fd);
	i = 0;
	while (str)
	{
		free(str);
		str = get_next_line(fd);
		i++;
	}
	return (i);
}

void	map_loop(t_data *data, char *str, int fd)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->map_dim[1] && str != NULL)
	{
		j = 0;
		data->map[i] = (char *)malloc(sizeof(char) * (data->map_dim[0]));
		while (j < data->map_dim[0])
		{
			if (!valid_map(str[j]))
			{
				ft_printf("Invalid Map\n");
				exit(1);
			}
			data->map[i][j] = str[j];
			j++;
		}
		free(str);
		str = get_next_line(fd);
		i++;
	}
}

void	load_map(char *av, t_data *data)
{
	int		fd;
	char	*str;

	fd = open(av, O_RDONLY);
	str = get_next_line(fd);
	if (fd < 0)
	{
		ft_printf("Wrong File");
		exit(1);
	}
	if (ft_strlen(str) == 0)
	{
		ft_printf("Empty Map");
		exit(1);
	}
	data->map_dim[0] = ft_strlen(str) - 1;
	map_loop(data, str, fd);
	close(fd);
}
