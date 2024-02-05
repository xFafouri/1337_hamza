/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfafouri <hfafouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:08:40 by hfafouri          #+#    #+#             */
/*   Updated: 2024/01/29 23:28:51 by hfafouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_wall(t_data *data, int new_x, int new_y)
{
	int	x;
	int	y;

	x = new_x / 48;
	y = new_y / 48;
	if (x >= 0 && x < data->map_dim[1] && y >= 0 && y < data->map_dim[0]
		&& data->map[x][y] == '1')
	{
		return (1);
	}
	return (0);
}

int	is_collective(t_data *data, int new_x, int new_y)
{
	int	x;
	int	y;

	x = new_x / 48;
	y = new_y / 48;
	if (x >= 0 && x < data->map_dim[1] && y >= 0 && y < data->map_dim[0]
		&& data->map[x][y] == 'C')
	{
		data->map[x][y] = '0';
		return (1);
	}
	return (0);
}

int	all_collected(t_data *img_data)
{
	int	i;
	int	j;

	i = 0;
	while (i < img_data->map_dim[1])
	{
		j = 0;
		while (j < img_data->map_dim[0])
		{
			if (img_data->map[i][j] == 'C')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	is_door(t_data *data, int x, int y)
{
	x = x / 48;
	y = y / 48;
	if (x >= 0 && x < data->map_dim[1] && y >= 0 && y < data->map_dim[0]
		&& data->map[x][y] == 'E')
	{
		if (all_collected(data))
		{
			return (1);
		}
	}
	return (0);
}
