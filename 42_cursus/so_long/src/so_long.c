/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfafouri <hfafouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 23:26:22 by hfafouri          #+#    #+#             */
/*   Updated: 2024/01/31 21:30:32 by hfafouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_data(t_data *img_data)
{
	mlx_clear_window(img_data->mlx, img_data->win);
	put_image(img_data);
	draw_player(img_data);
	mlx_do_sync(img_data->mlx);
}

int	close_window(t_data *img_data)
{
	ft_printf("Window closed by user\n");
	free_map(img_data);
	mlx_clear_window(img_data->mlx, img_data->win);
	mlx_destroy_window(img_data->mlx, img_data->win);
	exit(0);
}

void	start_data(t_data *data)
{
	data->frame_counter_right = 0;
	data->frame_counter_left = 0;
	data->frame_counter = 0;
	data->move_counter = 0;
	data->current_frame[0] = 0;
	data->current_frame[1] = 0;
	data->current_direction = 0;
	load_right_frames(data->mlx, data);
	load_left_frames(data->mlx, data);
	load_image(data->mlx, data);
	put_image(data);
	mlx_hook(data->win, 17, 0L, close_window, data);
	mlx_hook(data->win, 2, 0, key_press, (void *)data);
	mlx_loop(data->mlx);
}

void	alocate_map(t_data *data)
{
	data->map = (char **)malloc(sizeof(char *) * (data->map_dim[1] + 1));
	if (data->map == NULL)
		return ;
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
	{
		ft_printf("Number of arguments is not 2\n");
		return (1);
	}
	check_ext(argv[1]);
	data.map_dim[1] = read_line(argv[1]);
	alocate_map(&data);
	load_map(argv[1], &data);
	check_rectangle(argv[1]);
	validate(&data);
	player_position(&data);
	check_valid_map(&data);
	free_map(&data);
	alocate_map(&data);
	load_map(argv[1], &data);
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, data.map_dim[0] * 48, data.map_dim[1]
			* 48, "Mar7ba biik");
	start_data(&data);
}
