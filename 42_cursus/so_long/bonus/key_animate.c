/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_animate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfafouri <hfafouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:33:40 by hfafouri          #+#    #+#             */
/*   Updated: 2024/02/01 14:59:51 by hfafouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	check_enemy(t_data *img_data)
{
	if (img_data->player_pos[0] == (img_data->enemy_pos[1])
		&& img_data->player_pos[1] == (img_data->enemy_pos[0]))
	{
		free_map(img_data);
		mlx_clear_window(img_data->mlx, img_data->win);
		mlx_destroy_window(img_data->mlx, img_data->win);
		ft_printf("You lost!\n");
		exit(0);
	}
}

void	help_function(t_data *img_data)
{
	mlx_clear_window(img_data->mlx, img_data->win);
	put_image(img_data);
	draw_enemy(img_data);
	draw_charachter(img_data);
	mlx_do_sync(img_data->mlx);
}

void	animate_and_move(t_data *img_data, int direction, int new_x, int new_y)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		img_data->current_frame[img_data->current_direction] = i;
		img_data->enemy_frame_counter = i;
		help_function(img_data);
		if (direction == 0)
			new_y += 6;
		else if (direction == 1)
			new_y -= 6;
		else if (direction == 2)
			new_x -= 6;
		else if (direction == 3)
			new_x += 6;
		usleep(10000);
		img_data->player_pos[0] = new_x;
		img_data->player_pos[1] = new_y;
		i++;
		check_enemy(img_data);
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
		free_map(img_data);
		mlx_clear_window(img_data->mlx, img_data->win);
		mlx_destroy_window(img_data->mlx, img_data->win);
		usleep(400000);
		ft_printf("YOU WIN ^-^\n");
		exit(0);
	}
}
