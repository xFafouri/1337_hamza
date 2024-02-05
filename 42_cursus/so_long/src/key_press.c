/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfafouri <hfafouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 00:39:36 by hfafouri          #+#    #+#             */
/*   Updated: 2024/02/01 15:01:34 by hfafouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_game(t_data *img_data)
{
	free_map(img_data);
	mlx_clear_window(img_data->mlx, img_data->win);
	mlx_destroy_window(img_data->mlx, img_data->win);
	exit(0);
}

void	animate_and_move(t_data *img_data, int direction, int new_x, int new_y)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		mlx_clear_window(img_data->mlx, img_data->win);
		img_data->current_frame[img_data->current_direction] = i;
		put_image(img_data);
		draw_charachter(img_data);
		if (direction == 0)
			new_y += 6;
		else if (direction == 1)
			new_y -= 6;
		else if (direction == 2)
			new_x -= 6;
		else if (direction == 3)
			new_x += 6;
		img_data->player_pos[0] = new_x;
		img_data->player_pos[1] = new_y;
		mlx_do_sync(img_data->mlx);
		i++;
	}
}

void	key_animate(int keycode, int new_x, int new_y, t_data *img_data)
{
	if (keycode == 2)
		animate_and_move(img_data, 0, new_x, new_y);
	else if (keycode == 0)
		animate_and_move(img_data, 1, new_x, new_y);
	else if (keycode == 13)
		animate_and_move(img_data, 2, new_x, new_y);
	else if (keycode == 1)
		animate_and_move(img_data, 3, new_x, new_y);
	if (is_door(img_data, img_data->player_pos[0], img_data->player_pos[1]))
	{
		ft_printf("YOU WIN ^-^\n");
		free_map(img_data);
		mlx_clear_window(img_data->mlx, img_data->win);
		mlx_destroy_window(img_data->mlx, img_data->win);
		exit(0);
	}
}

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
