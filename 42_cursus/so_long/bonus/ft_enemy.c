/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enemy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfafouri <hfafouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 17:44:22 by hfafouri          #+#    #+#             */
/*   Updated: 2024/01/31 16:44:37 by hfafouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	draw_enemy(t_data *data)
{
	int	x;
	int	y;

	x = data->enemy_pos[0];
	y = data->enemy_pos[1];
	if (x != 0 && y != 0)
	{
		mlx_put_image_to_window(data->mlx, data->win,
			data->enemy_frames[data->enemy_frame_counter], x, y);
	}
}

void	animate_enemy(t_data *data)
{
	int	i;

	data->enemy_frame_counter = 0;
	i = 0;
	while (i < 7)
	{
		data->enemy_frame_counter = i;
		mlx_clear_window(data->mlx, data->win);
		put_image(data);
		draw_enemy(data);
		usleep(10000);
		mlx_do_sync(data->mlx);
		i++;
	}
}

void	alocate_map(t_data *data)
{
	data->map = (char **)malloc(sizeof(char *) * (data->map_dim[1] + 1));
	if (data->map == NULL)
		return ;
}

void	check_and_place_enemy(t_data *img_data, int i, int j, int *valid)
{
	if (img_data->map[i][j] != '1' && (j != img_data->player_pos[0] / 48
			|| i != img_data->player_pos[1] / 48) && img_data->map[i][j] != 'E'
		&& img_data->map[i][j] != 'C')
	{
		img_data->map[i][j] = '1';
		flood_fill(img_data, img_data->player_pos[0] / 48,
			img_data->player_pos[1] / 48);
		if (check_map(img_data) == 1)
		{
			*valid = 1;
			img_data->enemy_pos[0] = j * 48;
			img_data->enemy_pos[1] = i * 48;
			free_map(img_data);
			alocate_map(img_data);
			load_map(img_data->argv[1], img_data);
		}
		else
		{
			img_data->map[i][j] = '0';
		}
	}
}

void	place_enemy(t_data *img_data)
{
	int	valid;
	int	i;
	int	j;

	valid = 0;
	i = 0;
	j = 0;
	while (i < img_data->map_dim[1])
	{
		j = 0;
		while (j < img_data->map_dim[0])
		{
			check_and_place_enemy(img_data, i, j, &valid);
			if (valid)
				return ;
			j++;
		}
		i++;
	}
	free_map(img_data);
	alocate_map(img_data);
	load_map(img_data->argv[1], img_data);
}
