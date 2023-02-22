/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_valid_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakebli <nakebli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 10:52:36 by nakebli           #+#    #+#             */
/*   Updated: 2023/02/21 12:53:36 by nakebli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "../solong_bonus.h"

void	check_flood_fill(t_data *data)
{
	char	**map;

	map = dup_2d_arr(data->map, data->height);
	flood_fill_exit(map, data->player_pos.x,
		data->player_pos.y, data->height);
	if (!map)
		befor_exit("\x1B[31mERROR : Alloction problem");
	if (!count_e_c(map, data->height, 'E'))
	{
		free_2d_arr(map);
		befor_exit("\x1B[31mERROR : missing path to the Exit");
	}
	free_2d_arr(map);
	map = dup_2d_arr(data->map, data->height);
	flood_fill_collect(map, data->player_pos.x,
		data->player_pos.y, data->height);
	if (!map)
		befor_exit("\x1B[31mERROR : Alloction problem");
	if (!count_e_c(map, data->height, 'C'))
	{
		free_2d_arr(map);
		befor_exit("\x1B[31mERROR : missing path to one or more collectables");
	}
	free_2d_arr(map);
}
