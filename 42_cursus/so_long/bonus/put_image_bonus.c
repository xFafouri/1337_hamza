/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_image_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfafouri <hfafouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:15:28 by hfafouri          #+#    #+#             */
/*   Updated: 2024/02/01 01:17:56 by hfafouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	draw_charachter(t_data *img_data)
{
	if (img_data->current_direction == 0)
		mlx_put_image_to_window(img_data->mlx, img_data->win,
			img_data->right_frames[img_data->current_frame[0]],
			img_data->player_pos[1], img_data->player_pos[0]);
	else if (img_data->current_direction == 1)
		mlx_put_image_to_window(img_data->mlx, img_data->win,
			img_data->left_frames[img_data->current_frame[1]],
			img_data->player_pos[1], img_data->player_pos[0]);
}

void	draw_player(t_data *data)
{
	int	x;
	int	y;

	x = data->player_pos[1];
	y = data->player_pos[0];
	mlx_put_image_to_window(data->mlx, data->win,
		data->right_frames[data->current_frame[data->current_direction]], x, y);
}

void	print_mvmnt(t_data *img_data)
{
	char	move_counter_str[100];

	sprintf(move_counter_str, "%d", img_data->move_counter);
	mlx_string_put(img_data->mlx, img_data->win, 156, 11, 0xEDFECE,
		move_counter_str);
}

void	put_to_window(t_data *data, int x, int y)
{
	mlx_put_image_to_window(data->mlx, data->win, data->plan, y * 48, x
		* 48);
	if (data->map[x][y] == '1')
		mlx_put_image_to_window(data->mlx, data->win, data->wall, y
			* 48, x * 48);
	else if (data->map[x][y] == 'C')
		mlx_put_image_to_window(data->mlx, data->win, data->collect, y
			* 48, x * 48);
	else if (data->map[x][y] == 'E')
	{
		mlx_put_image_to_window(data->mlx, data->win, data->door, y
			* 48, x * 48);
		if (all_collected(data))
			mlx_put_image_to_window(data->mlx, data->win,
				data->dooropen, y * 48, x * 48);
	}
}

void	put_image(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	mlx_clear_window(data->mlx, data->win);
	while (x < data->map_dim[1])
	{
		y = 0;
		while (y < data->map_dim[0])
		{
			put_to_window(data, x, y);
			y++;
		}
		x++;
	}
	print_mvmnt(data);
	draw_enemy(data);
	mlx_put_image_to_window(data->mlx, data->win, data->mvmnt, 10, 10);
	draw_charachter(data);
}
