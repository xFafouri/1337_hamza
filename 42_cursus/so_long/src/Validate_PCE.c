/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Validate_PCE.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfafouri <hfafouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 14:59:21 by hfafouri          #+#    #+#             */
/*   Updated: 2024/02/01 15:01:11 by hfafouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_rectangle(char *argv)
{
	int		fd;
	int		i;
	int		flen;
	char	*str;

	i = 0;
	fd = open(argv, O_RDONLY);
	str = get_next_line(fd);
	flen = ft_strlen1(str);
	while (str)
	{
		if (ft_strlen1(str) != flen)
		{
			ft_printf("Invalid Map\n");
			exit(1);
		}
		free(str);
		str = get_next_line(fd);
		i++;
	}
}

int	validate_pce(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	data->p = 0;
	data->c = 0;
	data->e = 0;
	while (i < data->map_dim[1])
	{
		j = 0;
		while (j < data->map_dim[0])
		{
			if (data->map[i][j] == 'P')
				data->p++;
			else if (data->map[i][j] == 'C')
				data->c++;
			else if (data->map[i][j] == 'E')
				data->e++;
			j++;
		}
		i++;
	}
	if (data->p != 1 || data->e != 1 || data->c < 1)
		return (0);
	return (1);
}

void	validate_walls(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->map_dim[0])
	{
		if (data->map[0][i] != '1' || data->map[data->map_dim[1] - 1][i] != '1')
		{
			ft_printf("maps should be surrounded by walls\n");
			exit(1);
		}
		if (i < data->map_dim[1] && (data->map[i][data->map_dim[0] - 1] != '1'
			|| data->map[i][0] != '1'))
		{
			ft_printf("maps should be rectangular\n");
			exit(1);
		}
		i++;
	}
}

void	validate(t_data *data)
{
	validate_walls(data);
	if (!validate_pce(data))
	{
		ft_printf("Invalid map.(one 'P', one 'E',and at least one 'C')\n");
		exit(1);
	}
}
