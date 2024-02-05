/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfafouri <hfafouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:03:57 by hfafouri          #+#    #+#             */
/*   Updated: 2024/02/01 01:16:29 by hfafouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_invalid_xpm(void *img)
{
	if (!img)
	{
		ft_printf("invalid xpm\n");
		exit (1);
	}
}

void	load_right_frames(void *mlx, t_data *data)
{
	data->right_frames[0] = mlx_xpm_file_to_image(mlx,
			"./src/right_moves/right_stop.xpm", &data->width, &data->height);
	exit_invalid_xpm(data->right_frames[0]);
	data->right_frames[1] = mlx_xpm_file_to_image(mlx,
			"./src/right_moves/right_1.xpm", &data->width, &data->height);
	exit_invalid_xpm(data->right_frames[1]);
	data->right_frames[2] = mlx_xpm_file_to_image(mlx,
			"./src/right_moves/right_2.xpm", &data->width, &data->height);
	exit_invalid_xpm(data->right_frames[2]);
	data->right_frames[3] = mlx_xpm_file_to_image(mlx,
			"./src/right_moves/right_3.xpm", &data->width, &data->height);
	exit_invalid_xpm(data->right_frames[3]);
	data->right_frames[4] = mlx_xpm_file_to_image(mlx,
			"./src/right_moves/right_4.xpm", &data->width, &data->height);
	exit_invalid_xpm(data->right_frames[4]);
	data->right_frames[5] = mlx_xpm_file_to_image(mlx,
			"./src/right_moves/right_5.xpm", &data->width, &data->height);
	exit_invalid_xpm(data->right_frames[5]);
	data->right_frames[6] = mlx_xpm_file_to_image(mlx,
			"./src/right_moves/right_6.xpm", &data->width, &data->height);
	exit_invalid_xpm(data->right_frames[6]);
	data->right_frames[7] = mlx_xpm_file_to_image(mlx,
			"./src/right_moves/right_7.xpm", &data->width, &data->height);
	exit_invalid_xpm(data->right_frames[7]);
}

void	load_left_frames(void *mlx, t_data *data)
{
	data->left_frames[0] = mlx_xpm_file_to_image(mlx,
			"./src/left_moves/left_stop.xpm", &data->width, &data->height);
	exit_invalid_xpm(data->left_frames[0]);
	data->left_frames[1] = mlx_xpm_file_to_image(mlx,
			"./src/left_moves/left_1.xpm", &data->width, &data->height);
	exit_invalid_xpm(data->left_frames[1]);
	data->left_frames[2] = mlx_xpm_file_to_image(mlx,
			"./src/left_moves/left_2.xpm", &data->width, &data->height);
	exit_invalid_xpm(data->left_frames[2]);
	data->left_frames[3] = mlx_xpm_file_to_image(mlx,
			"./src/left_moves/left_3.xpm", &data->width, &data->height);
	exit_invalid_xpm(data->left_frames[3]);
	data->left_frames[4] = mlx_xpm_file_to_image(mlx,
			"./src/left_moves/left_4.xpm", &data->width, &data->height);
	exit_invalid_xpm(data->left_frames[4]);
	data->left_frames[5] = mlx_xpm_file_to_image(mlx,
			"./src/left_moves/left_5.xpm", &data->width, &data->height);
	exit_invalid_xpm(data->left_frames[5]);
	data->left_frames[6] = mlx_xpm_file_to_image(mlx,
			"./src/left_moves/left_6.xpm", &data->width, &data->height);
	exit_invalid_xpm(data->left_frames[6]);
	data->left_frames[7] = mlx_xpm_file_to_image(mlx,
			"./src/left_moves/left_7.xpm", &data->width, &data->height);
	exit_invalid_xpm(data->left_frames[7]);
}

void	load_image(void *mlx, t_data *data)
{
	data->plan = mlx_xpm_file_to_image(mlx, "./utils/plan.xpm", &data->width,
			&data->height);
	exit_invalid_xpm(data->plan);
	data->wall = mlx_xpm_file_to_image(mlx, "./utils/wall.xpm", &data->width,
			&data->height);
	exit_invalid_xpm(data->wall);
	data->collect = mlx_xpm_file_to_image(mlx, "./utils/collect.xpm",
			&data->width, &data->height);
	exit_invalid_xpm(data->collect);
	data->door = mlx_xpm_file_to_image(mlx, "./utils/doorf.xpm", &data->width,
			&data->height);
	exit_invalid_xpm(data->door);
	data->dooropen = mlx_xpm_file_to_image(mlx, "./utils/dooropen.xpm",
			&data->width, &data->height);
	exit_invalid_xpm(data->dooropen);
}
