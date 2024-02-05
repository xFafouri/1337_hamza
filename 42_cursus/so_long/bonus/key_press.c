/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfafouri <hfafouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 16:52:38 by hfafouri          #+#    #+#             */
/*   Updated: 2024/02/01 13:23:47 by hfafouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	key_next(int keycode, int new_x, int new_y, t_data *img_data)
{
	if (!is_wall(img_data, new_x, new_y))
	{
		if (keycode == 2)
		{
			img_data->current_direction = 0;
			new_y -= 48;
		}
		else if (keycode == 0)
		{
			img_data->current_direction = 1;
			new_y += 48;
		}
		else if (keycode == 13)
			new_x += 48;
		else if (keycode == 1)
			new_x -= 48;
		key_animate(keycode, new_x, new_y, img_data);
		img_data->move_counter++;
		ft_printf("Number of movements: %d\n", img_data->move_counter);
	}
}

void	exit_game(t_data *img_data)
{
	free_map(img_data);
	mlx_clear_window(img_data->mlx, img_data->win);
	mlx_destroy_window(img_data->mlx, img_data->win);
	exit(0);
}

int	key_press(int keycode, t_data *img_data)
{
	int	new_x;
	int	new_y;

	if (keycode == 13 || keycode == 1 || keycode == 2 || keycode == 0)
	{
		img_data->frame_counter = 1;
		new_x = img_data->player_pos[0];
		new_y = img_data->player_pos[1];
		if (keycode == 2)
			new_y += 48;
		else if (keycode == 0)
			new_y -= 48;
		else if (keycode == 13)
			new_x -= 48;
		else if (keycode == 1)
			new_x += 48;
		if (is_collective(img_data, new_x, new_y))
			img_data->map[new_x / 48][new_y / 48] = '0';
		key_next(keycode, new_x, new_y, img_data);
	}
	else if (keycode == 53)
		exit_game(img_data);
	return (1);
}
