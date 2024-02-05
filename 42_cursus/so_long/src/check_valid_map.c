/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfafouri <hfafouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 18:47:50 by hfafouri          #+#    #+#             */
/*   Updated: 2024/02/01 02:01:26 by hfafouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill(t_data *data, int x, int y)
{
	if (x < 0 || y < 0 || x >= data->map_dim[1] || y >= data->map_dim[0])
		return ;
	if (data->map[x][y] == 'P' || data->map[x][y] == 'E'
		|| data->map[x][y] == 'C' || data->map[x][y] == '0')
	{
		data->map[x][y] = 'X';
		flood_fill(data, x + 1, y);
		flood_fill(data, x, y + 1);
		flood_fill(data, x - 1, y);
		flood_fill(data, x, y - 1);
	}
}

int	check_map(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->map_dim[1])
	{
		j = 0;
		while (j < data->map_dim[0])
		{
			if (data->map[i][j] == 'E' || data->map[i][j] == 'C')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	check_valid_map(t_data *data)
{
	flood_fill(data, data->player_pos[0] / 48, data->player_pos[1] / 48);
	if (!check_map(data))
	{
		ft_printf("INVALID MAP\n");
		free_map(data);
		exit(1);
	}
}
