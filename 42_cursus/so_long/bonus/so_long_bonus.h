/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfafouri <hfafouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 18:20:09 by hfafouri          #+#    #+#             */
/*   Updated: 2024/02/01 13:24:15 by hfafouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "ft_printf/ft_printf.h"
# include "get_next_line/get_next_line.h"
# include <fcntl.h>
# include <mlx.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <time.h>

typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*img;
	void	*right_frames[8];
	void	*left_frames[8];
	int		current_frame[2];
	int		player_pos[2];
	int		enemy_pos[2];
	void	*enemy_frames[8];
	int		enemy_frame_counter;
	int		enemy_direction;
	int		width;
	int		height;
	int		p;
	int		c;
	int		e;
	int		x;
	int		y;
	int		frame_counter;
	int		frame_counter_right;
	int		frame_counter_left;
	int		move_counter;
	int		current_direction;
	char	**argv;
	char	**map;
	void	*window;
	char	**play;
	char	**wall;
	char	**collect;
	char	**plan;
	char	**door;
	char	**dooropen;
	char	**mvmnt;
	char	map_dim[2];
	int		player_num;
	int		collect_num;
}			t_data;

void		flood_fill(t_data *data, int x, int y);
void		check_valid_map(t_data *data);
int			check_map(t_data *data);
int			read_line(char *av);
void		load_map(char *av, t_data *data);
int			validate_pce(t_data *data);
void		load_right_frames(void *mlx, t_data *data);
void		load_left_frames(void *mlx, t_data *data);
void		load_enemy_frames(void *mlx, t_data *data);
void		load_image(void *mlx, t_data *data);
int			is_wall(t_data *data, int new_x, int new_y);
int			is_collective(t_data *data, int new_x, int new_y);
int			all_collected(t_data *img_data);
int			is_door(t_data *data, int x, int y);
void		validate_walls(t_data *data);
void		draw_charachter(t_data *img_data);
void		draw_player(t_data *data);
void		put_image(t_data *data);
void		validate(t_data *data);
void		draw_enemy(t_data *data);
void		animate_enemy(t_data *data);
void		check_rectangle(char *argv);
int			check_ext(char *argv);
void		free_map(t_data *data);
void		key_animate(int keycode, int new_x, int new_y, t_data *img_data);
int			key_press(int keycode, t_data *img_data);
void		draw_enemy(t_data *data);
void		animate_enemy(t_data *data);
void		alocate_map(t_data *data);
void		place_enemy(t_data *img_data);
void		player_position(t_data *data);

#endif
