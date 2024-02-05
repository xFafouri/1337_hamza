/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_pos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfafouri <hfafouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 18:08:52 by hfafouri          #+#    #+#             */
/*   Updated: 2024/01/30 18:34:06 by hfafouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	player_position(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->map_dim[1])
	{
		j = 0;
		while (j < data->map_dim[0])
		{
			if (data->map[i][j] == 'P')
			{
				data->player_pos[0] = i * 48;
				data->player_pos[1] = j * 48;
				return ;
			}
			j++;
		}
		i++;
	}
}
