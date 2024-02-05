/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfafouri <hfafouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 13:59:24 by hfafouri          #+#    #+#             */
/*   Updated: 2024/01/30 18:22:58 by hfafouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	free_map(t_data *data)
{
	int	i;

	i = 0;
	while (data->map_dim[1] > i)
	{
		free(data->map[i]);
		i++;
	}
	free(data->map);
}
